#pragma once
#ifndef SDDS_SHOPPINGREC_H // replace with relevant names
#define SDDS_SHOPPINGREC_H

namespace sdds {
	const int MAX_TITLE_LENGTH = 50;

	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};


	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);
};

#endif

