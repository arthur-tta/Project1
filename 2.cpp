#include <bits/stdc++.h>
#include <conio.h>
#include <vector>

using namespace std;

struct NhanVien
{   
    string manv;
    string hovaten;
    string namsinh;
    string chucdanh;
    double hsluong;
    long phucap;
    long luong;
    long tongluong;
    long congdoan;
};

struct PhongBan
{
    string ten;
    string diachi;
    int soluongnv;
    long luongtoithieu;
    vector<NhanVien> dsnhanvien;
    long tongluong;
    long tongcdphi;

};

int n; // so luong phong ban
int i = 1; // so luong phong ban hien tai
vector<PhongBan> dsphongban;

void input(){
    cout << endl;
    cout << "Ban da chon nhap danh sach phong ban nhan vien!" << endl;
    PhongBan t;
    while(i <= n){
        t.tongluong = 0;
        t.tongcdphi = 0;
        i++;
        cout << "\tTen Phong Ban: ";
        fflush(stdin);
        getline(cin, t.ten);
        cout << endl;
        cout << "\tDia Chi: ";
        fflush(stdin);
        getline(cin, t.diachi);
        cout << endl;
        fflush(stdin);
        cout << "\tLuong toi thieu: ";
        cin >> t.luongtoithieu;
        cout << endl;
        cout << "\tSo nhan vien: ";
        cin >> t.soluongnv;
        cout << "\tNhap ds Nhan Vien:" << endl;
        for(int j = 1; j <= t.soluongnv; j++){
            cout << "\tNhan vien thu " << j << endl;
            long luong = 0;
            NhanVien t2;
            cout << "\t\tMaNV: ";
            cin >> t2.manv;
            cout << endl;
            cout << "\t\tHo ten Nhan vien: ";
            fflush(stdin);
            getline(cin, t2.hovaten);
            cout << endl;
            cout << "\t\tNhap Nam sinh: ";
            cin >> t2.namsinh;
            cout << endl;
            cout << "\t\tNhap HS Luong: ";
            cin >> t2.hsluong;
            cout << endl;
            cout << "\t\tNhap chuc danh: ";
            cin >> t2.chucdanh;
            cout << endl;
            if(t2.chucdanh == "GVCC"){
                t2.phucap = 2000;
            }else if (t2.chucdanh == "GVC"){
                t2.phucap = 1500;
            }else if (t2.chucdanh == "GV"){
                t2.phucap = 1000;
            }else if (t2.chucdanh == "CBKT"){
                t2.phucap = 750;
            }else if (t2.chucdanh == "CBHC"){
                t2.phucap = 500;
            }
            t2.tongluong = t2.hsluong * t.luongtoithieu + t2.phucap;
            t2.luong = t2.tongluong * 0.99;
            t2.congdoan = t2.tongluong * 0.01;
            t.dsnhanvien.push_back(t2);
            t.tongcdphi += t2.congdoan;
            t.tongluong += t2.tongluong;
        }

        dsphongban.push_back(t);
        cout << endl;
        cout << "Ban da nhap thanh cong!" << endl;
        cout << "Nhan phim bat ky de tiep tuc!" << endl;
        cout << endl;
        getch();
    }
}

void output(){
    cout << endl;
    cout << "Ban da chon xuat DS Phong ban!" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    for(auto i = dsphongban.begin(); i != dsphongban.end(); i++){
        cout << "\tTen phong ban: " << (*i).ten << endl;
        cout << "\tDia chi: " << (*i).diachi << endl;
        cout << "\tLuong TT: " << (*i).luongtoithieu << endl;
        cout << "\tTong luong PB: " << (*i).tongluong << endl;
        cout << "\tTong CD phi: " << (*i).tongcdphi<< endl;
        cout << "\tBang Luong Nhan Vien:" << endl;
        cout << "\t";
        cout << setw(20) << left << "MaNV";
        cout << setw(20) << left << "HotenNV";
        cout << setw(20) << left << "Chucdanh";
        cout << setw(20) << left << "PCCV";
        cout << setw(20) << left << "HesoL";
        cout << setw(20) << left << "Luong";
        cout << setw(20) << left << "CDP";
        cout << setw(20) << left << "Con nhan";
        cout << endl;
        for(auto j = (*i).dsnhanvien.begin(); j != (*i).dsnhanvien.end(); j++){
            cout << "\t";
            cout << setw(20) << left << (*j).manv;
            cout << setw(20) << left << (*j).hovaten;
            cout << setw(20) << left << (*j).chucdanh;
            cout << setw(20) << left << (*j).phucap;
            cout << setw(20) << left << (*j).hsluong;
            cout << setw(20) << left << (*j).tongluong;
            cout << setw(20) << left << (*j).congdoan;
            cout << setw(20) << left << (*j).luong;
            cout << endl;
        }
        cout << endl;       
    }
    cout << "------------------------------------------------------------------------------------------";
    cout << endl;
    cout << "Nhan phim bat ki de tiep tuc!";
    cout << endl;
    getch();
}



int main(){
    cout << "De3_7_IT3040_20211" << endl;
    cout << "Lai Anh Duy -20194036 - Ma lop 710816" << endl;
    cout << "Nhap so phong ban: ";
    cin >> n;
    int choose;
    while(true){
         cout << endl;
        cout << "Lai Anh Duy -20194036 - Ma lop 710816" << endl;                     
        cout << "**    CHUONG TRINH QUAN PHONG BAN - NV   **" << endl;
        cout << "** 1. Nhap cac phong ban                 **" << endl;
        cout << "** 2. In ra ds cac phong ban va nhan vien**" << endl;
        cout << "** 0. Thoat chuong trinh                 **" << endl;
        cout << "*******************************************" << endl;
        cout << "**          Nhap lua chon cua ban        **" << endl;
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