#include<bits/stdc++.h>
using namespace std;

// tao 1 struct khach hang
struct KhachHang{
    char fullname[10];
    char address[20];
    char phone [10];
    char birthday [10];
    int cccd;
    int tongGiaTriHopDong;
    int ChietKhau;
};



//hàm nhập một khach hang
void input (KhachHang &khachhang){
    cout<< "full name: ";
    fflush(stdin);
    gets(khachhang.fullname);
    cout<< "birthday: ";gets(khachhang.birthday);
    cout<< "address: ";gets(khachhang.address);
    cout<< "cccd: ";cin>>khachhang.cccd;
    cout<< "phone: ";
    cin.ignore();gets(khachhang.phone);
    cout<< "Tong gia tri HD da ky: ";
    cin>>khachhang.tongGiaTriHopDong;    

}




// hàm xuất khách hàng
void output(KhachHang khachhang){
    cout<< setw(10)<< khachhang.fullname;
    cout<< setw(10)<< khachhang.birthday;
    cout<< setw(10)<< khachhang.address;
    cout<< setw(10)<< khachhang.cccd;
    cout<< setw(10)<< khachhang.phone;
    cout<< setw(10)<< khachhang.tongGiaTriHopDong;
    cout<< setw(10)<< 0.05*khachhang.tongGiaTriHopDong;    
    cout<<endl;
}
// tạo node
struct node {
    KhachHang data;
    struct node *pNext;
};
// tạo danh sach quan li boi phead và ptail
struct LIST {
    node *pHead;
    node *ptail;
};
// khoi tao dnah sach
void create_list(LIST &List)
{
    List.pHead = NULL;
    List.ptail = NULL;
}
// ham khoi tao trả về node
node *create_node(KhachHang khachhang)
{
    node *new_KH = new node;
    new_KH->data = khachhang;
    new_KH->pNext =NULL;
    return new_KH;
}
// hàm thêm đầu danh sách
void add_first_list(LIST &List,node*p)
{
    if(List.pHead ==  NULL){
        List.pHead = List.ptail = p;
    }
    else{
        p->pNext = List.pHead;
        List.pHead = p;
    }
}
// hàm thêm cuối danh sách
void add_last_list(LIST &List,node *p)
{
    if(List.pHead ==  NULL){
        List.pHead = List.ptail = p;
    }
    else{
        List.ptail->pNext = p;
        List.ptail = p;
    }
}
//hàm nhập danh sách
void input_list(LIST &List)
{
    int n;
    cout<< "so luong khach hang can quan li: ";cin>>n;
    for(int i=0;i<n;i++)
    {
        KhachHang khachhang;
        cout<< "khach hang thu "<<i+1<<endl;
        input(khachhang);
        node *p = create_node(khachhang);
        int pick;
        cout<< "1.add first"<<endl;
        cout<< "2.add last"<<endl;cin>>pick;
        switch (pick){
            case 1:
                add_first_list(List,p);
                break;
            case 2:
                add_last_list(List,p);
                break;
        }
    }
}

void Chiet_khau_xy(LIST &List){};

// hàm tìm thông tin khách hàng bằng cccc
void find_infor_by_cccd (LIST List)
{
    int cccd_temp;
    cout<< "nhap cccd cua khach hang muon tim: ";cin>>cccd_temp;
    for(node *k = List.pHead;k !=NULL; k=k->pNext){
        if(k->data.cccd == cccd_temp){
            output(k->data);
        }
   }
}
// ham xoa dau danh sach
void remove_firstList (LIST &List)
{
    if(List.pHead == NULL)
        cout<< "ko co du lieu"<<endl;
    else
    {
        node *p = List.pHead;
        List.pHead = List.pHead->pNext;
        delete p;
    }
}
// ham xoa cuoi danh sach
void remove_lastList(LIST &List)
{
    for(node *i=List.pHead;i!= NULL;i=i->pNext)
    {

        if(i->pNext == List.ptail)
        {
            delete List.ptail;
            i->pNext = NULL;
            List.ptail = i;
        }
    }
}
//xóa khách hàng bằng cccd
void remove_cccd(LIST &List)
{
    node *p;
    int cccd_remove;
    cout<< "nhap cccd cua khach hang can xoa: ";
    cin>>cccd_remove;
    if(cccd_remove == List.pHead->data.cccd)
    {
        remove_firstList(List);
        return;
    }
    if(cccd_remove == List.ptail->data.cccd)
    {
        remove_lastList(List);
        return;
    }
    for(node *i=List.pHead;i!= NULL;i=i->pNext)
    {
        if(i->data.cccd == cccd_remove)
        {
            p->pNext = i->pNext;
            delete i;
            return;
        }
        p=i;
    }
}
// huy toan bo danh sach
void huy_toan_bo_ds(LIST &List)
{
    for(node *i=List.pHead;i!= NULL;i=i->pNext)
    {
        node* p = List.pHead;
        List.pHead=List.pHead->pNext;
        delete p;
    }
    List.ptail=NULL;
}

// sắp sếp theo số tiền đầu tư
// void sort_by_expense(LIST List)
// {
//     for(node *i = List.pHead;i!=NULL;i=i->pNext)
//     {
//         for(node *j=i->pNext;j!=NULL;j=j->pNext)
//         {
//             if(i->data.expense > j->data.expense){
//                 KhachHang temp = i->data;
//                 i->data = j->data;
//                 j->data = temp;
//             }
//         }

//     }
// }
// khác hàng có chi phí cao nhất
// void KhacHang_co_chi_phi_thap(LIST List)
// {
//     sort_by_expense(List);
//     output(List.pHead->data);
// }







// ham sua thong tin khach hang
void fix_info(LIST List)
{
    int cccd_temp;
    cout<< "nhap cccd cua khach hang muon sua: ";cin>>cccd_temp;
    for(node *k = List.pHead;k !=NULL; k=k->pNext){
        if(k->data.cccd == cccd_temp){
            input(k->data);
        }
   }
}
// đọc file
void write_file (LIST List)
{
    FILE *f;

	f = fopen("file.dat", "wb");
	int n = 0;
	node* p;

	for (p = List.pHead; p != NULL; p = p->pNext)
		n = n + 1;
	fwrite(&n, sizeof(int), 1, f);

	for (p = List.pHead; p != NULL; p = p->pNext)
		fwrite(&p->data, sizeof(KhachHang), 1, f);
	fclose(f);
	cout << "\nSuccessfully Saved File!";
}
// ghi file
void read_file(LIST &List)
{
    FILE* f;
	KhachHang x;
	int i, n;
	node* p;
	node* q;
	f = fopen("file.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	bool check = true;
	int count = 0;

	for (i = 0; i < n; i++) {
		fread(&x, sizeof(KhachHang), 1, f);
		p = create_node(x);
		for (q = List.pHead; q != NULL; q = q->pNext) {
			if (q->data.cccd == p->data.cccd) {
				check = false;
			}
		}
		if (check) {
			add_last_list(List, p);
			count++;
		}
	}
	if (count > 0)
		cout << "\nSuccessfully Read File!";
	else
		cout << "\nUnsuccessfully Read File Due To Duplicated ProfileCode!";
	fclose(f);
}
// hàm hiện danh sách
void show_list(LIST List){
    cout<< setw(10)<< "FULL NAME";
    cout<< setw(10)<< "BIRTHDAY";
    cout<< setw(10)<< "ADDRESS";
    cout<< setw(10)<< "CCCD";
    cout<< setw(10)<< "PHONE";
    cout<< setw(10)<< "TOTAL";
    cout<< setw(10)<< "CK"<<endl;
    

    for(node *k = List.pHead;k !=NULL; k=k->pNext){
        output(k->data);
    }
}


//tổng tiền của các khách hàng
void Tong_Chiet_Khau (LIST &List )
{
    float sum = 0;
    for(node *i = List.pHead;i!=NULL;i=i->pNext)
    {
        sum += i->data.tongGiaTriHopDong;
    }
    cout<< "Tong Chiet Khau: "<<(sum*0.05)<<endl;
}

//CHIET KHAU X->Y
void ck_xy(LIST &List){
    int x, y;
    KhachHang data;
    cout<< "nhap x, y: ";
    cin>>x;
    cin>>y;
    if(x<data.ChietKhau  && data.ChietKhau<y){
        show_list(List);
        cout<<endl;
    }else
    cout<<"Không có hóa đơn có chiết khấu trong khoảng cần tìm"<<endl;
}









//===================================DANH SACH LIÊN KẾT ĐÔI=====================
// quan li don vi thi cong

// TẠO KIEU DU LIEU
struct company {
    char id_company[15];
    char id_contact[15];
    char time_start[15];
    char progress[15];
    int number_workers;
    float material_money,cost;
};
// TẠO NODE
struct node_company{
    company data;
    struct node_company *pNext;
    struct node_company *pPrev;
};
// TSO DANH SACH DE QUAN LI
struct LIST_company {
    node_company*pHead;
    node_company*ptail;
};
// HAM NHAP
void input_company (company &company_temp)
{
    cout<< "id_company: ";fflush(stdin);gets(company_temp.id_company);
    cout<< "id_contact: ";gets(company_temp.id_contact);
    cout<< "time_start(dd/mm/yy): ";gets(company_temp.time_start);
    cout<< "number_workers: ";cin>>company_temp.number_workers;
    cout<< "cost: ";cin>>company_temp.cost;
    cout<< "material_money: ";cin>>company_temp.material_money;
    cout<< "progress: ";fflush(stdin);gets(company_temp.progress);
    cout<< "------------------------------"<<endl;
}
// HÀM XUẤT
void output_datacompany(company company_temp)
{
        cout<< setw(10)<<company_temp.id_company;
        cout<< setw(20)<<company_temp.id_contact;
        cout<< setw(20)<<company_temp.time_start;
        cout<< setw(20)<<company_temp.material_money;
        cout<< setw(20)<<company_temp.cost;
        cout<< setw(20)<<company_temp.number_workers;
        cout<< setw(20)<<company_temp.progress;
        cout<<endl;
}
// TAO DANH SACH
void createList_company(LIST_company &List)
{
    List.pHead = NULL;
    List.ptail = NULL;
}
// HÀM TRẢ VỀ NODE
node_company *creteNode_company(company company_temp)
{
    node_company *p = new node_company;
    p->data = company_temp;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}/*
void input_list_company(LIST_company &List_c)
{
    int n;
    cout<< "nhap vao so luong don vi thi cong can quan li: "<<endl;
    for(int i=0;i<n;i++)
    {
        company temp;
        input_company(temp);
        node_company *p = creteNode_company(temp);
        addFirstLisTCompany(List_c,p);
    }
}*/
// HAM THEM ĐẦU
void addFirstLisTCompany(LIST_company &List,node_company *temp)
{
    if(List.pHead == NULL && List.ptail == NULL){
        List.pHead = List.ptail = temp;
    }else
    {
        temp->pNext = List.pHead;
        List.pHead ->pPrev = temp;
        List.pHead = temp;
    }
}
// HÀM THÊM CUỐI
void addLastListCompany(LIST_company &List,node_company *temp)
{
    if(List.pHead == NULL && List.ptail == NULL){
        List.pHead = List.ptail = temp;
    }
    else
    {
        List.ptail->pNext = temp;
        temp->pPrev = List.ptail;
        List.ptail = temp;
    }
}
// HÀM NHẬP DANH SÁCH VÀO LIST
void input_list_company(LIST_company &List_c)
{
    int n;
    cout<< "nhap vao so luong don vi thi cong can quan li: "<<endl;cin>>n;
    for(int i=0;i<n;i++)
    {
        company temp;
        input_company(temp);
        node_company *p = creteNode_company(temp);
        addFirstLisTCompany(List_c,p);
    }
}
// duyet danh sach tu dau den cuoi
void display1(LIST_company List){
    node_company *temp = List.pHead;
    while(temp != NULL)
    {
        output_datacompany(temp->data);
        temp = temp->pNext;
    }
    cout<<endl;
}
// duyet tu cuoi len dau
void display2(LIST_company List){
    node_company *temp = List.ptail;
    if(List.ptail == NULL){
        return;
    }
    while(temp != NULL)
    {
        output_datacompany(temp->data);
        temp = temp->pPrev;
    }
    cout<<endl;
}
// tim don vi thi cong them ma don vi
void find_id_company (LIST_company List){
    char idFind[10];
    cout<< "input id_company find: ";fflush(stdin);gets(idFind);
    for(node_company *i = List.pHead; i!= NULL;i = i->pNext)
    {
        if (strcmp(idFind,i->data.id_company)==0)
        {
            output_datacompany (i->data);
        }
    }
}
// sua lai don vi thi cong theo id
void fix_id_company (LIST_company List){
    char idFix[10];
    cout<< "input id_company fix: ";fflush(stdin);gets(idFix);
    for(node_company *i = List.pHead; i!= NULL;i = i->pNext)
    {
        if (strcmp(idFix,i->data.id_company)==0)
        {
            input_company(i->data);
            cout<< "fix info is successful"<<endl;
            break;
        }
    }
}
// HAM XOA ĐẦU
void removeFirstCompany(LIST_company &List)
{
    if(List.pHead == NULL){
        return;
    }
    List.pHead = List.pHead->pNext;
    List.pHead ->pPrev = NULL;
}
// HÀM XÓA CUỐI
void removeLastCompany (LIST_company &List)
{
    if(List.pHead == NULL){
        return;
    }
    List.ptail = List.ptail->pPrev;
    List.ptail ->pNext = NULL;
}
void remove_id(LIST_company &List)
{
    char id_remove[10];
    cout<< "nhap id don vi thi cong can xoa: ";fflush(stdin);gets(id_remove);
    if(strcmp(List.pHead->data.id_company,id_remove)==0)
    {
        removeFirstCompany(List);
        return;
    }
    else if(strcmp(List.ptail->data.id_company,id_remove)==0)
    {
        removeLastCompany(List);
        return;
    }
    else
    {
        for(node_company * i=List.pHead;i!=NULL;i=i->pNext)
        {
            if(strcmp(i->data.id_company,id_remove)==0)
            {
                i->pPrev->pNext = i->pNext;
                i->pNext->pPrev = i->pPrev;
                i->pPrev = NULL;
                i->pNext = NULL;
                delete i;
                break;
            }
        }
    }

}
void sort_by_cost(LIST_company List)
{
    for(node_company *i = List.pHead;i!=NULL;i=i->pNext)
    {
        for(node_company *j=i->pNext;j!=NULL;j=j->pNext)
        {
            if(i->data.cost > j->data.cost){
                company temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }

    }
    display1(List);
}
// ĐỌC FILE
void write_file_company(LIST_company List)
{
    FILE *f;

	f = fopen("file_company.dat", "wb");
	int n = 0;
	node_company* p;

	for (p = List.pHead; p != NULL; p = p->pNext)
		n = n + 1;
	fwrite(&n, sizeof(int), 1, f);

	for (p = List.pHead; p != NULL; p = p->pNext)
		fwrite(&p->data, sizeof(company), 1, f);
	fclose(f);
	cout << "\nSuccessfully Saved File!";
}
// GHI FILE
void read_file_company(LIST_company &List)
{
    FILE* f;
	company x;
	int i, n;
	node_company* p;
	node_company* q;
	f = fopen("file_company.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	bool check = true;
	int count = 0;

	for (i = 0; i < n; i++) {
		fread(&x, sizeof(company), 1, f);
		p = creteNode_company(x);
		for (q = List.pHead; q != NULL; q = q->pNext) {
			if (q->data.id_company == p->data.id_company) {
				check = false;
			}
		}
		if (check) {
			addFirstLisTCompany(List, p);
			count++;
		}
	}
	if (count > 0)
		cout << "\nSuccessfully Read File!";
	else
		cout << "\nUnsuccessfully Read File Due To Duplicated ProfileCode!";
	fclose(f);
}



//==================================== STACK NHAN VIEN===================
struct NhanVien {
    char id[10];
    char fullname[10];
    char id_contact[10];
    float luong_CB,hoa_hong;
};
void input_nhanvien(NhanVien &nhanvien)
{
    cout<< "id: ";fflush(stdin);
    gets(nhanvien.id);
    cout<< "fullname: ";gets(nhanvien.fullname);
    cout<< "id_contact: ";gets(nhanvien.id_contact);
    cout<< "luong co ban: ";cin>>nhanvien.luong_CB;
    cout<< "hoa hong: ";cin>>nhanvien.hoa_hong;
    cout<< "============="<<endl;
}
void output_nhanvien(NhanVien nhanvien)
{
    cout<< setw(10)<< nhanvien.id;
    cout<< setw(10)<< nhanvien.fullname;
    cout<< setw(10)<< nhanvien.id_contact;
    cout<< setw(10)<< nhanvien.luong_CB;
    cout<< setw(10)<< nhanvien.hoa_hong;
    cout<<endl;
}
struct node_nhanvien{
    NhanVien data;
    struct node_nhanvien*pNext;
};
struct stack_Listnhanvien{
    node_nhanvien*pTop;

};
struct ListNhanvien
{
    node_nhanvien *pHead;
    node_nhanvien *ptail;
};
void createListNhanvien (ListNhanvien &l)
{
    l.pHead = NULL;
    l.ptail = NULL;
}
node_nhanvien *create_nodestack(NhanVien nhanvien)
{
    node_nhanvien *temp = new node_nhanvien;
    temp->data = nhanvien;
    temp->pNext = NULL;
    return temp;
}
void create_stack_nhanvien (stack_Listnhanvien &s)
{
    s.pTop = NULL;
}
//ktra rong
bool isEmpty(stack_Listnhanvien s)
{
    if(s.pTop == NULL)return 1;
    return 0;
}
//them vao dau
void pust(stack_Listnhanvien &s,node_nhanvien *temp)
{
   // node_nhanvien *temp = create_nodestack(nhanvien);
    if(s.pTop== NULL)
        s.pTop = temp;
    else{
        temp->pNext = s.pTop;
        s.pTop = temp;
    }

}

// lay thong tin va xoa no di
bool pop(stack_Listnhanvien &s,NhanVien &x)
{
    if(s.pTop == NULL)return false;
    else{
        node_nhanvien *temp= s.pTop;
        x = temp ->data;
        s.pTop = s.pTop ->pNext;
        delete temp;
    }
    return true;
}
void top(stack_Listnhanvien s)
{
    if(s.pTop!=NULL)
        output_nhanvien(s.pTop->data);
}
void input_stack(stack_Listnhanvien &s)
{
    int n;
    cout<< "so luong nhan vien: ";cin>>n;
    for(int i=0;i<n;i++)
    {
        NhanVien nhanvien;
        input_nhanvien(nhanvien);
        node_nhanvien *temp= create_nodestack(nhanvien);
        pust(s,temp);
        //themvaodau(l,temp);
    }
}
void themvaodau(ListNhanvien &l, node_nhanvien* nhanvien )
{
    if(l.pHead == NULL)
        l.pHead = l.ptail = nhanvien;
    else
    {
        nhanvien->pNext = l.pHead;
        l.pHead = nhanvien;
    }
}
void themvaocuoi(ListNhanvien &l,node_nhanvien *nhanvien)
{
    if(l.pHead == NULL)
        l.pHead = l.ptail = nhanvien;
    else{
        l.ptail->pNext = nhanvien;
        l.ptail= nhanvien;
    }
}
void gan_stack (stack_Listnhanvien &s,ListNhanvien &l)
{
    while(isEmpty(s)== false)
    {
        NhanVien temp;
        pop(s,temp);
        node_nhanvien *p = create_nodestack(temp);
        themvaodau(l,p);
    }
}
void add_stack(stack_Listnhanvien &s,ListNhanvien &l)
{
    for(node_nhanvien *i = l.pHead;i!=NULL;i=i->pNext)
    {
        pust(s,i);
    }
}
void output_stack(stack_Listnhanvien s)
{
    if(isEmpty(s) == true)
        cout<< "ko co du lieu de xuat ..."<<endl;
    else
    {
        while(isEmpty(s) == false)
        {
            NhanVien temp;
            pop(s,temp);
            output_nhanvien(temp);
        }
    }
}
void write_file_stack(ListNhanvien l)
{
    FILE *f;

	f = fopen("file_stack.dat", "wb");
	int n = 0;
	node_nhanvien* p;

	for (p = l.pHead; p != NULL; p = p->pNext)
		n = n + 1;
	fwrite(&n, sizeof(int), 1, f);

	for (p = l.pHead; p != NULL; p = p->pNext)
		fwrite(&p->data, sizeof(NhanVien), 1, f);
	fclose(f);
	cout << "\nSuccessfully Saved File!";
}
void read_file_nhanvien(ListNhanvien &l,stack_Listnhanvien &s)
{
    FILE* f;
	NhanVien x;
	int i, n;
	node_nhanvien* p;
	node_nhanvien* q;
	f = fopen("file_company.dat", "rb");
	fread(&n, sizeof(int), 1, f);
	bool check = true;
	int count = 0;

	for (i = 0; i < n; i++) {
		fread(&x, sizeof(NhanVien), 1, f);
		p = create_nodestack(x);
		for (q = l.pHead; q != NULL; q = q->pNext) {
			if (q->data.id == p->data.id) {
				check = false;
			}
		}
		if (check) {
			themvaocuoi(l, p);
			add_stack(s,l);
			count++;
		}
	}
	if (count > 0)
		cout << "\nSuccessfully Read File!";
	else
		cout << "\nUnsuccessfully Read File Due To Duplicated ProfileCode!";
	fclose(f);
}
//=================================QUEUE======================
struct hopdong{
    char mahopdong [10];
    char ngaykiket [10];
    char maNV [10];
    float so_tien_du_tru,coc;

};
void nhaphopdong(hopdong &h)
{
    cout<< "ma hop dong: ";fflush(stdin);
    gets(h.mahopdong);
    cout<< "ngay ki ket: ";gets(h.ngaykiket);
    cout<< "ma nhan vien: ";gets(h.maNV);
    cout<< "so tien du tru: ";cin>>h.so_tien_du_tru;
    cout<< "coc: ";cin>>h.coc;
    cout<< "------------------"<<endl;
}
void xuathopdong(hopdong h)
{
    cout<< setw(10)<<h.mahopdong;
    cout<< setw(10)<<h.ngaykiket;
    cout<< setw(10)<<h.maNV;
    cout<< setw(10)<<h.so_tien_du_tru;
    cout<< setw(10)<<h.coc;
    cout<<endl;

}
struct node_hopdong{
    hopdong data;
    struct node_hopdong*pNext;
};
struct queue_hd{
    node_hopdong*pHead;
    node_hopdong*ptail;
};
void khoitaoList_queue(queue_hd &hd){
    hd.pHead = NULL;
    hd.ptail = NULL;
}
node_hopdong *tao_hopdong(queue_hd &hd,hopdong hp)
{
    node_hopdong *temp = new node_hopdong;
    temp->data = hp;
    temp->pNext = NULL;
    return temp;
}
bool isEmpty_eq(queue_hd hd)
{
    if(hd.pHead == NULL) return true;
    return false;
}

// co che them vao cuoi
void pust_eq(queue_hd &hd,node_hopdong *temp)
{
    if(isEmpty_eq(hd)==true)
        hd.pHead = hd.ptail = temp;
    else{
        hd.ptail->pNext = temp;
        hd.ptail = temp;
    }
}
void push_add(queue_hd &hd)
{
    hopdong x;
    nhaphopdong(x);
    node_hopdong *temp = tao_hopdong(hd,x);
    pust_eq(hd,temp);
    cout<< "done" <<endl;

}
//lay dau va xoa ra
bool pop_eq(queue_hd &hd,hopdong &temp)
{
    if(isEmpty_eq(hd) == true) return false;
    else{
        node_hopdong *h = hd.pHead;
        temp = h->data;
        hd.pHead = hd.pHead->pNext;
        delete h;

    }
    return true;
}
void top_eq(queue_hd hd)
{
    if(isEmpty_eq(hd) == true)
        cout<< "ko co du lieu"<<endl;
    else
        xuathopdong(hd.pHead->data);
}
void nhapds(queue_hd &hd)
{
    int n;
    cout<< "nhap danh sach :";cin>>n;
    for(int i=0;i<n;i++)
    {
        hopdong h;
        nhaphopdong(h);
        node_hopdong *temp = tao_hopdong(hd,h);
        pust_eq(hd,temp);
    }
}
void xuatds(queue_hd &hd)
{
    while(isEmpty_eq(hd)== false)
    {
        hopdong a;
        pop_eq(hd,a);
        xuathopdong(a);
    }
}
void menu()
{
    LIST List;
    create_list(List);
    FILE *f;

    LIST_company List_c;
    createList_company(List_c);

    stack_Listnhanvien s;
    create_stack_nhanvien(s);

    ListNhanvien l;
    createListNhanvien(l);

    queue_hd hopdong;
    khoitaoList_queue(hopdong);
    int chose;
    cout<< "1.------Khach Hang---------"<<endl;
    cout<< "2.------Din vi thi cong--------"<<endl;
    cout<< "3.------Nhanvien--------"<<endl;
    cout<< "4.-----Hop dong-------"<<endl;
    cout<< "moi ban chon: ";cin>>chose;
    do
    {
        switch(chose)
        {
            case 1:
                int chose_1;
                do{
                    //int chose_1;
                    cout<< "1.nhap thong tin"<<endl;
                    cout<< "2.xuat thong tin"<<endl;
                    cout<< "3.luu file"<<endl;
                    cout<< "4.doc file"<<endl;
                    cout<< "5.tim thong tin theo cccd"<<endl;
                    cout<< "6.sua thong tin khach hang bang ma cccd"<<endl;
                    cout<< "7.xoa thong tin khach hang"<<endl;
                    cout<< "8.tinh tong chiet khau"<<endl;
                    cout<< "9.danh sach kh co chiet khau trong khoang x->y"<<endl;
                    cout<< "moi ban chon: ";cin>>chose_1;
                    switch(chose_1)
                    {
                        case 1:
                            input_list(List);
                            break;
                        case 2:
                            show_list(List);
                            break;
                        case 3:
                            write_file(List);
                            break;
                        case 4:
                            read_file(List);
                            cout<<endl;
                            show_list(List);
                            break;
                        case 5:
                            find_infor_by_cccd(List);
                            break;
                        case 6:
                            break;

                        case 7:
                            fix_info(List);
                            break;
                        case 8:
                            Tong_Chiet_Khau(List);
                            break;
                        case 9:
                            break;
                        case 0:
                            exit(0);
                            break;
                    }
                }while(chose_1!=0);
            break;

            case 2:
                int chose_2;
                do{
                    int chose_2;
                    cout<< "1.nhap thong tin"<<endl;
                    cout<< "2.xuat thong tin"<<endl;
                    cout<< "3.luu file"<<endl;
                    cout<< "4.doc file"<<endl;
                    cout<< "5.tim thong tin don vi theo id"<<endl;
                    cout<< "6.sua thong tin don vi theo id"<<endl;
                    cout<< "7.xoa thong tin don vi"<<endl;
                    cout<< "8.sap xep theo chi phi"<<endl;
                    cout<< "moi ban chon: ";cin>>chose_2;
                    switch(chose_2)
                    {
                        case 1:
                            input_list_company(List_c);
                            break;
                        case 2:
                            display1(List_c);
                            break;
                        case 3:
                            write_file_company(List_c);
                            break;
                        case 4:
                            read_file_company(List_c);
                            cout<<endl;
                            display1(List_c);
                            break;
                        case 5:
                            find_id_company(List_c);
                            break;
                        case 6:
                            fix_id_company(List_c);
                            break;
                        case 7:
                            remove_id(List_c);
                            display1(List_c);
                            break;
                        case 8:
                            sort_by_cost(List_c);
                            break;

                    }
                }while(chose_2!=0);
                break;
            case 3:
                int chose_3;
                do{

                    cout<< "1.nhap thong tin"<<endl;
                    cout<< "2.xuat thong tin"<<endl;
                    cout<< "3.luu file"<<endl;
                    cout<< "4.doc file"<<endl;
                    cout<< "5.top"<<endl;
                    cout<< "6.ktra rong"<<endl;
                    cout<< "7.lay phan tu dau top: "<<endl;

                    cout<< "moi ban chon: ";cin>>chose_3;
                    switch(chose_3)
                    {
                        case 1:
                            input_stack(s);
                            break;
                        case 2:
                            output_stack(s);
                            break;
                        case 3:
                            //top(s);
                            write_file_stack(l);
                            break;
                        case 4:
                            read_file_nhanvien(l,s);
                            output_stack(s);
                            break;
                        case 5:
                            top(s);
                            break;

                        case 6:
                            if(isEmpty(s)==true)
                                cout<< "danh sach rong"<<endl;
                            else
                                cout<< "danh sach da ton tai phan tu"<<endl;
                            break;

                    }
                }while(chose_3!=0);
                break;
            case 4:
                int chose_4;
                do{
                    //int chose_4;
                    cout<< "1.nhap thong tin"<<endl;
                    cout<< "2.xuat thong tin"<<endl;
                    //cout<< "3.luu file"<<endl;
                    //cout<< "4.doc file"<<endl;
                    cout<< "5.top_eq"<<endl;
                    cout<< "6.push_eq"<<endl;
                    cout<< "7.ktra danh sach rong"<<endl;
                    //cout<< "8.pop_eq"<<endl;
                    cout<< "";
                    cout<< "moi ban chon: ";cin>>chose_4;
                    switch(chose_4)
                    {
                        case 1:
                            nhapds(hopdong);
                            break;
                        case 2:
                            xuatds(hopdong);
                            break;
                        case 3:
                            //top_eq
                            break;
                        case 4:

                            break;
                        case 5:
                            top_eq(hopdong);
                            break;
                        case 6:
                            push_add(hopdong);
                            break;
                        case 7:
                            if(isEmpty_eq(hopdong)==true)
                                cout<< "danh sach rong"<<endl;
                            else
                                cout<< "danh sach da ton tai phan tu"<<endl;
                            break;
                        case 0:
                            exit(0);
                            break;
                    }
                }while(chose_4!=0);
                break;
        }

    }while(chose != 0);
}


int main()
{
    menu();
    return 0;
}
