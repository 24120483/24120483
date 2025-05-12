#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct Company {
	string name;
	string profit_tax;
	string address;
};
struct HashTable {
	Company Table[2000];
};

vector<Company> readCompanyList(string file_name) {
	vector<Company> list;
	ifstream file(file_name);
	if (!file) {
		cout << "khong the mo file de doc!" << endl;
		return list;
	}
	string line;
	getline(file, line);
	while (getline(file, line)) {
		Company c;
		stringstream s(line);
		string s1, s2, s3;
		getline(s, s1, '|');
		c.name = s1;
		getline(s, s2, '|');
		c.profit_tax = s2;
		getline(s, s3, '|');
		c.address = s3;
		list.push_back(c);
	}
	file.close();
	return list;
}

long long hashString(string company_name) {
	long long sum = 0;

	if (company_name.size() > 20) {
		string temp;
		temp = company_name.substr(company_name.length() - 20);
		for (int i = 0; i < 20; i++) {
			long long ascii = static_cast<long long> (temp[i]);
			sum += ascii * pow(31, i);
		}
		return abs(sum % 2000);
	}
	for (int i = 0; i < company_name.length(); i++) {
		long long ascii = static_cast<long long> (company_name[i]);
		sum += ascii * pow(31, i);
	}
	return abs(sum % 2000);
}
bool isEmpty(Company c){
	return c.name.empty() && c.profit_tax.empty() && c.address.empty();
}
HashTable* createHashTable(vector<Company> list_company) {
	HashTable* h = new HashTable;
	for (int i = 0; i < list_company.size(); i++) {
		long long index = hashString(list_company[i].name);
		if (isEmpty(h->Table[index])) {
			h->Table[index] = list_company[i];
		}
		else {
			long long newindex = (index + 1) % 2000;
			while (!isEmpty(h->Table[newindex])) {
				newindex = (newindex + 1) % 2000;
			}
			h->Table[newindex] = list_company[i];
		}
	}
	return h;
}

void insert(HashTable* hash_table, Company company) {
	long long index = hashString(company.name);
	if (isEmpty(hash_table->Table[index])) {
		hash_table->Table[index] = company;
	}
	else {
		long long newindex = (index + 1) % 2000;
		while (newindex != index && !isEmpty(hash_table->Table[newindex])) {
			newindex = (newindex + 1) % 2000;
		}
		if (newindex != index) {
			hash_table->Table[newindex] = company;
		}
		else {
			cout << "hash table is full!" << endl;
		}
	}
}

Company* search(HashTable* hash_table, string company_name) {
	long long index = hashString(company_name);
	if (!isEmpty(hash_table->Table[index])) {
		if (hash_table->Table[index].name == company_name) {
			return &(hash_table->Table[index]);
		}
		else {
			long long newindex = (index + 1) % 2000;
			while (newindex != index && !isEmpty(hash_table->Table[newindex]) && hash_table->Table[newindex].name != company_name) {
				newindex = (newindex + 1) % 2000;
			}
			if (newindex == index || isEmpty(hash_table->Table[newindex])) {
				return NULL;
			}
			else {
				return &(hash_table->Table[newindex]);
			}
		}
	}
	return NULL;
}

int main() {
	vector<Company> list = readCompanyList("MST.txt");
	HashTable* h = createHashTable(list);
	ifstream file1("input.txt");
	if (!file1) {
		cout << "khong the mo file de doc!" << endl;
		return 1;
	}
	ofstream file2("output.txt");
	if (!file2) {
		cout << "khong the mo file de ghi!" << endl;
		return 1;
	}
	string line;
	while (getline(file1, line)) {
		Company* c = search(h, line);
		if (c != NULL) {
			file2 << c->name << "|" << c->profit_tax << "|" << c->address << endl;
		}
		delete c;
	}
	file1.close();
	file2.close();
	delete h;
	return 0;
}