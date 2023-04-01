#include <iostream>
using namespace std;

const int MAX_STACK = 5;

struct Stack {
	int top;
	int data[MAX_STACK];
};

Stack stack;
void inisialisasi(){
	stack.top = -1;
};

void push(int data){
	stack.top++;
	stack.data[stack.top] = data;
	cout << "Data berhasil ditambahkan " << endl;
};

void pop(){
	cout << "Data " << stack.data[stack.top]
	<< " Sudah dihapus " << endl;
	stack.top--;
};

void clear(){
	stack.top = -1;
	cout << "Stack sudah dikosongkan " << endl;
};

bool isEmprty(){
	return (stack.top == -1);
};

bool isFUll(){
	return (stack.top >= (MAX_STACK - 1));
};

void print(){
	cout << "Isi stack : "<< endl;
	for (int i = stack.top; i >= 0; i--){
		cout << stack.data[i] << endl;
	}
	cout << endl;
};

int main (){
	inisialisasi();
	int data;
	int pilihanMenu;
	
	do {
		cout << "===== PILIHAN MENU STACK ====== \n\n";
		cout << "1. Menambahkan item stack " << endl;
		cout << "2. Menghapus item stack " << endl;
		cout << "3. Menampilkan item stack " << endl;
		cout << "4. Mengosongkan stack " << endl;
		cout << "5. Selesai" << endl;
		
		cout << "Masukan pilihan anda : ";
		cin >> pilihanMenu;
		cout << endl;
		
		switch(pilihanMenu){
			case 1 :
				cout << "Masukan data : " ;
				cin >> data;
				push(data);
				break;
			case 2 :
				pop();
				break;
			case 3 :
				print();
				break;
			case 4 :
				clear();
				break;
		}
	} while (pilihanMenu != 5);
	
	cout << endl;
	system("pause");
	return 0;
}
