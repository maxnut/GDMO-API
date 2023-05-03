#include "features.h"

bool test = true;

void features::ImGuiTest()
{
	GDMO::ImBegin("Test Window");
	if (GDMO::ImButton("Test"))
	{
		GDMO::writeOutput("Hello!");
	}
	GDMO::ImCheckbox("Test Checkbox", &test);
	GDMO::ImEnd();
}

void features::Save()
{
	GDMO::SaveBool("APITEST", "test", test);
}

void features::Load()
{
	GDMO::ReadBool("APITEST", "test", &test);
}