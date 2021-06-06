#pragma once
#include"Entities.h"
#include"AdminSection.h"
#include"ClientSection.h"
#include"Helpers.h"
#include"Exception.h"
using namespace Ex;
using namespace std;
using namespace Entities;
using namespace AdminSection;
using namespace ClientSection;
using namespace FileHelpers;

namespace Display {
	class DisplayChoise {
		DataBase* db;
		Order* order;
		Kitchen* kitchen;
	public:
		DisplayChoise(DataBase* database)
		{
			db = database;
		}

		DisplayChoise() = default;

		 void Display1() {
			int choise;
			cout << "Admin  [1]" << endl;
			cout << "Client [2]" << endl;
			cout << "Enter: ";
			cin >> choise;
			if (choise == 1) {
				FileHelper::WriteLogs("Was selected input as admin. ");
				DisplayAdminControl();
			}
			else if (choise == 2) {
				FileHelper::WriteLogs("Was selected input as client. ");
				DisplayClientLogin();
			}
			else {
				cout << "Enter 1 or 2" << endl;
				Display1();
			}
		}
		
		void DisplayAdminControl() {
			string username;
			string password;
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;

			AdminController controller(db);
			auto hasSignIn = controller.ControlAdmin(username, password);
			if (hasSignIn) {
				system("CLS");
				DisplayAdmin2();
				FileHelper::WriteLogs("Admin Loggid in . ");
			}
			else {
				system("CLS");
				throw WrongLoginException("Login is incorrect", __FILE__, __LINE__, __DATE__);
				int choise;
				cout << endl;
				cout << "Back [0]" << endl;
				cin >> choise;
				if (choise == 0) {
					system("CLS");
					DisplayAdminControl();
				}
				FileHelper::WriteLogs("Admin login entered incorrectly. ");
			}
		}
		void DisplayAdmin2() {
			system("CLS");
			int choise;
			cout << "Kitchen [1]" << endl;
			cout << "Stock   [2]" << endl;
			cout << "Enter: ";
			cin >> choise;
			if (choise == 1) {
				FileHelper::WriteLogs("Admin choose Kitchen. ");
				DisplayKitchen();
			}
			else if (choise == 2) {
				FileHelper::WriteLogs("Admin choose Kitchen. ");
				DisplayStock();
			}
			else {
				DisplayAdmin2();
			}
		}
		void DisplayStock() {
			system("CLS");
			int choise;
			cout << "Show Stock [1] " << endl;
			cout << "Add Ingredient [2] " << endl;
			cout << "Delete Ingredient [3]" << endl;
			cout << "Increase or Decrease Ingredient count [4]" << endl;
			cout << "Back [0]" <<endl;
			cout << "Choose: ";
			cin >> choise;
			system("CLS");
			DisplayStockChoise(choise);
		}
		void DisplayStockChoise(int choise) {
			if (choise == 1) {
				db->ShowStock();
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayStock();
				}
				FileHelper::WriteLogs("Admin looked Stock. ");
			}
			else if (choise == 2) {
				auto ingre = CreatIngredient();
				db->AddIngredient(ingre);
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayStock();
				}
				FileHelper::WriteLogs("Admin added ingredient. ");
			}
			else if (choise == 3) {
				system("CLS");
				db->ShowStock();
				int id;
				cout << "Enter id: ";
				cin >> id;
				db->DeleteIngredients(id);
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayStock();
				}
				FileHelper::WriteLogs("Admin deleted ingredient. ");
			}
			else if (choise == 4) {
				system("CLS");
				db->ShowStock();
				int id;
				cout << "Enter id:";
				cin >> id;
				int count;
				cout << "Enter count: ";
				cin >> count;
				db->UpdateIngredientCount(id, count);
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayAdmin2();
				}
				FileHelper::WriteLogs("Admin changed ingredient count. ");
			}
			else if (choise == 0) {
				DisplayStock();
			}
			else {
				DisplayStock();
			}
		}
		void DisplayKitchen() {
			system("CLS");
			int choise;
			cout << "Show All Order [1]" << endl;
			cout << "Order confirmation or cancellation [2]" << endl;
			cout << "All Restaurant Menu [3] " << endl;
			cout << "Add Meal [4]" << endl;
			cout << "Delete Meal [5]" << endl;
			cout << "Update Meal [6]" << endl;
			cout << "Show Stock [7]" << endl;
			cout << "Back [0]" << endl;
			cout << "Choose: ";
			cin >> choise;
			system("CLS");
			DisplayKitchenChoise(choise);
			
		}
		void DisplayKitchenChoise(int choise) {
			if (choise == 1) {
				order->ShowOrder();
				FileHelper::WriteLogs("Admin looked at the Orders. ");
				int choise;
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayKitchen();
				}
			}
			else if (choise == 2) {
				system("CLS");
				int id;
				cout << "Id: ";
				cin >> id;
				auto control = kitchen->ControlOrder(id);
				if (control) {
					cout << "The order was accepted " << endl;
					FileHelper::WriteLogs("The order was accepted. ");
				}
				else {
					cout << "The order wasn't accepted " << endl;
					FileHelper::WriteLogs("The order wasn't accepted. ");
				}
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayKitchen();
				}
			}
			else if (choise == 3) {
				db->ShowRestaurant();
				db->ShowMenu();
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayKitchen();
				}
				FileHelper::WriteLogs("Admin looked Menu. ");
			}
			else if (choise == 4) {
				auto meal = CreatMenu();
				db->AddMeal(meal);		
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayKitchen();
				}
				FileHelper::WriteLogs("Admin added meal. ");
			}
			else if (choise == 5) {
				system("CLS");
				int id;
				cout << "Id: ";
				cin >> id;
				db->DeleteMeal(id);
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayKitchen();
				}
				FileHelper::WriteLogs("Admin deleted meal. ");
			}
			else if (choise == 6) {
				system("CLS");
				int choise;
				cout << "Update meal name [1]" << endl;
				cout << "Update meal Ingredient [2]" << endl;
				cout << "Change Rating [3]" << endl;
				cout << "Back[0] ";
				cin >> choise;
				system("CLS");
				UpdateMeal(choise);
			}
			else if (choise == 7) {
				system("CLS");
				DisplayStock();
				FileHelper::WriteLogs("Admin choose Stock choise. ");
			}
			else if (choise == 0) {
				DisplayKitchen();
			}
			else {
				DisplayKitchen();
			}
		}
		void UpdateMeal(int choise) {
			if (choise == 1) {
				system("CLS");
				int id;
				cout << "ID: ";
				cin >> id;
				string name;
				cout << "Enter name: ";
				cin >> name;
				db->UpdateMealName(id, name);
				FileHelper::WriteLogs("Admin Updated meal name. ");
			}
			else if (choise == 2) {
				system("CLS");
				int id;
				cout << "ID: ";
				cin >> id;
				int rating;
				cout << "Enter rating: ";
				cin >> rating;
				db->UpdateMealRating(id, rating);
				FileHelper::WriteLogs("Admin Updated meal rating. ");
			}
			if (choise == 3) {
				system("CLS");
				int id;
				cout << "ID: ";
				cin >> id;
				auto ingredient = GetIngredient();
				int count;
				cout << "Count: ";
				cin >> count;
				db->UpdateMealIngredient(id,count,ingredient);
				FileHelper::WriteLogs("Admin Updated meals ingredient. ");
			}
			else if (choise == 0) {
				DisplayKitchen();
			}
			else {
				DisplayKitchen();
			}
		}

		Menu* CreatMenu(){
			cin.ignore();
			cin.clear();
			string name;
			int count;
			double menu_rating;

			system("CLS");
			cout << "Name: ";
			getline(cin, name);
			cout << "Count: ";
			cin >> count;
			cout << "Menu rating: ";
			cin >> menu_rating;	
			auto ingredient = GetIngredient();

			Menu* m=new Menu(name, count, ingredient, menu_rating);
			return m;
		}
		Stock** GetIngredient() {
			db->ShowStock();
			int id;
			cout << "Enter id : ";
			cin >> id;
				auto item = db->GetIngredients().GetItem(id);
				Stock** in = new Stock*(item);
				return in;
		}
		Stock* CreatIngredient() {
			cin.ignore();
			cin.clear();
			string name;
			int count;
			double price;
			int kkal;

			cout << "Name: ";
			getline(cin, name);
			cout << "Count: ";
			cin >> count;
			cout << "Price: ";
			cin >> price;
			cout << "KKal: ";
			cin >> kkal;

			Stock* ing=new Stock(name, count, price, kkal);
			return ing;
		}

		void Table() {
			cout << " ---------            ------" << endl;
			cout << "|   T1    |          |  T4   |" << endl;
			cout << " ---------            -------" << endl;
			cout << "                        ---------" << endl;
			cout << "       --------        |    T2    |" << endl;
			cout << "      |  T3    |        ----------" << endl;
			cout << "       --------" << endl;
		}
		void DisplayClientLogin() {
			system("CLS");
			Table();
			string tableNo;
			cout << "Choose table no: ";
			cin >> tableNo;
			FileHelper::WriteLogs("Client choosed table. ");
			DisplayClient();
		}
		void DisplayClient() {
			system("CLS");
			int choise;
			cout << "Show Menu [1] " << endl;
			cout << "Show Meal Details [2]" << endl;
			cout << "Order [3]" << endl;
			cout << "Search Meal[4] " << endl;
			cout << "Back [0]" << endl;
			cout << "Enter: ";
			cin >> choise;
			DisplayClientChoise(choise);
			system("CLS");
		}
		void DisplayClientChoise(int choise) {
			if (choise == 1) {
				FileHelper::WriteLogs("Client looked at the menu. ");
				db->ShowMenu();
				int choise;
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayClient();
				}
			}
			else if (choise == 2) {
				db->ShowMenu();
				int id;
				cout << "Enter ID: ";
				cin >> id;
				FileHelper::WriteLogs("Client looked at the menu. ");
				db->ShowMealDetails(id);
				int choise;
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayClient();
				}
			}
			else if (choise == 3) {
				OrderChoise();		

			}
			else if (choise == 4) {
				system("CLS");
				db->ShowMenu();
				string name;
				cout << "Enter name: ";
				cin >> name;
				FileHelper::WriteLogs("Client searched meal. ");
				db->SearchMeal(name);
				int choise;
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayClient();
				}
			}
			else if (choise == 0) {
				Display1();
			}
			else {
				system ("CLS");
				DisplayClient();
			}
		}
		void OrderChoise() {
			system("CLS");
			db->ShowMenu();
			int id; int ID; int count;
			cout << "Enter meal id for order: ";
			cin >> id;
			string ch;		
			
				cout << "Do you want add ingredient again yes/no :";
				cin >> ch;
				db->ShowStock();
				if (ch == "yes") {
					
						cout << "Enter ingredient id for order: ";
						cin >> ID;
						
						cout << "How many pieces: ";
						cin >> count;
														
				}				
				OrderOrder(id, ID, count);			
		}
		void OrderOrder(int meal_id, int ing_id,int count) {
			
			if (meal_id != 0) {
				auto meal = db->GetMeals().GetItem(meal_id);
				
				auto ingredient = db->GetIngredients().GetItem(ing_id);
				
				
				Order orderrrr(meal, ingredient, count);
				system("CLS");
				cout << "Order Completed" << endl;
				FileHelper::WriteLogs("Order completed. ");
				int choise;
				cout << endl;
				cout << "Back[0]: ";
				cin >> choise;
				if (choise == 0) {
					DisplayClient();
				}
			}

		}


	};

	

}