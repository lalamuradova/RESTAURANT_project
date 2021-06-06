#include"Display.h"

using namespace std;
using namespace Display;


void main() {
	

		Restaurant restaurant("Eleven restaurant", "Rashid Behbudov str. 1 (Park Inn Hotel, 11th floor)", "Baku", 0);


		Admin admin1("lala", "lala1234");
		Admin admin3("admin", "admin123");
		Admin admin2("admin", "adminadmin");

		Admin* admins = new Admin[3]{ admin1,admin2,admin3 };


		Stock* i1 = new Stock("Tomato", 5, 1, 17);
		Stock* i2 = new Stock("Mushroom", 13, 2, 14);
		Stock* i3 = new Stock("Flour", 7, 1.5, 120);
		Stock* i4 = new Stock("Meat", 10, 15, 166);
		Stock* i5 = new Stock("Walnuts", 20, 5, 200);
		Stock* i6 = new Stock("Cheese", 9, 3.5, 22);
		Stock* i7 = new Stock("Chicken", 10, 10, 100);
		Stock* i8 = new Stock("Potato", 20, 4, 45);
		Stock* i9 = new Stock("Oil", 12, 3.5, 58);
		Stock* i10 = new Stock("Olive", 20, 6.5, 32);
		Stock* i11 = new Stock("Pepper", 25, 2.2, 20);

		Stock** ing = new Stock * [3]{ i3,i7,i9 };
		Stock** ing1 = new Stock * [2]{ i3,i4 };
		Stock** ing2 = new Stock * [2]{ i7,i8 };
		Stock** ing3 = new Stock * [4]{ i3,i4,i9,i11 };


		Menu* m1 = new Menu("Margherita Pizza", 3, ing, 3);
		Menu* m2 = new Menu("Cheese Burger", 2, ing1, 4);
		Menu* m3 = new Menu("SCHNITZEL", 2, ing2, 1);
		Menu* m4 = new Menu("Lahmacun", 4, ing3, 2);



		DataBase db;
		db.AddMeal(m1);
		db.AddMeal(m2);
		db.AddMeal(m3);
		db.AddMeal(m4);

		db.AddIngredient(i1);
		db.AddIngredient(i2);
		db.AddIngredient(i3);
		db.AddIngredient(i4);
		db.AddIngredient(i5);
		db.AddIngredient(i6);
		db.AddIngredient(i7);
		db.AddIngredient(i8);
		db.AddIngredient(i9);
		db.AddIngredient(i10);
		db.AddIngredient(i11);



		DisplayChoise display(&db);
		display.Display1();

}
