#include "IControl.h"
#include "Panel\Panel.h"
#include "Label\Label.h"
#include "Button\Button.h"
#include "TextBox\TextBox.h"
#include "ComboBox\ComboBox.h"
#include "CheckList\CheckList.h"
#include "RadioList\RadioList.h"
#include "NumericBox\NumericBox.h"
#include "EventEngine\EventEngine.h"
#include "MessageBox\MessageBox.h"

using namespace std;

int main()
{
	vector<string> options = { "Option 111111111", "Option 2222222", "Option 3", "Option 4", "Option 5" };

	Label lName(20);
	lName.SetValue("Name: ");

	Label lAddress(20);
	lAddress.SetValue("Address:");
	Label lCountry(20);
	lCountry.SetValue("Country:");
	Label lSex(20);
	lSex.SetValue("Sex:");
	Label lInterests(20);
	lInterests.SetValue("Interests:");
	Label lAge(20);
	lAge.SetValue("Age:");
	
	
	TextBox tName(20);
	tName.SetValue("Sherlock Holmes");
	tName.SetBorder(BorderType::Single);

	TextBox tAddress(25);
	tAddress.SetValue("221B Baker Street, London");
	tAddress.SetBorder(BorderType::Single);
	
	ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
	cCountry.SetSelectedIndex(1);
	cCountry.SetBorder(BorderType::Single);
	
	RadioList rSex(2, 15, { "Male", "Female" });
	rSex.SetBorder(BorderType::Single);
	
	CheckList clInterests(3, 15, { "Sports", "Books", "Movies" });
	clInterests.SelectIndex(1);
	clInterests.SetBorder(BorderType::Single);
	
	NumericBox nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.SetBorder(BorderType::Single);
	
	Button bSubmit(10);
	bSubmit.SetValue("Submit");
	bSubmit.SetBorder(BorderType::Double);

	
	
	Panel main;
	main.addControl(lName, 1, 2);
	main.addControl(lAddress, 1, 5);
	main.addControl(lCountry, 1, 8);
	main.addControl(lSex, 1, 11);
	main.addControl(lInterests, 1, 15);
	main.addControl(lAge, 1, 20);
	main.addControl(tName, 25, 2);
	main.addControl(tAddress, 25, 5);
	main.addControl(cCountry, 25, 8);
	main.addControl(rSex, 25, 11);
	main.addControl(clInterests, 25, 15);
	main.addControl(nAge, 25, 20);


	main.addControl(bSubmit, 1, 22);
	IControl::setFocus(tName);
	EventEngine engine;
	engine.run(main);
	return 0;
	


}