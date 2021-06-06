#pragma once
#include<iostream>
#include<fstream>
#include"Entities.h"

using namespace std;
using namespace Entities;

namespace FileHelpers {
	class FileHelper {
	public:
		static string filename;

		static void WriteLogs(string data) {
			ofstream fout(filename, ios::app);
			if (fout.is_open()) {
				fout << data << endl;
				fout.close();
			}
		}
		
	};

	string FileHelper::filename = "Logs.txt";

	class FileHelper2 {
	public:
		static string filename;
		static void Save(DataBase db) {
			ofstream fout(filename, ios::app);
			auto items = db.GetIngredients().GetItems();
			if (fout.is_open()) {
				
				for (size_t i = 0; i < db.GetIngredients().GetCount(); i++)
				{
					fout <<items[i]->GetName() << "                " << items[i]->GetCount() << " piece        " << items[i]->GetKkal() << " kkal " << endl;
					cout << "...................................................." << items[i]->GetPrice() << " $ " << endl;
				}
				fout.close();
			}
		}
		static DataBase Read() {
			DataBase db;
			ifstream fin(filename);

			if (fin.is_open()) {				
				for (size_t i = 0; i < db.GetIngredients().GetCount(); i++)
				{					
					Stock* ing = new Stock;

					int id;
					string ingredient_name;
					double price;
					int count;
					int kkal;

					fin >> ingredient_name >> price >> count >> kkal;
					ing->SetName(ingredient_name);
					ing->SetPrice(price);
					ing->SetCount(count);
					ing->SetKkal(kkal);

					db.AddIngredient(ing);
				}
				fin.close();

				return db;
			}
		}
	};

	string FileHelper2::filename = "Stock.txt";
}