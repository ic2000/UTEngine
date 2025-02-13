cmake_minimum_required(VERSION 3.15)

add_subdirectory( Thirdparty/ZVulkan )

project(SurrealEngine)

set(UTENGINE_SOURCES
	SurrealEngine/Precomp.cpp
	SurrealEngine/Render/RenderSubsystem.cpp
	SurrealEngine/Render/RenderSubsystem.h
	SurrealEngine/Render/RenderCanvas.cpp
	SurrealEngine/Render/RenderMesh.cpp
	SurrealEngine/Render/RenderBrush.cpp
	SurrealEngine/Render/RenderSprite.cpp
	SurrealEngine/Render/RenderCorona.cpp
	SurrealEngine/Render/RenderDecal.cpp
	SurrealEngine/Render/RenderScene.cpp
	SurrealEngine/Render/RenderLight.cpp
	SurrealEngine/Render/RenderFog.cpp
	SurrealEngine/Render/Lightmap/LightEffect.cpp
	SurrealEngine/Render/Lightmap/LightEffect.h
	SurrealEngine/Render/Lightmap/LightmapBuilder.cpp
	SurrealEngine/Render/Lightmap/LightmapBuilder.h
	SurrealEngine/Render/Lightmap/Shadowmap.cpp
	SurrealEngine/Render/Lightmap/Shadowmap.h
	SurrealEngine/Render/Lightmap/FogmapBuilder.cpp
	SurrealEngine/Render/Lightmap/FogmapBuilder.h
	SurrealEngine/Engine.cpp
	SurrealEngine/Main.cpp
	SurrealEngine/File.cpp
	SurrealEngine/UTF16.cpp
	SurrealEngine/VM/NativeFuncExtractor.h
	SurrealEngine/VM/NativeFunc.cpp
	SurrealEngine/VM/NativeFuncExtractor.cpp
	SurrealEngine/VM/Frame.cpp
	SurrealEngine/VM/ExpressionValue.h
	SurrealEngine/VM/ScriptCall.cpp
	SurrealEngine/VM/Bytecode.cpp
	SurrealEngine/VM/Bytecode.h
	SurrealEngine/VM/ScriptCall.h
	SurrealEngine/VM/ExpressionEvaluator.h
	SurrealEngine/VM/Frame.h
	SurrealEngine/VM/NativeFunc.h
	SurrealEngine/VM/Expression.h
	SurrealEngine/VM/ExpressionEvaluator.cpp
	SurrealEngine/VM/ExpressionVisitor.h
	SurrealEngine/VM/Iterator.cpp
	SurrealEngine/VM/Iterator.h
	SurrealEngine/Engine.h
	SurrealEngine/Audio/AudioPlayer.cpp
	SurrealEngine/Audio/AudioPlayer.h
	SurrealEngine/Audio/AudioSource.h
	SurrealEngine/Audio/AudioSource.cpp
	SurrealEngine/Audio/AudioMixer.cpp
	SurrealEngine/Audio/AudioMixer.h
	SurrealEngine/Audio/AudioSubsystem.cpp
	SurrealEngine/Audio/AudioSubsystem.h
	SurrealEngine/Native/NStatLog.h
	SurrealEngine/Native/NZoneInfo.cpp
	SurrealEngine/Native/NNavigationPoint.cpp
	SurrealEngine/Native/NLevelInfo.h
	SurrealEngine/Native/NScriptedTexture.cpp
	SurrealEngine/Native/NPawn.cpp
	SurrealEngine/Native/NGameInfo.h
	SurrealEngine/Native/NGameInfo.cpp
	SurrealEngine/Native/NStatLogFile.h
	SurrealEngine/Native/NWarpZoneInfo.cpp
	SurrealEngine/Native/NScriptedTexture.h
	SurrealEngine/Native/NObject.h
	SurrealEngine/Native/NActor.cpp
	SurrealEngine/Native/NPlayerPawn.h
	SurrealEngine/Native/NStatLog.cpp
	SurrealEngine/Native/NStatLogFile.cpp
	SurrealEngine/Native/NPawn.h
	SurrealEngine/Native/NConsole.h
	SurrealEngine/Native/NWarpZoneInfo.h
	SurrealEngine/Native/NLevelInfo.cpp
	SurrealEngine/Native/NCanvas.h
	SurrealEngine/Native/NCommandlet.h
	SurrealEngine/Native/NConsole.cpp
	SurrealEngine/Native/NNavigationPoint.h
	SurrealEngine/Native/NCanvas.cpp
	SurrealEngine/Native/NPlayerPawn.cpp
	SurrealEngine/Native/NCommandlet.cpp
	SurrealEngine/Native/NDecal.cpp
	SurrealEngine/Native/NActor.h
	SurrealEngine/Native/NObject.cpp
	SurrealEngine/Native/NDecal.h
	SurrealEngine/Native/NZoneInfo.h
	SurrealEngine/Native/NInternetLink.cpp
	SurrealEngine/Native/NInternetLink.h
	SurrealEngine/Native/NTcpLink.cpp
	SurrealEngine/Native/NTcpLink.h
	SurrealEngine/Native/NUdpLink.cpp
	SurrealEngine/Native/NUdpLink.h
	SurrealEngine/Native/NDebugInfo.cpp
	SurrealEngine/Native/NDebugInfo.h
	SurrealEngine/Native/NDeusExPlayer.cpp
	SurrealEngine/Native/NDeusExPlayer.h
	SurrealEngine/Native/NScriptedPawn.cpp
	SurrealEngine/Native/NScriptedPawn.h
	SurrealEngine/Native/NDeusExDecoration.cpp
	SurrealEngine/Native/NDeusExDecoration.h
	SurrealEngine/Native/NDumpLocation.cpp
	SurrealEngine/Native/NDumpLocation.h
	SurrealEngine/Native/NDeusExSaveInfo.cpp
	SurrealEngine/Native/NDeusExSaveInfo.h
	SurrealEngine/Native/NGameDirectory.cpp
	SurrealEngine/Native/NGameDirectory.h
	SurrealEngine/Native/NParticleIterator.cpp
	SurrealEngine/Native/NParticleIterator.h
	SurrealEngine/Native/NPlayerPawnExt.cpp
	SurrealEngine/Native/NPlayerPawnExt.h
	SurrealEngine/RenderDevice/RenderDevice.cpp
	SurrealEngine/RenderDevice/RenderDevice.h
	SurrealEngine/RenderDevice/Vulkan/BufferManager.cpp
	SurrealEngine/RenderDevice/Vulkan/BufferManager.h
	SurrealEngine/RenderDevice/Vulkan/CachedTexture.h
	SurrealEngine/RenderDevice/Vulkan/CommandBufferManager.cpp
	SurrealEngine/RenderDevice/Vulkan/CommandBufferManager.h
	SurrealEngine/RenderDevice/Vulkan/DescriptorSetManager.cpp
	SurrealEngine/RenderDevice/Vulkan/DescriptorSetManager.h
	SurrealEngine/RenderDevice/Vulkan/FileResource.cpp
	SurrealEngine/RenderDevice/Vulkan/FileResource.h
	SurrealEngine/RenderDevice/Vulkan/FramebufferManager.cpp
	SurrealEngine/RenderDevice/Vulkan/FramebufferManager.h
	SurrealEngine/RenderDevice/Vulkan/RenderPassManager.cpp
	SurrealEngine/RenderDevice/Vulkan/RenderPassManager.h
	SurrealEngine/RenderDevice/Vulkan/SamplerManager.cpp
	SurrealEngine/RenderDevice/Vulkan/SamplerManager.h
	SurrealEngine/RenderDevice/Vulkan/SceneTextures.cpp
	SurrealEngine/RenderDevice/Vulkan/SceneTextures.h
	SurrealEngine/RenderDevice/Vulkan/ShaderManager.cpp
	SurrealEngine/RenderDevice/Vulkan/ShaderManager.h
	SurrealEngine/RenderDevice/Vulkan/TextureManager.cpp
	SurrealEngine/RenderDevice/Vulkan/TextureManager.h
	SurrealEngine/RenderDevice/Vulkan/TextureUploader.cpp
	SurrealEngine/RenderDevice/Vulkan/TextureUploader.h
	SurrealEngine/RenderDevice/Vulkan/UploadManager.cpp
	SurrealEngine/RenderDevice/Vulkan/UploadManager.h
	SurrealEngine/RenderDevice/Vulkan/VulkanRenderDevice.cpp
	SurrealEngine/RenderDevice/Vulkan/VulkanRenderDevice.h
	SurrealEngine/Package/ObjectFlags.h
	SurrealEngine/Package/Package.h
	SurrealEngine/Package/ObjectStream.h
	SurrealEngine/Package/PackageManager.cpp
	SurrealEngine/Package/PackageFlags.h
	SurrealEngine/Package/Package.cpp
	SurrealEngine/Package/PackageManager.h
	SurrealEngine/Package/PackageStream.cpp
	SurrealEngine/Package/IniFile.h
	SurrealEngine/Package/PackageStream.h
	SurrealEngine/Package/IniFile.cpp
	SurrealEngine/Package/NameString.h
	SurrealEngine/Math/FrustumPlanes.h
	SurrealEngine/Math/quaternion.h
	SurrealEngine/Math/FrustumPlanes.cpp
	SurrealEngine/Math/halffloat.cpp
	SurrealEngine/Math/hsb.cpp
	SurrealEngine/Math/halffloat.h
	SurrealEngine/Math/mat.h
	SurrealEngine/Math/vec.h
	SurrealEngine/Math/rotator.h
	SurrealEngine/Math/mat.cpp
	SurrealEngine/Math/bbox.h
	SurrealEngine/Math/hsb.h
	SurrealEngine/GC/GC.cpp
	SurrealEngine/GC/GC.h
	SurrealEngine/UObject/ULevel.cpp
	SurrealEngine/UObject/PropertyOffsets.cpp
	SurrealEngine/UObject/UMusic.cpp
	SurrealEngine/UObject/UClient.cpp
	SurrealEngine/UObject/UActor.cpp
	SurrealEngine/UObject/ULevel.h
	SurrealEngine/UObject/UClass.cpp
	SurrealEngine/UObject/UTexture.cpp
	SurrealEngine/UObject/UFont.cpp
	SurrealEngine/UObject/UObject.h
	SurrealEngine/UObject/NativeObjExtractor.cpp
	SurrealEngine/UObject/UProperty.h
	SurrealEngine/UObject/UMusic.h
	SurrealEngine/UObject/UTexture.h
	SurrealEngine/UObject/USound.h
	SurrealEngine/UObject/UClient.h
	SurrealEngine/UObject/NativeObjExtractor.h
	SurrealEngine/UObject/UMesh.cpp
	SurrealEngine/UObject/UMesh.h
	SurrealEngine/UObject/UProperty.cpp
	SurrealEngine/UObject/UActor.h
	SurrealEngine/UObject/USound.cpp
	SurrealEngine/UObject/UFont.h
	SurrealEngine/UObject/UTextBuffer.cpp
	SurrealEngine/UObject/UClass.h
	SurrealEngine/UObject/UObject.cpp
	SurrealEngine/UObject/UTextBuffer.h
	SurrealEngine/UObject/UInternetLink.cpp
	SurrealEngine/UObject/UInternetLink.h
	SurrealEngine/UObject/PropertyOffsets.h
	SurrealEngine/Collision/CollisionHash.cpp
	SurrealEngine/Collision/CollisionHash.h
	SurrealEngine/Collision/TraceHit.h
	SurrealEngine/Collision/TraceRayLevel.cpp
	SurrealEngine/Collision/TraceRayLevel.h
	SurrealEngine/Collision/TraceRayModel.cpp
	SurrealEngine/Collision/TraceRayModel.h
	SurrealEngine/Collision/TraceCylinderLevel.cpp
	SurrealEngine/Collision/TraceCylinderLevel.h
	SurrealEngine/Collision/TraceSphereModel.cpp
	SurrealEngine/Collision/TraceSphereModel.h
	SurrealEngine/Collision/TraceAABBModel.cpp
	SurrealEngine/Collision/TraceAABBModel.h
	SurrealEngine/UI/Controls/LineEdit/LineEdit.cpp
	SurrealEngine/UI/Controls/LineEdit/LineEdit.h
	SurrealEngine/UI/Controls/TextLabel/TextLabel.cpp
	SurrealEngine/UI/Controls/TextLabel/TextLabel.h
	SurrealEngine/UI/Controls/ImageBox/ImageBox.cpp
	SurrealEngine/UI/Controls/ImageBox/ImageBox.h
	SurrealEngine/UI/Controls/Button/Button.h
	SurrealEngine/UI/Controls/Button/Button.cpp
	SurrealEngine/UI/Controls/SvgBox/SvgBox.h
	SurrealEngine/UI/Controls/SvgBox/SvgBox.cpp
	SurrealEngine/UI/Controls/ListView/ListViewItemView.cpp
	SurrealEngine/UI/Controls/ListView/ListViewItemView.h
	SurrealEngine/UI/Controls/ListView/ListViewItem.h
	SurrealEngine/UI/Controls/ListView/ListView.cpp
	SurrealEngine/UI/Controls/ListView/ListView.h
	SurrealEngine/UI/Controls/ListView/ListViewItem.cpp
	SurrealEngine/UI/Controls/TabControl/TabControl.h
	SurrealEngine/UI/Controls/TabControl/TabControl.cpp
	SurrealEngine/UI/Controls/BorderLayoutView/BorderLayoutView.cpp
	SurrealEngine/UI/Controls/BorderLayoutView/BorderLayoutView.h
	SurrealEngine/UI/Core/UTF8Reader.cpp
	SurrealEngine/UI/Core/JsonValue.cpp
	SurrealEngine/UI/Core/View.cpp
	SurrealEngine/UI/Core/JsonValue.h
	SurrealEngine/UI/Core/Element/Element.h
	SurrealEngine/UI/Core/Element/Canvas.cpp
	SurrealEngine/UI/Core/Element/WindowFrame.cpp
	SurrealEngine/UI/Core/Element/Canvas.h
	SurrealEngine/UI/Core/Element/ElementGeometry.cpp
	SurrealEngine/UI/Core/Element/Rect.h
	SurrealEngine/UI/Core/Element/Event.cpp
	SurrealEngine/UI/Core/Element/Element.cpp
	SurrealEngine/UI/Core/Element/WindowFrame.h
	SurrealEngine/UI/Core/Element/ComputedBorder.h
	SurrealEngine/UI/Core/Element/ElementGeometry.h
	SurrealEngine/UI/Core/Element/Event.h
	SurrealEngine/UI/Core/Element/ElementStyle.cpp
	SurrealEngine/UI/Core/Element/ElementStyle.h
	SurrealEngine/UI/Core/Element/Colorf.h
	SurrealEngine/UI/Core/View.h
	SurrealEngine/UI/Core/UTF8Reader.h
	SurrealEngine/UI/Dialog/MessageBox.h
	SurrealEngine/UI/Dialog/AppMenu.cpp
	SurrealEngine/UI/Dialog/WebsiteHeader.cpp
	SurrealEngine/UI/Dialog/DialogButtonbar.cpp
	SurrealEngine/UI/Dialog/DockHeaderButton.h
	SurrealEngine/UI/Dialog/WindowHeader.cpp
	SurrealEngine/UI/Dialog/DialogButtonbar.h
	SurrealEngine/UI/Dialog/DialogButton.cpp
	SurrealEngine/UI/Dialog/DialogButton.h
	SurrealEngine/UI/Dialog/AppMenu.h
	SurrealEngine/UI/Dialog/DockHeaderButton.cpp
	SurrealEngine/UI/Dialog/DialogHeader.h
	SurrealEngine/UI/Dialog/Dialog.h
	SurrealEngine/UI/Dialog/WindowHeader.h
	SurrealEngine/UI/Dialog/MessageBox.cpp
	SurrealEngine/UI/Dialog/WebsiteHeader.h
	SurrealEngine/UI/Dialog/Dialog.cpp
	SurrealEngine/UI/Dialog/DialogHeader.cpp
	SurrealEngine/UI/Dialog/DockHeader.cpp
	SurrealEngine/UI/Dialog/DialogHeaderButton.cpp
	SurrealEngine/UI/Dialog/DialogHeaderButton.h
	SurrealEngine/UI/Dialog/DockHeader.h
	SurrealEngine/UI/Debugger/DebuggerWindow.h
	SurrealEngine/UI/Debugger/DisassemblyPage.cpp
	SurrealEngine/UI/Debugger/LocalsPage.cpp
	SurrealEngine/UI/Debugger/ObjectViewerPage.cpp
	SurrealEngine/UI/Debugger/CallstackPage.cpp
	SurrealEngine/UI/Debugger/CallstackPage.h
	SurrealEngine/UI/Debugger/DebuggerWindow.cpp
	SurrealEngine/UI/Debugger/ObjectViewerPage.h
	SurrealEngine/UI/Debugger/ExpressionItemBuilder.cpp
	SurrealEngine/UI/Debugger/DisassemblyPage.h
	SurrealEngine/UI/Debugger/ExpressionItemBuilder.h
	SurrealEngine/UI/Debugger/LocalsPage.h
	SurrealEngine/UI/Debugger/LogPage.cpp
	SurrealEngine/UI/Debugger/LogPage.h
	SurrealEngine/UI/MainWindow/Menubar.h
	SurrealEngine/UI/MainWindow/Statusbar.h
	SurrealEngine/UI/MainWindow/VToolbar.cpp
	SurrealEngine/UI/MainWindow/Statusbar.cpp
	SurrealEngine/UI/MainWindow/MenubarModal.h
	SurrealEngine/UI/MainWindow/Menu.h
	SurrealEngine/UI/MainWindow/Toolbar.cpp
	SurrealEngine/UI/MainWindow/Menu.cpp
	SurrealEngine/UI/MainWindow/Menubar.cpp
	SurrealEngine/UI/MainWindow/Toolbar.h
	SurrealEngine/UI/MainWindow/VToolbar.h
	SurrealEngine/UI/MainWindow/MenubarModal.cpp
	SurrealEngine/Window/Window.cpp
	SurrealEngine/Window/Window.h
	SurrealEngine/File.h
	SurrealEngine/Precomp.h
	SurrealEngine/GameFolder.cpp
	SurrealEngine/GameFolder.h
	SurrealEngine/CommandLine.cpp
	SurrealEngine/CommandLine.h
	SurrealEngine/Window/SDL3/SDL3window.cpp
	SurrealEngine/Window/SDL3/SDL3window.h
)

set(UTENGINE_WIN32_SOURCES
	SurrealEngine/Window/Win32/Win32Window.cpp
	SurrealEngine/Window/Win32/Win32Window.h
	SurrealEngine/SurrealEngine.natvis
)

set(UTENGINE_UNIX_SOURCES
	SurrealEngine/Window/X11/X11Window.cpp
	SurrealEngine/Window/X11/X11Window.h
	SurrealEngine/Window/X11/X11Atoms.cpp
	SurrealEngine/Window/X11/X11Atoms.h
)

set(THIRDPARTY_SOURCES
	Thirdparty/dr_wav.h
	Thirdparty/minimp3_ex.h
	Thirdparty/minimp3.h
	Thirdparty/dumb/src/core/duhtag.c
	Thirdparty/dumb/src/core/rawsig.c
	Thirdparty/dumb/src/core/atexit.c
	Thirdparty/dumb/src/core/dumbfile.c
	Thirdparty/dumb/src/core/loadduh.c
	Thirdparty/dumb/src/core/unload.c
	Thirdparty/dumb/src/core/makeduh.c
	Thirdparty/dumb/src/core/readduh.c
	Thirdparty/dumb/src/core/rendsig.c
	Thirdparty/dumb/src/core/rendduh.c
	Thirdparty/dumb/src/core/register.c
	Thirdparty/dumb/src/core/duhlen.c
	Thirdparty/dumb/src/helpers/lpc.c
	Thirdparty/dumb/src/helpers/clickrem.c
	Thirdparty/dumb/src/helpers/memfile.c
	Thirdparty/dumb/src/helpers/silence.c
	Thirdparty/dumb/src/helpers/tarray.c
	Thirdparty/dumb/src/helpers/sampbuf.c
	Thirdparty/dumb/src/helpers/riff.c
	Thirdparty/dumb/src/helpers/barray.c
	Thirdparty/dumb/src/helpers/resample.c
	Thirdparty/dumb/src/helpers/resampler.c
	Thirdparty/dumb/src/helpers/stdfile.c
	Thirdparty/dumb/src/it/readoldpsm.c
	Thirdparty/dumb/src/it/readdsmf.c
	Thirdparty/dumb/src/it/loadokt.c
	Thirdparty/dumb/src/it/loadamf.c
	Thirdparty/dumb/src/it/itorder.c
	Thirdparty/dumb/src/it/loadxm2.c
	Thirdparty/dumb/src/it/xmeffect.c
	Thirdparty/dumb/src/it/loadxm.c
	Thirdparty/dumb/src/it/readmod.c
	Thirdparty/dumb/src/it/readxm2.c
	Thirdparty/dumb/src/it/reads3m2.c
	Thirdparty/dumb/src/it/loadokt2.c
	Thirdparty/dumb/src/it/read669.c
	Thirdparty/dumb/src/it/readokt2.c
	Thirdparty/dumb/src/it/loadany.c
	Thirdparty/dumb/src/it/ptmeffect.c
	Thirdparty/dumb/src/it/readstm2.c
	Thirdparty/dumb/src/it/loadoldpsm2.c
	Thirdparty/dumb/src/it/read6692.c
	Thirdparty/dumb/src/it/loads3m.c
	Thirdparty/dumb/src/it/loadmod.c
	Thirdparty/dumb/src/it/readriff.c
	Thirdparty/dumb/src/it/readam.c
	Thirdparty/dumb/src/it/loadmtm.c
	Thirdparty/dumb/src/it/itunload.c
	Thirdparty/dumb/src/it/loadpsm.c
	Thirdparty/dumb/src/it/itrender.c
	Thirdparty/dumb/src/it/readxm.c
	Thirdparty/dumb/src/it/readstm.c
	Thirdparty/dumb/src/it/itmisc.c
	Thirdparty/dumb/src/it/itload.c
	Thirdparty/dumb/src/it/loadasy2.c
	Thirdparty/dumb/src/it/loadriff.c
	Thirdparty/dumb/src/it/load669.c
	Thirdparty/dumb/src/it/loads3m2.c
	Thirdparty/dumb/src/it/loadpsm2.c
	Thirdparty/dumb/src/it/readany2.c
	Thirdparty/dumb/src/it/readamf.c
	Thirdparty/dumb/src/it/itload2.c
	Thirdparty/dumb/src/it/itread2.c
	Thirdparty/dumb/src/it/loadriff2.c
	Thirdparty/dumb/src/it/loadasy.c
	Thirdparty/dumb/src/it/loadany2.c
	Thirdparty/dumb/src/it/readany.c
	Thirdparty/dumb/src/it/readpsm.c
	Thirdparty/dumb/src/it/readamf2.c
	Thirdparty/dumb/src/it/loadamf2.c
	Thirdparty/dumb/src/it/loadptm.c
	Thirdparty/dumb/src/it/load6692.c
	Thirdparty/dumb/src/it/readptm.c
	Thirdparty/dumb/src/it/loadoldpsm.c
	Thirdparty/dumb/src/it/readmtm.c
	Thirdparty/dumb/src/it/loadmtm2.c
	Thirdparty/dumb/src/it/loadstm.c
	Thirdparty/dumb/src/it/readasy.c
	Thirdparty/dumb/src/it/loadptm2.c
	Thirdparty/dumb/src/it/reads3m.c
	Thirdparty/dumb/src/it/itread.c
	Thirdparty/dumb/src/it/readmod2.c
	Thirdparty/dumb/src/it/readokt.c
	Thirdparty/dumb/src/it/loadmod2.c
	Thirdparty/dumb/src/it/loadstm2.c
	Thirdparty/dumb/include/aldumb.h
	Thirdparty/dumb/include/internal/stack_alloc.h
	Thirdparty/dumb/include/internal/dumbfile.h
	Thirdparty/dumb/include/internal/resampler.h
	Thirdparty/dumb/include/internal/aldumb.h
	Thirdparty/dumb/include/internal/dumb.h
	Thirdparty/dumb/include/internal/barray.h
	Thirdparty/dumb/include/internal/tarray.h
	Thirdparty/dumb/include/internal/lpc.h
	Thirdparty/dumb/include/internal/it.h
	Thirdparty/dumb/include/internal/riff.h
	Thirdparty/dumb/include/dumb.h
	Thirdparty/resample/CDSPSincFilterGen.h
	Thirdparty/resample/CDSPHBDownsampler.h
	Thirdparty/resample/CDSPResampler.h
	Thirdparty/resample/CDSPRealFFT.h
	Thirdparty/resample/CDSPFIRFilter.h
	Thirdparty/resample/pffft.cpp
	Thirdparty/resample/r8butil.h
	Thirdparty/resample/CDSPHBUpsampler.h
	Thirdparty/resample/CDSPProcessor.h
	Thirdparty/resample/r8bbase.cpp
	Thirdparty/resample/pffft.h
	Thirdparty/resample/CDSPFracInterpolator.h
	Thirdparty/resample/CDSPBlockConvolver.h
	Thirdparty/resample/fft4g.h
	Thirdparty/resample/r8bconf.h
	Thirdparty/resample/r8bbase.h
	Thirdparty/dr_flac.h
	Thirdparty/stb_vorbis.h
)

set(THIRDPARTY_WIN32_SOURCES
)

set(THIRDPARTY_UNIX_SOURCES
)

set(UTENGINE_LIBS
	zvulkan
)

source_group("SurrealEngine" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/.+")
source_group("SurrealEngine\\Audio" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/Audio/.+")
source_group("SurrealEngine\\Math" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/Math/.+")
source_group("SurrealEngine\\Native" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/Native/.+")
source_group("SurrealEngine\\Package" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/Package/.+")
source_group("SurrealEngine\\RenderDevice" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/RenderDevice/.+")
source_group("SurrealEngine\\RenderDevice/Vulkan" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/RenderDevice/Vulkan/.+")
source_group("SurrealEngine\\Render" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/Render/.+")
source_group("SurrealEngine\\Render\\Lightmap" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/Render/Lightmap/.+")
source_group("SurrealEngine\\UI" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/.+")
source_group("SurrealEngine\\UI\\Controls" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Controls/.+")
source_group("SurrealEngine\\UI\\Controls\\BorderLayoutView" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Controls/BorderLayoutView/.+")
source_group("SurrealEngine\\UI\\Controls\\Button" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Controls/Button/.+")
source_group("SurrealEngine\\UI\\Controls\\ImageBox" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Controls/ImageBox/.+")
source_group("SurrealEngine\\UI\\Controls\\LineEdit" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Controls/LineEdit/.+")
source_group("SurrealEngine\\UI\\Controls\\ListView" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Controls/ListView/.+")
source_group("SurrealEngine\\UI\\Controls\\SvgBox" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Controls/SvgBox/.+")
source_group("SurrealEngine\\UI\\Controls\\TabControl" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Controls/TabControl/.+")
source_group("SurrealEngine\\UI\\Controls\\TextLabel" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Controls/TextLabel/.+")
source_group("SurrealEngine\\UI\\Core" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Core/.+")
source_group("SurrealEngine\\UI\\Core\\Element" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Core/Element/.+")
source_group("SurrealEngine\\UI\\Debugger" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Debugger/.+")
source_group("SurrealEngine\\UI\\Dialog" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/Dialog/.+")
source_group("SurrealEngine\\UI\\MainWindow" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UI/MainWindow/.+")
source_group("SurrealEngine\\UObject" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/UObject/.+")
source_group("SurrealEngine\\Collision" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/Collision/.+")
source_group("SurrealEngine\\GC" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/GC/.+")
source_group("SurrealEngine\\VM" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/VM/.+")
source_group("SurrealEngine\\Window" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/Window/.+")
source_group("SurrealEngine\\Window\\Win32" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/Window/Win32/.+")
source_group("SurrealEngine\\Window\\X11" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/SurrealEngine/Window/X11/.+")
source_group("Thirdparty" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/.+")
source_group("Thirdparty\\resample" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/resample/.+")
source_group("Thirdparty\\dumb" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/dumb/.+")
source_group("Thirdparty\\dumb\\src" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/dumb/src/.+")
source_group("Thirdparty\\dumb\\src\\core" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/dumb/src/core.+")
source_group("Thirdparty\\dumb\\src\\helpers" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/dumb/src/helpers/.+")
source_group("Thirdparty\\dumb\\src\\it" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/dumb/src/it/.+")
source_group("Thirdparty\\dumb\\include" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/dumb/include/.+")
source_group("Thirdparty\\dumb\\include\\internal" REGULAR_EXPRESSION "${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/dumb/include/internal/.+")

set(SDL_STATIC TRUE)
add_subdirectory("Thirdparty/SDL3")
set(UTENGINE_LIBS ${UTENGINE_LIBS} SDL3::SDL3-static)

include_directories(SurrealEngine Thirdparty Thirdparty/ZVulkan/include Thirdparty/dumb/include ${SDL3_SOURCE_DIR}/include)

if(WIN32)
	set(UTENGINE_SOURCES ${UTENGINE_SOURCES} ${UTENGINE_WIN32_SOURCES})
	set(THIRDPARTY_SOURCES ${THIRDPARTY_SOURCES} ${THIRDPARTY_WIN32_SOURCES})
	add_definitions(-DUNICODE -D_UNICODE)
else()
	set(UTENGINE_SOURCES ${UTENGINE_SOURCES} ${UTENGINE_UNIX_SOURCES})
	set(THIRDPARTY_SOURCES ${THIRDPARTY_SOURCES} ${THIRDPARTY_UNIX_SOURCES})
	set(UTENGINE_LIBS ${UTENGINE_LIBS} ${CMAKE_DL_LIBS} -lX11 -ldl -lasound)
	add_definitions(-DUNIX -D_UNIX)
	add_link_options(-pthread)
endif()

if(MSVC)
	# Use all cores for compilation
	set(CMAKE_CXX_FLAGS "/MP ${CMAKE_CXX_FLAGS}")

	# Add precompiled headers
	# set(PCH_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/Precomp.pch")
	# set_source_files_properties(${UTENGINE_SOURCES} PROPERTIES COMPILE_FLAGS "/Yu\"Precomp.h\" /Fp\"${PCH_OUTPUT}\"" OBJECT_DEPENDS "${PCH_OUTPUT}")
	# set_source_files_properties("SurrealEngine/Precomp.cpp" PROPERTIES COMPILE_FLAGS "/Yc\"Precomp.h\" /Fp\"${PCH_OUTPUT}\"" OBJECT_OUTPUTS "${PCH_OUTPUT}")

	# Ignore warnings in third party code
	set_source_files_properties(${THIRDPARTY_SOURCES} PROPERTIES COMPILE_FLAGS "/wd4244 /wd4267 /wd4005 /wd4018 -D_CRT_SECURE_NO_WARNINGS")
endif()

add_executable(SurrealEngine WIN32 MACOSX_BUNDLE ${UTENGINE_SOURCES} ${THIRDPARTY_SOURCES})
target_link_libraries(SurrealEngine ${UTENGINE_LIBS})
set_target_properties(SurrealEngine PROPERTIES CXX_STANDARD 17)

if (CMAKE_GENERATOR STREQUAL "Ninja")
	add_custom_command(TARGET SurrealEngine
		POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E env "PATH=$ENV{PATH}" ninja -C ${CMAKE_BINARY_DIR} -t compdb > ${CMAKE_SOURCE_DIR}/compile_commands.json
	)
endif()
