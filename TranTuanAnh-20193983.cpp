#include <bits/stdc++.h>
#include <conio.h>
#include <vector>



using namespace std;

struct SanPham
{
    string masp;
    string tensp;
    int soluong;
    double dongia;
    double thanhtien;
    double tiengiam;
};

struct PhieuNhap
{
    string tennhacungcap;
    int ngay;
    int thang;
    int nam;
    int sosp;
    double sotiendathanhtoan;
    double sotienphaithanhtoan;
    double tonggiam;
    vector<SanPham> dssanpham;
    double tienthua;
};

int n;  // so luong sinh vien toi da
int i;  // so luong sinh vien hien tai trong danh sach
vector<PhieuNhap> dsphieunhap;
double tongtiendathanhtoan = 0;
double tongtienphaithanhtoan = 0;
double tongtiengiam = 0.0;
double tongtienthua = 0;


void input(){
    cout << endl;
    cout << "Ban da chon nhap ds Phieu Nhap SP!" << endl;
    PhieuNhap temp;
    
    for(i = 1; i <= n; i++){
        temp.tonggiam = 0;
        temp.sotienphaithanhtoan = 0;
        temp.sotiendathanhtoan = 0;
        cout << "Nhap thong tin Phieu Nhap " << i << " : " << endl;
        cout << "\tTen Nha Cung Cap: ";
        fflush(stdin);
        getline(cin, temp.tennhacungcap);
        cout <<"\n\tNgay: ";
        cin >> temp.ngay;
        cout <<"\n\tThang: ";
        cin >> temp.thang;
        cout <<"\n\tNam: ";
        cin >> temp.nam;
        cout <<"\n\tSo San Pham: ";
        cin >> temp.sosp;
        cout << "\tNhap ds san pham:" << endl;
        for(int j = 1; j <= temp.sosp; j++){
            SanPham s;
            cout << "\tSan Pham " << j << endl;
            cout << "\t\tMa so SP: ";
            cin >> s.masp;
            cout << "\t\tTen San Pham: ";
            fflush(stdin);
            getline(cin, s.tensp);
            cout << "\t\tSo Luong Sp: ";
            cin >> s.soluong;
            cout << "\t\tDon da nhap: ";
            cin >> s.dongia;
            s.thanhtien = s.soluong * s.dongia;
            if(s.soluong < 10){
                s.tiengiam = 0;
            }else if(s.soluong < 50){
                s.tiengiam = 0.01 * s.thanhtien;
            }else if(s.soluong < 100){
                s.tiengiam = 0.02 * s.thanhtien;
            }else if(s.soluong < 200){
                s.tiengiam = 0.025 * s.thanhtien;
            }else if(s.soluong < 500 ){
                s.tiengiam = 0.03 * s.thanhtien;
            }
            temp.tonggiam += s.tiengiam;
            temp.sotienphaithanhtoan += s.thanhtien;
            temp.dssanpham.push_back(s);
        }
        cout <<"\n\tSo tien da thanh toan: ";
        cin >> temp.sotiendathanhtoan;
        temp.tienthua = temp.sotiendathanhtoan - temp.sotienphaithanhtoan + temp.tonggiam;
        tongtienphaithanhtoan += temp.sotienphaithanhtoan;
        tongtiendathanhtoan += temp.sotiendathanhtoan;
        tongtiengiam += temp.tonggiam;
        tongtienthua += temp.tienthua;
        dsphieunhap.push_back(temp); 
        temp.dssanpham.clear();

    }
    cout << endl;
    cout << "Ban da nhap thanh cong!" << endl;
    cout << "Nhan phim bat ky de tiep tuc!" << endl;
    cout << endl;
    getch();
}

void output(){
    cout << endl;
    cout << "Ban da chon xuat Phieu Nhap!" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    for(auto i = dsphieunhap.begin(); i != dsphieunhap.end(); i++){
        cout << "\tTen nha cung cap: " << (*i).tennhacungcap << endl;
        cout << "\tNgay thu: Ngay " << (*i).ngay << " thang " << (*i).thang << " nam " << (*i).nam << endl;
        cout << "\tSo san pham: " << (*i).sosp << endl;
        cout << "\tTong da thanh toan: " << (*i).sotiendathanhtoan << endl;
        cout << "\tTong phai thanh toan: " << (*i).sotienphaithanhtoan << endl;
        cout << "\tTong tien giam " << (*i).tonggiam << endl;
        if((*i).tienthua < 0){
            cout << "\tChua thanh toan " << -(*i).tienthua << endl;
        }else{
             cout << "\tTong tien thua " << (*i).tienthua << endl;
        }
        
        cout << "\t\tChi tiet cac san pham:" << endl;
        cout << "\t";
        cout << setw(20) << left << "Masp";
        cout << setw(20) << left << "Tensanppham";
        cout << setw(20) << left << "Dongia";
        cout << setw(20) << left << "Soluong";
        cout << setw(20) << left << "Thanhtien";
        
        cout << setw(20) << left << "Tiengiam";
        cout << endl;
        for(auto j = (*i).dssanpham.begin(); j != (*i).dssanpham.end(); j++){
            cout << "\t";
            cout << setw(20) << left  << (*j).masp;
            cout << setw(20) << left  << (*j).tensp;
            cout << setw(20) << left  << (*j).dongia;
            cout << setw(20) << left  << (*j).soluong;
            cout << setw(20) << left  << (*j).thanhtien;
            cout << setw(20) << left  << (*j).tiengiam;
            cout << endl;
        }
        cout << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
    }

    cout << "Tong phai thanh toan cac phieu nhap: " << tongtienphaithanhtoan << endl;
    cout << "Tong da thanh toan cac phieu nhap: " << tongtiendathanhtoan << endl;
    cout << "Tong duoc giam cua cac phieu nhap: " << tongtiengiam << endl;
    if(tongtienthua > 0){

        cout << "Tong tien thua: " << tongtienthua << endl;
    }else{
        cout << "Tong chua thanh toan: " << -tongtienthua << endl;
    }
    cout << "Nhan phim bat ki de tiep tuc!";
    cout << endl;
    getch();
}



int main(){
    cout << "Tran Tuan Anh - 20193983 - 710820" << endl;
    cout << "Nhap so Phieu Nhap: ";
    cin >> n;
    int choose;
   
   
    while (true){
        cout << endl;
        cout << "Tran Tuan Anh - 20193983 - 710820" << endl;                     
        cout << "**  CHUONG TRINH QUAN LY NHA CC   **" << endl;
        cout << "** 1. Nhap Nha CC Phieu Nhap      **" << endl;
        cout << "** 2. In Ket Qua Phieu Nhap       **" << endl;
        cout << "** 0. Thoat chuong trinh          **" << endl;
        cout << "************************************" << endl;
        cout << "**      Nhap lua chon cua ban     **" << endl;
        cin >> choose;
        switch (choose){
        case 0:
            cout << "Ban da chon thoat chuong trinh!";
            getch();
            return 1;
        case 1:
            input();
            break;
        case 2:
            output();
            break;
        default:
            break;
        }
    }
    
    
}
