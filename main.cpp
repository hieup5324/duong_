#include <iostream>
using namespace std;

struct Book{
	string nameBook, idBook, nameTg;
	int namSx;
};

struct BK{
	Book s;
	BK *next;
};

typedef struct BK* bk;


bk makeNode(){
	Book s;
	cout << "Nhap thong tin sach :\n";
	cout << "Nhap ID sach :"; cin >> s.idBook;
	cout << "Nhap ten sach :"; cin.ignore();
	getline(cin, s.nameBook);
	cout << "Nhap ten tac gia :"; cin.ignore();
	getline(cin, s.nameTg);
	cout << "Nhap nam san xuat :"; cin >> s.namSx;
	bk tmp = new BK();
	tmp->s = s;
	tmp->next = NULL;
	return tmp;
}

//Kiem tra rong
bool empty(bk a){
	return a == NULL;
}

int Size(bk a){
	int cnt = 0;
	while(a != NULL){
		++cnt;
		a = a->next; // gan dia chi cua not tiep theo cho node hien tai
		//cho node hien tai nhay sang not tiep theo
	}
	return cnt;
}

//them sach
void insertFirst(bk &a){
	bk tmp = makeNode();
	if(a == NULL){
		a = tmp;
	}
	else{
		tmp->next = a;
		a = tmp;
	}
}

//Them sach cuoi
void insertLast(bk &a){
	bk tmp = makeNode();
	if(a == NULL){
		a = tmp;
	}
	else{
		bk p = a;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}

//Them 1 phan tu vao giua
void insertMiddle(bk &a,int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n + 1){
		cout << "Vi tri chen khong hop le !\n"; return;
	}
	if(pos == 1){
		insertFirst(a); return;
	}
	else if(pos == n + 1 ){
		insertLast(a); return;
	}
	bk p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p->next;
	}
	bk tmp = makeNode();
	tmp->next = p->next;
	p->next = tmp;
}

//xoa sach o dau
void deleteFirst(bk &a){
	if(a == NULL) return;
	a = a->next;
}

//xoa sach cuoi
void deleteLast(bk &a){
	if(a == NULL) return;
	bk truoc = NULL, sau = a;
	while(sau->next != NULL){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = NULL;
	}
	else{
		truoc->next = NULL;
	}
}

//Xoa sach o giua
void deleteMiddle(bk &a, int pos){
	if(pos <=0 || pos > Size(a)) return;
	bk truoc = NULL, sau = a;
	for(int i = 1; i < pos; i++){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = a->next;
	}
	else{
		truoc->next = sau->next;
	}
}

void in(Book s){
	cout << "\n--------------------------------\n";
	cout << "ID sach : " << s.idBook << endl;
	cout << "Ten sach :" << s.nameBook << endl;
	cout << "Ten tac gia : " << s.nameTg << endl;
	cout << "Nam san xuat : " << s.namSx << endl;
	cout << "\n--------------------------------\n";
}

void inds(bk a){
	cout << "Danh sach sinh vien :\n";
	while(a != NULL){
		in(a->s);
		a = a->next;
	}
	cout << endl;
}

int main(){
	bk head = NULL;
	while(1){
		cout << "-----------------MENU---------------\n";
		cout << "1. Chen sach vao dau danh sach\n";
		cout << "2. Hien thi sach cua tac gia Mai Thien An\n";
		cout << "3. Chen sach moi vao giua danh sach\n";
		cout << "4. Xoa sach o giua\n";
		cout << "5. Duyet danh sach lien ket\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;
		if(lc == 1){
			insertFirst(head);
		}
		else if(lc == 3){
			int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
			insertMiddle(head, pos);
		}
		else if(lc == 4){
			int pos; cout << "Nhap vi tri can xoa:"; cin >> pos;
			deleteMiddle(head, pos);
		}
		else if(lc == 5){
			inds(head);
		}
		else if(lc == 0){
			break;
		}
	}
	return 0;
}


