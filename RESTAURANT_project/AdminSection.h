#pragma once
#include"Entities.h"
using namespace std;
using namespace Entities;


namespace AdminSection {
	using namespace Entities;
	class AdminController {
		DataBase* _database;
	public:
		AdminController(DataBase* database) {
			_database = database;
		}
		bool ControlAdmin(const string& username, const string& password) {
			for (size_t i = 0; i < _database->GetAdmins().GetCount(); i++)
			{
				auto items = _database->GetAdmins();
				auto adminArray = items.GetItems();
				if (adminArray[i]->GetUsername() == username && adminArray[i]->GetPassword() == password) {
					return true;
				}
			}

			return false;
		}
	};

	

}

