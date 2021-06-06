#pragma once
#include"Entities.h"

using namespace std;
using namespace Entities;

namespace ClientSection {
	class Client {
		string table_no;
	public:
		Client():table_no(""){}
		Client(const string& table_no) {
			SetTableNo(table_no);
		}
		string GetTableNo()const {
			return table_no;
		}
		void SetTableNo(const string& table_no) {
			this->table_no = table_no;
		}

	};

}