#include<bits/stdc++.h>
#include <fstream>
using namespace std;

//Khởi tạo struct phim
struct phim{
    string tenphim;
    string tendaodien;
    int namsx;
    string hangsx;


};

//khỏi tạo node phim
struct Nodepp{
   phim infor;
   struct Nodepp*next;


};
//khởi tạo node đầu cuối
struct Listb{
    int sl;
    Nodepp*Head;
    Nodepp*Tail;
};
    //Khai báo list
    Listb x;

// hàm nhập 1 phim co ban

void nhap(phim&x){
    fflush(stdin);
    cout<<"\nNhap ten phim: ";
    getline(cin,x.tenphim);
    cout<<"\nNhap ten dao dien: ";
    getline(cin,x.tendaodien);
    cout<<"\nNhap hang san xuat : ";
    getline(cin,x.hangsx);
    cout<<"\nNhap nam san xuat: ";
    fflush(stdin);
    cin>>x.namsx;
    fflush(stdin);
}

//ham hien 1 phim co ban
void hien(phim&x){
    cout<<"\n"<<setw(19)<<x.tenphim<<setw(19)<<x.tendaodien<<setw(19)<<x.namsx<<setw(19)<<x.hangsx;

}



///khơi tạo node (tro);

Nodepp*getNodepp(phim x){
    Nodepp*p;
    p=new Nodepp();
    //kiem tra null
    if(p==NULL){
        cout<<"khong thanh cong";
        exit(0);
    }
    //thoat
    p->infor=x;
    p->next=NULL;
    return p;
}

//Tao con trỏ
void trophim(Listb& Q){
   Q.Head=NULL;
   Q.Tail=NULL;
}

//chèn cuối
  void chencuoitp(Listb &Q,Nodepp *p)
{

    if(Q.Head == NULL)
    {
        Q.Head = p;
        Q.Tail = Q.Head;
    }
    else
    {
        Q.Tail->next=p;
        Q.Tail = p;
    }
}
//Chèn đầu
void chendautp(Listb&Q,Nodepp*p){
    if(Q.Head==NULL){
        Q.Head=p;
        Q.Tail=Q.Head;

    }
    else{
        p->next=Q.Head;
        Q.Head=p;

    }

}




//Chèn vị trí bất kì
void chenvitribk(Listb& Q, Nodepp* p,Nodepp* x)
{

	if (x != NULL)
	{
		p->next = x->next;
		x->next = p;
		if (Q.Tail == x)
			Q.Tail = p;
	}
	else
		chendautp(Q,p);
}

//Tìm node
Nodepp*tim(Listb&Q,phim x){
Nodepp*p;
string a;
fflush(stdin);
cout<<"\nNhap ten phim can tim: ";
getline(cin,a);
for(p=Q.Head;p!=NULL;p=p->next){
    if(p!=NULL&&(p->infor.tenphim==a)){
        break;
    }

}
return p;

}
//Nhap ds phim
void nhapdsp(Listb &Q)
{
    Nodepp *p;
    phim x;
    int n;
    cout<< "\nNhap so phim : ";
    fflush(stdin);
    cin>>Q.sl;
    for(int i=0; i< Q.sl; i++)
    {
        cout<<"\n-------------------------------";
        nhap(x);
        p = getNodepp(x);
        chencuoitp(Q,p);
    }
}
//in danh sach phim
void indsp(Listb&Q){
    Nodepp*p;
    cout<<"\n"<<setw(19)<<"Ten phim"<<setw(19)<<"Ten DD"<<setw(19)<<"Nam sx"<<setw(19)<<"hang sx";
    for(p=Q.Head;p!=NULL;p=p->next){
        hien(p->infor);
    }

}

//Thêm đầu
void  themdau(Listb & Q ){
    Nodepp*p;
    bool kt;
    kt=false;
    phim x;
    nhap(x);
    for(p=Q.Head;p!=NULL;p=p->next){
        if(p->infor.tenphim==x.tenphim){
            kt=true;
            break;
        }

    }
    if(kt==true){
        cout<<"\nTen phim da ton tai: !!!!";

    }
    else{
    p=getNodepp(x);

    chendautp(Q,p);
    }
}


//Thêm cuối
void  themcuoi(Listb & Q ){
    Nodepp*p;
    bool kt;
    kt=false;
    phim x;
    nhap(x);
    for(p=Q.Head;p!=NULL;p=p->next){
        if(p->infor.tenphim==x.tenphim){
            kt=true;
            break;
        }

    }
    if(kt==true){
        cout<<"\nTen phim da ton tai: !!!!";

    }
    else{
    p=getNodepp(x);
    chencuoitp(Q,p);
    }

}
void  themvitribk(Listb & Q ){
    Nodepp*p;
    bool kt;
    kt=false;
    phim x;


    nhap(x);

    for(p=Q.Head;p!=NULL;p=p->next){
        if(p->infor.tenphim==x.tenphim){
            kt=true;
            break;
        }

    }
    Nodepp*a;
    if(kt==true){
        cout<<"\nTen phim da ton tai: !!!!";
    }

    else{
            a=tim(Q,x);
    p=getNodepp(x);
    chenvitribk(Q,p,a);
    }


}


int them(Listb&Q){
    int chon,chon1,chon2;
    fflush(stdin);
    do{
            indsp(Q);
        cout<<"\n------------------------Muc Them----------------------------";
        cout<<"\n1.Them 1 phim                                               ";
        cout<<"\n2.Them nhieu phim                                           ";
        cout<<"\n0.Thoat                                                     ";
        cout<<"\n------------------------------------------------------------";
        cout<<"\nMoi ban chon: ";
        cin>>chon;
        switch(chon){
            case 1:
              do{
                  indsp(Q);
                    cout<<"\n-----------------------Them vi tri--------------------------";
                    cout<<"\n1.Vi tri dau                                                ";
                    cout<<"\n2.Vi tri bat ki x                                           ";
                    cout<<"\n3.Vi tri cuoi                                               ";
                    cout<<"\n0.Thoat                                                     ";
                    cout<<"\n------------------------------------------------------------";

              cout<<"\nMoi ban chon: ";
              cin>>chon1;
              switch(chon1){
                    case 1:
                        themdau(Q);
                        indsp(Q); break;
                    case 2:
                        themvitribk(Q);
                        indsp(Q); break;
                    case 3:
                        themcuoi(Q);
                        indsp(Q); break;
              }
                    system("pause");
                    system("cls");
              }while(chon1!=0);
              cout<<endl;
              break;
            case 2:
                int n;
                    cout<<"\nNhap so luong muon them: ";
                    cin>>n;
              do{indsp(Q);
                cout<<"\n-----------------------Them vi tri--------------------------";
              cout<<"\n1.Vi tri dau                                                ";
              cout<<"\n2.Vi tri bat ki x                                           ";
              cout<<"\n3.Vi tri cuoi                                               ";
              cout<<"\n0.Thoat                                                     ";
              cout<<"\n------------------------------------------------------------"<<endl;

              cout<<"\nMoi ban chon: ";
              fflush(stdin);
              cin>>chon2;
              switch(chon2){
                case 1:
                    for(int i=0;i<n;i++){
                        themdau(Q);

                    }
                    indsp(Q); break;
                case 2:
                    for(int i=0;i<n;i++){
                        themvitribk(Q);

                    }
                    indsp(Q); break;
                case 3:
                    for(int i=0;i<n;i++){
                        themcuoi(Q);
                    }
                    indsp(Q); break;
              }system("pause");
                system("cls");
              }while(chon2!=0);
              cout<<endl;
              break;
               }
    }while(chon!=0);
    cout<<endl;

}

// xóa đầu

void XoaDau(Listb &Q){
    Nodepp*p=Q.Head;
    Q.Head=Q.Head->next;
    p->next=NULL;
    delete p;
    indsp(Q);
}

//xóa cuối
void XoaCuoi(Listb &Q){

    for(Nodepp*p=Q.Head;p!=NULL;p=p->next){
        if(p->next==Q.Tail){
            delete Q.Tail;
            p->next=NULL;
            Q.Tail=p;
        }
    }

}


//xóa vị trí sau Q
void xoavitribatkik(Listb&Q){
    string x;
    cout<<"\nNhap ten phim xoa: ";
    fflush(stdin);
    getline(cin,x);
    fflush(stdin);
    Nodepp*p=new Nodepp;
    bool kt=false;
    if(Q.Head->infor.tenphim==x){
        XoaDau(Q);
        kt=true;
        return;
    }
    if(Q.Tail->infor.tenphim==x){
        XoaCuoi(Q);
        kt==true;
        return;
    }
    for(Nodepp*k=Q.Head;k!=NULL;k=k->next){
                    if(k->infor.tenphim==x){
                    p->next=k->next;
                    delete k;
                    kt=true;
                    }
                    p=k;
                }

      if(kt==false){
        cout<<"Danh sach sau khi xoa la: ";
        indsp(Q);
      }
      else if(kt==true){
        cout<<"Phan tu xoa khong co trong danh sach";
      }
    }


//xoa vi tri sau k
void xoavitrisauk(Listb&Q){
    string x;
    cout<<"\nNhap ten phim truoc phim xoa: ";
    fflush(stdin);
    getline(cin,x);
    fflush(stdin);
    Nodepp*p=new Nodepp;
    bool kt=false;
    if(Q.Head->infor.tenphim==x){
        XoaDau(Q);
        kt=true;
        return;
    }
    if(Q.Tail->infor.tenphim==x){
        XoaCuoi(Q);
        kt==true;
        return;
    }



                for(Nodepp*k=Q.Head;k!=NULL;k=k->next){
                    if(k->infor.tenphim==x){
                    p->next=k->next;
                    delete k->next;
                    kt=true;
                    }
                    p=k;break;
                }


      if(kt==false){
        cout<<"Danh sach sau khi xoa la: ";
        indsp(Q);
      }
      else if(kt==true){
        cout<<"Phan tu xoa khong co trong danh sach";
      }
    }
    void xoatoanbo(Listb&Q){
        while(Q.Head !=NULL)
        XoaCuoi(Q);
    }

void xoa(Listb&Q){
    int chon;
    do{
            indsp(Q);
        cout<<"\n-------------------------------MENU XOA---------------------------";
        cout<<"\n1.Xoa dau                                                         ";
        cout<<"\n2.Xoa vi tri xac dinh k                                           ";
        cout<<"\n3.Xoa vi tri sau K                                                ";
        cout<<"\n4.Xoa cuoi                                                        ";
        cout<<"\n5Xoa toan bo                                                      ";
        cout<<"\n0.Thoat                                                           ";
        cout<<"\n------------------------------------------------------------------";
        cout<<"\nNhap su lua chon: ";
        cin>>chon;
        switch(chon){
            case 1:
                XoaDau(Q);break;
            case 2:
                xoavitribatkik(Q);break;
            case 3:
                xoavitrisauk(Q);break;

            case 4:
                XoaCuoi(Q);break;
            case 5:
                xoatoanbo(Q);break;
        }
                system("pause");
                system("cls");
    }while(chon!=0);
}
//sap xep theo nam
void sapxeptheonam(Listb&Q){
    Nodepp*p;
    Nodepp*q;
    for(p=Q.Head;p!=NULL;p=p->next){
        Nodepp*Min=p;
        for(q=p->next;q!=NULL;q=q->next){
            if(p->infor.namsx>Min->infor.namsx){
                Min=q;
            }
        }
        if(p->infor.tenphim!=Min->infor.tenphim){
            swap(p->infor,Min->infor);
        }
    }

}
//sap xep theo ten;
void sapxeptheoten(Listb&Q){
    Nodepp*q;
    Nodepp*p;
    for(p=Q.Head;p!=NULL;p=p->next){
        for(q=p->next;q!=NULL;q=q->next){
            if(p->infor.tenphim>q->infor.tenphim){
                swap(p->infor,q->infor);
            }
        }
    }
}

void sapxep(Listb&Q){
    int chon;
    do{
            indsp(Q);
        cout<<"\n--------------------------------MenuSapxep----------------------------";
        cout<<"\n1.Sap xep nam tang dan(chon)                                          ";
        cout<<"\n2.Sap xep ten tang dan(tuantu)                                        ";
        cout<<"\n3.thoat                                                               ";
        cout<<"\n----------------------------------------------------------------------";
        fflush(stdin);
        cout<<"\nNhap su lua chon: ";
        cin>>chon;
        switch(chon){
            case 1:
                sapxeptheonam(Q);break;
            case 2:
                sapxeptheoten(Q);break;
        }
                system("pause");
                system("cls");
    }while(chon!=3);
}

//Tìm đầu
void timdau(Listb&Q){
     Nodepp*p=Q.Head;
     cout<<"\nPhim o dau danh sach la: ";
    cout<<"\n"<<setw(19)<<"Ten phim"<<setw(19)<<"Ten DD"<<setw(19)<<"Nam sx"<<setw(19)<<"hang sx";
    hien(p->infor);
}
void timcuoi(Listb&Q){
     Nodepp*p=Q.Tail;
     cout<<"\nPhim o cuoi danh sach la: ";
    cout<<"\n"<<setw(19)<<"Ten phim"<<setw(19)<<"Ten DD"<<setw(19)<<"Nam sx"<<setw(19)<<"hang sx";
    hien(p->infor);
}
void timbatki(Listb&Q){
    Nodepp*p;
    string s;
    cout<<"\nNhap ten phim can tim s :";
    fflush(stdin);
    getline(cin,s);
    cout<<"\nPhim can tim la:   ";
     cout<<"\n"<<setw(19)<<"Ten phim"<<setw(19)<<"Ten DD"<<setw(19)<<"Nam sx"<<setw(19)<<"hang sx";
    for(p=Q.Head;p!=NULL;p=p->next){
        if(p->infor.tenphim==s){
            hien(p->infor);
        }
    }
}
void timmax(Listb&Q){
    Nodepp*p;
    Nodepp*Max=Q.Head;
    for(p=Q.Head;p!=NULL;p=p->next){
        if(p->infor.namsx>Max->infor.namsx){
            Max=p;
        }
    }
    cout<<"\nNam san suat gan day nhat: "<<Max->infor.namsx;
}
void daphuongtien(Listb&Q){
    int chon;
    do{
            cout<<"\n------------------Muc Khac-------------------";
            cout<<"\n1.Tim dầu danh sach                          ";
            cout<<"\n2.Tim cuoi danh sach                         ";
            cout<<"\n3.Tim tat ca                                 ";
            cout<<"\n4.Tim bat ki                                 ";
            cout<<"\n5Tim max(min vs den tuong tu                 ";
            cout<<"\n0.Thoat                                      ";
            cout<<"\n---------------------------------------------";
            switch(chon){
            case 1:
                timdau(Q);break;
            case 2:
                timcuoi(Q);break;
            case 3:
                indsp(Q);break;
            case 4:
                timbatki(Q);break;
            case 5:
                timmax(Q);break;
            }
            system("pause");
                system("cls");


    }while(chon!=0);
}
void luufile(Listb&Q){
    Nodepp*p=Q.Head;
    ofstream fo;
    fo.open("phim.txt",ios::out);
    fo<<x.sl<<endl;
    while(p!=NULL){
            phim k=p->infor;
            fo<<k.tenphim<<"\n"
            <<k.tendaodien<<
            "\n"<<k.hangsx<<"n";
          // "\n"k.namsx<<"\n";
            p=p->next;
    }
    fo.close();
}
void docfile(Listb &Q){
    indsp(Q);
    ifstream fi;
    fi.open("phim.txt",ios::in);
    int n;
    fi>>n;
    string s;
    fflush(stdin);
    getline(fi,s);
    for(int i=0;i<n;i++){
            phim x;
        getline(fi,x.tenphim);
        getline(fi,x.tendaodien);
        //getline(fi,x.namsx);
        getline(fi,x.hangsx);
        Nodepp *p = getNodepp(x);
        chencuoitp(Q,p);
    }
    x.sl=n;
    fi.close();

}
int main(){
    nhapdsp(x);
    indsp(x);
    them(x);
    xoa(x);
    sapxep(x);
    timdau(x);
    timcuoi(x);
    timbatki(x);
    timmax(x);
    luufile(x);

}








