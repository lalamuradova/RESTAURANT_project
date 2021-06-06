#pragma once
#include<iostream>
#include<string>
#include<list>
#include<Windows.h>
#include<conio.h>
#include<iomanip>
#include"Exception.h"

using namespace std;
using namespace Ex;

namespace Entities {

	class Admin {
		string username;
		string password;
	public:
		Admin() :username(""), password("") {}
		Admin(const string& username, const string& password) {
			SetUsername(username);
			SetPassword(password);
		}
		string GetUsername()const {
			return username;
		}
		void SetUsername(string username) {
			this->username = username;
		}
		string GetPassword()const {
			return password;
		}
		void SetPassword(string password) {
			this->password = password;
		}

	};

	int global_id = 0;
	class Restaurant {
		int id;
		string name;
		string address;
		string city;
		int budget = 0;
	public:
		Restaurant() : name(""), address(""), city("") { SetId(); }
		Restaurant(const string& name, const string& address, const string& city, const int& budget) {
			SetId();
			SetName(name);
			SetAddress(address);
			SetCity(city);
			SetBudget(budget);
		}
		int GetId()const {
			return id;
		}
		void SetId() {
			this->id = ++global_id;
		}
		string GetName()const {
			return name;
		}
		void SetName(string name) {
			this->name = name;
		}
		string GetAddress()const {
			return address;
		}
		void SetAddress(string address) {
			this->address = address;
		}
		string GetCity()const {
			return city;
		}
		void SetCity(string city) {
			this->city = city;
		}
		int GetBudget()const {
			return budget;
		}
		void SetBudget(int budget) {
			this->budget = budget;
		}
		void ShowRestaurant()const {
			cout << "Restaurant Name: " << GetName() << endl;
			cout << "Address: " << GetAddress() << endl;
			cout << "City: " << GetCity() << endl;
			cout << "Budget: " << GetBudget() << endl;
		}

	};
	
	class Stock {
		int id;
		string ingredient_name;
		double price;
		int count;
		int kkal;
	public:
		Stock() : ingredient_name(""), price(0), count(0), kkal(0) { SetId(); }
		Stock(const string& ingredient_name, const int& count, const double& price, const int& kkal) {
			SetId();
			SetName(ingredient_name);
			SetCount(count);
			SetPrice(price);
			SetKkal(kkal);
		}
		int GetId()const {
			return id;
		}
		void SetId() {
			this->id = ++global_id;
		}
		string GetName()const {
			return ingredient_name;
		}
		void SetName(string name) {
			this->ingredient_name = name;
		}
		int GetCount()const {
			return count;
		}
		void SetCount(int count) {
			this->count = count;
		}
		double GetPrice()const {
			return price;
		}
		void SetPrice(double price) {
			this->price = price;
		}
		int GetKkal()const {
			return kkal;
		}
		void SetKkal(int kkal) {
			this->kkal = kkal;
		}
		void ShowIngredient() {
			cout << GetId() << ". " << GetName() << "                " << GetCount() << " piece        " << GetKkal() << " kkal " << endl;
			cout << "...................................................." << GetPrice() << " $ " << endl;
		}
	};
	
	class Menu {
		int id;
		string name;
		Stock** ingredients;
		int count;
		double menu_rating = 0;
		double price = 0;
		int used_count;
	public:		
		Menu() : name(""), count(0),ingredients(nullptr), menu_rating(0) {
			SetId();
		}
		Menu(const string& name, const int& count, Stock** ingredients, double menu_rating) {
			SetId();
			SetName(name);
			SetCount(count);
			SetIngredients(ingredients);
			SetMenuRating(menu_rating);
		}
		int GetId()const {
			return id;
		}
		void SetId() {
			this->id = ++global_id;
		}
		int GetCount()const {
			return count;
		}
		void SetCount(int count) {
			this->count = count;
		}
		Stock** GetStock() {
			return ingredients;
		}
		void SetIngredients(Stock** ingredients) {
			this->ingredients = ingredients;
		}
		string GetName()const {
			return name;
		}
		void SetName(const string& name) {
			this->name = name;
		}
		double GetMenuRating()const {
			return menu_rating;
		}
		void SetMenuRating(const double menu_rating) {
			if (menu_rating <= 5) {
				this->menu_rating = menu_rating;
			}
		}
		double GetTotalPrice() const {
			double p = 0;
			for (size_t i = 0; i < GetCount(); i++)
			{
				p += ingredients[i]->GetPrice();
			}
			return p;
		}
		int GetTotalKkal()const {
			int k = 0;
			for (size_t i = 0; i < GetCount(); i++)
			{
				k += ingredients[i]->GetKkal();
			}
			return k;
		}
		void ShowMenu()const {
			cout << endl;
			cout << GetId() << ". ";
			cout << GetName() << "......................................" << GetTotalPrice() << " $" << endl;
			cout << "Rating: " << GetMenuRating() << (char)15;
		}
		void AboutMeal()const {
			cout << endl << endl;
			for (size_t i = 0; i < GetCount(); i++)
			{
				cout << ingredients[i]->GetName() << "                " <<  ingredients[i]->GetKkal() << " kkal " << endl;
				cout << "...................................................." << ingredients[i]->GetPrice() << " $ " << endl;
			}

		}
		void ShowTotals()const {
			cout << "Total : " << GetTotalKkal() << " kkal" << endl;
			cout << "                                              Total Price: " << GetTotalPrice() << " $ " << endl;
		}
	};

	template<typename T>
	class DataSet {
		T** items;
		int count = 0;
	    public:
		int GetCount()const {
			return count;
		}
		T** GetItems()const {
			return items;
		}
		void Add(T* item) {
			auto newItem = new T * [count + 1]{};
			for (size_t i = 0; i < count; i++)
			{
				newItem[i] = items[i];
			}
			newItem[count] = item;

			items = newItem;
			newItem = nullptr;
			++count;
		}

		void DeleteById(const int& id) {
			auto Items = new T * [count - 1]{};
			for (size_t i = 0, k = 0; i < count; k++, i++)
			{
				if (items[i]->GetId() == id) {
					--k;
				}
				else {
					Items[k] = items[i];
				}
			}

			items = Items;
			Items = nullptr;
			--count;
		}
		T* GetItem(const int& id) {
			for (size_t i = 0; i < GetCount(); i++)
			{
				if (items[i]->GetId() == id) {
					return items[i];
				}
			}
			throw NotFoundDataException("Data Not Found", __FILE__, __LINE__, __DATE__);
		}
		T* Search(const string& name) {
			for (size_t i = 0; i < count; i++)
			{
				if (items[i]->GetName() == name) {
					return items[i];
				}
			}
			throw NotFoundDataException("Data Not Found", __FILE__, __LINE__, __DATE__);
		}
		~DataSet() {

		}
	};

	class DataBase {
	private:
		DataSet<Restaurant>restaurants;
		DataSet<Admin>admins;
		DataSet<Stock>ingredients;
		DataSet<Menu>meals;
	public:
		DataSet<Restaurant>GetRestaurants() {
			return restaurants;
		}
		DataSet<Admin>GetAdmins() {
			return admins;
		}
		DataSet<Stock>GetIngredients() {
			return ingredients;
		}
		DataSet<Menu> GetMeals() {
			return meals;
		}
		void AddRestaurant(Restaurant* restaurant) {
			restaurants.Add(restaurant);
		}
		void AddAdmin(Admin* admin) {
			admins.Add(admin);
		}
		void AddIngredient(Stock* ingredient) {
			ingredients.Add(ingredient);
		}
		void AddMeal(Menu* meal) {
			meals.Add(meal);
		}
		void DeleteMeal(int id) {
			meals.DeleteById(id);
		}
		void DeleteIngredients(int id) {
			ingredients.DeleteById(id);
		}
		void UpdateMealName(const int& id, const string& newname) {
			auto item = meals.GetItem(id);
			item->SetName(newname);
		}
		void UpdateMealRating(const int& id, const double& rating) {
			auto item = meals.GetItem(id);
			item->SetMenuRating(rating);
		}
		void UpdateMealIngredient(const int& id,const int& count, Stock**ingredients) {
			auto item = meals.GetItem(id);
			item->SetIngredients(ingredients);
		}
		void UpdateIngredientCount(const int& id, const int& count) {
			auto item = ingredients.GetItem(id);
			item->SetCount(count);
		}
		void SearchMeal(const string& name) {
			auto meal = meals.Search(name);
			meal->ShowMenu();
		}
		void SearchIngredient(const string& name) {
			auto ingredient = ingredients.Search(name);
			ingredient->ShowIngredient();
		}
		void ShowRestaurant() {
			for (size_t i = 0; i < restaurants.GetCount(); i++)
			{
				restaurants.GetItems()[i]->ShowRestaurant();
			}
		}
		void ShowStock() {
			for (size_t i = 0; i < ingredients.GetCount(); i++)
			{
				ingredients.GetItems()[i]->ShowIngredient();
			}			
		}
		void ShowMenu() {
			for (size_t i = 0; i < meals.GetCount(); i++)
			{
				meals.GetItems()[i]->ShowMenu();
			}
		}
		void ShowMealDetails(const int& id) {
			for (size_t i = 0; i < meals.GetCount(); i++)
			{
				if (meals.GetItems()[i]->GetId() == id) {
					meals.GetItems()[i]->AboutMeal();
					meals.GetItems()[i]->ShowTotals();
				}
			}
		}
		

	};

	class Order {
		int id;
		Menu* meals;
		Stock* ingredients;
		
		int used_count ;
	public:
		Order() :meals(NULL),  ingredients(NULL),used_count(0) { SetId(); }
		Order(Menu* meals, Stock* ingredients,const int&used_count) {
			SetId();
			SetMeals(meals);
			SetStock(ingredients);
			SetUsedCount(used_count);
		}
		int GetId()const {
			return id;
		}
		void SetId() {
			this->id = ++id;
		}
		void SetMeals(Menu* meals) {
			this->meals = meals;
		}
		Menu* GetMeals() {
			return meals;
		}
		void SetStock(Stock* ingredients) {
			this->ingredients = ingredients;
		}
		Stock* GetIngredients() {
			return ingredients;
		}
		
		
		double GetTotalPrice() {
			double p = 0;
			
			p = meals->GetTotalPrice();
			p += ingredients->GetPrice();
			
			return p;
		}
		bool EnterUsedCount( int used_count) {
		
					auto c = ingredients->GetCount();
						if (c > used_count) {
							c -= used_count;
							ingredients->SetCount(c);
							return true;
						}		
			return false;
		}
		void SetUsedCount( int used_count) {
			this->used_count = used_count;
		}
		int GetUsedCount() const{
			return used_count;
		}
		double GetTotalPrices() {
				double price = ingredients->GetPrice();
				int count = GetUsedCount();
				return price * count;
		}
		void ShowOrder() {
			cout << "Order " << GetId() << ":" << endl;
				meals->ShowMenu();
					if (ingredients != nullptr) {
						cout << endl;
						meals->AboutMeal();
						ShowOrderIngredients();
					}
					cout << "                                                        TOTAL Price: " << GetTotalPrice() << endl;
		}
		void ShowOrderIngredients() {
			
				cout << ingredients->GetName() << "                " <<GetUsedCount()  << " piece        " << ingredients->GetKkal() << " kkal " << endl;
				cout << "...................................................." <<GetTotalPrice()  << " $ " << endl;

		
		}
	};

	class Kitchen {
		Order* orders;
		int count;
	public:
		Kitchen():count(0),orders(NULL){}
		Kitchen(const int& count, Order* orders) {
			SetCount(count);
			this->orders = orders;
		}
		Order* GetOrders() {
			return orders;
		}
		int GetCount()const {
			return count;
		}
		void SetCount(const int& count) {
			this->count = count;
		}		
		Order* GetOrder(const int& id) {
			for (size_t i = 0; i < GetCount(); i++)
			{
				if (orders[i].GetId() == id) {
					return &orders[i];
				}
			}
			throw NotFoundDataException("Data Not Found", __FILE__, __LINE__, __DATE__);
		}
		bool ControlOrder(const int& id) {
			auto order = GetOrder(id);
			auto ing = order->GetIngredients();
			
				
			if (order != nullptr) {
					bool control = order->EnterUsedCount(order->GetUsedCount());
					if (control) {
						return true;
					}
					return false;
				
			}
			return false;
		}
		
	};


}

	






