#include <iostream>
#include "menu.h"
#include "submenu.h"
#include "menuitem.h"
#include "bookbase.h"




void bookBase::run() {
	subMenu mainmenu("Главное меню", false);
	subMenu adminmenu("admin", true);
	subMenu usermenu("user", false);
	subMenu sort("sort", false);
	subMenu find("find", false);

	adminmenu.add_item(&find);
	usermenu.add_item(&sort);

	mainmenu.add_item(&adminmenu);
	mainmenu.add_item(&usermenu);

	mainmenu.run();


}

bookBase::bookBase() {}
bookBase::~bookBase() {}
