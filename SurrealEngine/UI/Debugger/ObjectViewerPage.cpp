
#include "Precomp.h"
#include "ObjectViewerPage.h"
#include "UI/Controls/ListView/ListView.h"
#include "UObject/UClass.h"
#include "UObject/UProperty.h"

ObjectViewerPage::ObjectViewerPage(View* parent) : VBoxView(parent)
{
	listview = new ListView(this);
	listview->setExpanding();

	listview->addColumn("Name", 200);
	listview->addColumn("Value", 200, true);

	addClass("objectviewerpage");
	listview->addClass("objectviewerpage-listview");
}

void ObjectViewerPage::setObject(UObject* obj)
{
	listview->clearList();

	auto props = obj->PropertyData.Class->Properties;
	std::stable_sort(props.begin(), props.end(), [](UProperty* a, UProperty* b) { return a->Name < b->Name; });

	for (UProperty* prop : props)
	{
		void* ptr = obj->PropertyData.Ptr(prop);

		auto item = (TextListViewItem*)listview->rootItem()->add(std::make_unique<TextListViewItem>());
		item->setText(0, prop->Name.ToString());
		item->setText(1, prop->PrintValue(ptr));
	}
}
