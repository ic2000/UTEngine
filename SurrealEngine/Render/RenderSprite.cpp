
#include "Precomp.h"
#include "RenderSubsystem.h"
#include "RenderDevice/RenderDevice.h"
#include "Engine.h"

void RenderSubsystem::DrawSprite(FSceneNode* frame, UActor* actor)
{
	UTexture* texture = actor->Texture();
	const vec3& location = actor->Location();
	const Rotator& rotation = actor->Rotation();
	float drawscale = actor->DrawScale();
	int style = actor->Style();
	bool noSmooth = actor->bNoSmooth();

	texture = texture->GetAnimTexture();

	FTextureInfo texinfo;
	texinfo.Texture = texture;
	texinfo.CacheID = (uint64_t)(ptrdiff_t)texinfo.Texture;
	texinfo.bRealtimeChanged = texture->TextureModified;
	if (texture->TextureModified)
		texture->TextureModified = false;
	texinfo.Format = texinfo.Texture->ActualFormat;
	texinfo.Mips = texinfo.Texture->Mipmaps.data();
	texinfo.NumMips = (int)texinfo.Texture->Mipmaps.size();
	texinfo.USize = texinfo.Texture->USize();
	texinfo.VSize = texinfo.Texture->VSize();
	if (texinfo.Texture->Palette())
		texinfo.Palette = (FColor*)texinfo.Texture->Palette()->Colors.data();

	float texwidth = (float)texture->Mipmaps.front().Width;
	float texheight = (float)texture->Mipmaps.front().Height;

	uint32_t renderflags = PF_TwoSided;
	if (style == 3)
		renderflags |= PF_Translucent;
	else if (style == 4)
		renderflags |= PF_Modulated;
	if (noSmooth)
		renderflags |= PF_NoSmooth;
	if (texture->bMasked())
		renderflags |= PF_Masked;

	drawscale *= 0.5f;

	vec3 xaxis = { texwidth * drawscale, 0.0f, 0.0f };
	vec3 yaxis = { 0.0f, 0.0f, texheight * drawscale };

	quaternion viewrotation = inverse(normalize(quaternion::euler(radians(-engine->CameraRotation.PitchDegrees()), radians(-engine->CameraRotation.RollDegrees()), radians(90.0f - engine->CameraRotation.YawDegrees()), EulerOrder::yxz)));
	xaxis = viewrotation * xaxis;
	yaxis = viewrotation * yaxis;

	GouraudVertex vertices[4];
	vertices[0].Point = location - xaxis - yaxis;
	vertices[0].UV = { 0.0f, 0.0f };
	vertices[0].Light = { 1.0f };
	vertices[0].Fog = { 0.0f };
	vertices[1].Point = location + xaxis - yaxis;
	vertices[1].UV = { texwidth, 0.0f };
	vertices[1].Light = { 1.0f };
	vertices[1].Fog = { 0.0f };
	vertices[2].Point = location + xaxis + yaxis;
	vertices[2].UV = { texwidth, texheight };
	vertices[2].Light = { 1.0f };
	vertices[2].Fog = { 0.0f };
	vertices[3].Point = location - xaxis + yaxis;
	vertices[3].UV = { 0.0f, texheight };
	vertices[3].Light = { 1.0f };
	vertices[3].Fog = { 0.0f };
	Device->DrawGouraudPolygon(frame, texinfo, vertices, 4, renderflags);
}
