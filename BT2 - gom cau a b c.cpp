#include <iostream>
#include <string>
using namespace std;

struct SinhVien{
	string hoten;
    string masv;
    int namsinh;
    string lop;
};

// ================= DANH SACH LIEN KET DON =================
struct nodeD{
	SinhVien info;
	nodeD *next;
};

nodeD *newnodeD (SinhVien sv){
	nodeD *p = new nodeD;
	p->info= sv;
	p->next= NULL;
	return p;
}

void insertlastD(nodeD *&first, SinhVien sv){
	nodeD *p = newnodeD(sv);
	if (first==NULL){
		first=p;
	} else {
		nodeD *temp =first;
		while (temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=p;
	}
}

void duyetD(nodeD *first){
	while (first != NULL) {
        cout << first->info.hoten << " | "
             << first->info.masv << " | "
             << first->info.namsinh << " | "
             << first->info.lop << endl;
        first = first->next;
	}
}

// Ham giai phong bo nho DSLK Don
void clearD(nodeD *&first) {
    nodeD *temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        delete temp;
    }
}

// ================= DANH SACH LIEN KET VONG =================
struct nodeV{
	SinhVien info;
	nodeV *next;
};

void insertlastV( nodeV *&first, SinhVien sv){
	nodeV *p = new nodeV{sv,NULL};
	if (first==NULL){
		first=p;
		p->next=first;
	} else {
		nodeV *temp= first;
		while (temp->next!=first){
			temp=temp->next;
		}
		temp->next=p;
		p->next=first;
	}
}

void duyetV(nodeV *first){
	if (first==NULL) return;
	
	nodeV *temp=first;
	do {
        cout << temp->info.hoten << " | "
             << temp->info.masv << " | "
             << temp->info.namsinh << " | "
             << temp->info.lop << endl;
        temp = temp->next;
    } while (temp != first);
}

// Ham giai phong bo nho DSLK Vong
void clearV(nodeV *&first) {
    if (first == NULL) return;
    nodeV *temp = first->next; // Bat dau xoa tu node thu 2
    while (temp != first) {
        nodeV *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    delete first; // Xoa node dau tien sau cung
    first = NULL;
}

// ================= DANH SACH LIEN KET KEP =================
struct nodeK{
	SinhVien info;
	nodeK *next;
	nodeK *prev;
};

void insertlastK( nodeK *&first, SinhVien sv){
	nodeK *p = new nodeK{sv,NULL,NULL};
	if (first==NULL){
		first=p;
	} else {
		nodeK *temp=first;
		while (temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=p;
		p->prev=temp;
	}
}

void duyetK(nodeK *first){
	while (first != NULL) {
        cout << first->info.hoten << " | "
             << first->info.masv << " | "
             << first->info.namsinh << " | "
             << first->info.lop << endl;
        first = first->next;
	}
}

// Ham giai phong bo nho DSLK Kep
void clearK(nodeK *&first) {
    nodeK *temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        delete temp;
    }
}

// ================= HAM MAIN =================
int main(){
	SinhVien a[] = {
        {"Nguyen Hoa Hau","D11K7",2002,"D20"},
        {"Do Luc Si","D11K8",2000,"D20"},
        {"Ly Minh Tinh","D11K9",2003,"D21"},
        {"Tran Dai Gia","D11K10",2003,"D21"}
    };

    SinhVien them = {"Duong Vo Si","D11K11",2000,"D18"};

    nodeD *firstD = NULL;
    nodeV *firstV = NULL;
    nodeK *firstK = NULL;

    for (int i = 0; i < 4; i++) {
        insertlastD(firstD, a[i]);
        insertlastV(firstV, a[i]);
        insertlastK(firstK, a[i]);
    }
	cout << "\n=== DSLK DON ===\n";
    duyetD(firstD);

    cout << "\n=== DSLK VONG ===\n";
    duyetV(firstV);

    cout << "\n=== DSLK KEP ===\n";
    duyetK(firstK);
    
    insertlastD(firstD, them);
    insertlastV(firstV, them);
    insertlastK(firstK, them);
    
	cout << "\n============= SAU KHI THEM 1 SINH VIEN VAO CUOI DANH SACH =============\n";
    
	cout << "\n=== DSLK DON ===\n";
    duyetD(firstD);

    cout << "\n=== DSLK VONG ===\n";
    duyetV(firstV);

    cout << "\n=== DSLK KEP ===\n";
    duyetK(firstK);

    // Don dep bo nho truoc khi ket thuc chuong trinh
    clearD(firstD);
    clearV(firstV);
    clearK(firstK);

    return 0;
}
