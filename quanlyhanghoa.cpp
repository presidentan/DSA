/*
    Ho va ten: Ngo Dinh Ngoc An
    Lop: CNTT3_K66
    MSV: 251210795
*/
#include <iostream>   
#include <iomanip>    
#include <string>     
#include <list>       
#include <iterator>   
using namespace std;

class HangHoa{
    private:
        string ma_hang;
        string ten_hang;
        int gia;
        int so_luong;
    public: 
        // Constructor 
        HangHoa(): ma_hang(""), ten_hang(""), gia(0), so_luong(0){};
        HangHoa(string ma, string ten, int gia, int so_luong): ma_hang(ma), ten_hang(ten), gia(gia), so_luong(so_luong){};
        
        // Get
        string get_ma() const {return ma_hang;}
        string get_ten() const {return ten_hang;}
        int get_gia() const {return gia;}
        int get_so_luong() const {return so_luong;}
        
        // Set 
        void set_ma(string ma){this->ma_hang = ma;}
        void set_ten(string ten){this->ten_hang = ten;}
        void set_gia(int gia){this->gia = gia;}
        void set_so_luong(int sl){this->so_luong = sl;}
        
        //operator
        friend istream& operator>> (istream& is, HangHoa& h){
            cout << "Nhap ma hang: ";
            getline(is >> ws, h.ma_hang);
            cout << "Nhap ten hang: ";
            getline(is >> ws, h.ten_hang);
            cout << "Nhap gia: ";
            is >> h.gia;
            cout << "Nhap so luong: ";
            is >> h.so_luong;
            return is;
        } 
        friend ostream& operator<< (ostream& os, const HangHoa& h){
            os << left << setw(10) << h.ma_hang 
               << setw(24) << h.ten_hang
               << right << setw(10) << h.so_luong
               << setw(14) << fixed << setprecision(0) << h.gia;
            return os; 
        }   
        friend bool operator< (const HangHoa& h1, const HangHoa& h2){
            return h1.ma_hang < h2.ma_hang;
        }

        ~HangHoa(){}
};

class DanhSachHangHoa{
    private: 
        int n;
        list<HangHoa> ds_hang_hoa;
    public:
        void Nhap(){
            ds_hang_hoa.clear();
            cout << "Nhap so hang hoa: ";
            cin >> n;
            HangHoa x;
            for (int i = 0; i < n; i++){
                cout << "\nNhap hang hoa so " << i+1 <<":\n";
                cin >> x;
                ds_hang_hoa.push_back(x);
            }
        }
        void Xuat(){
            cout << left << setw(10) << "Ma" << setw(24) << "Ten hang"
                 << right << setw(10) << "So luong" << setw(14) << "Don gia" << '\n';
            cout << string(58, '-') << "\n";
            for (auto i : ds_hang_hoa){
                cout << i << '\n';
            }
        }
        void SapXep(){
            ds_hang_hoa.sort();
        }

        void TimKiem(){
            string TimKiem;
            cout << "\nChon ten hang ban muon tim:  ";
            getline(cin >> ws, TimKiem);
            bool available = false;
            //Kiem tra co hang trung ten khong
            for (HangHoa i: ds_hang_hoa){
                if (i.get_ten() == TimKiem){
                    available = true;
                    break;
                }
            }
            if (!available){
                cout << "Khong ton tai mat hang co ten nay!\n";
            }
            else{
                cout << "Danh sach mat hang ban can tim: \n";
                cout << left << setw(10) << "Ma" << setw(24) << "Ten hang"
                     << right << setw(10) << "So luong" << setw(14) << "Don gia" << '\n';
                cout << string(58, '-') << "\n";
                for (HangHoa i: ds_hang_hoa){
                    if (i.get_ten() == TimKiem){
                        cout << i << '\n';
                    }
                }
            }
        }
        void Xoa(){
            int inp;
            cout << "\nChon mat hang ban muon xoa" << "(0 - " << ds_hang_hoa.size() << "): ";
            cin >> inp;
            auto it = ds_hang_hoa.begin();
            advance(it, inp + 1);
            ds_hang_hoa.erase(it);
            cout << "Da xoa mat hang thu " << inp << "!\n";
        }

        void Them(){
            int inp;
            cout << "\nChon vi tri ban muon them" << "(0 - " << ds_hang_hoa.size() << "): ";
            cin >> inp;
            cout << "\nNhap thong tin mat hang moi:\n";
            HangHoa x;
            cin >> x;
            auto it = ds_hang_hoa.begin();
            advance(it, inp);
            ds_hang_hoa.insert(it, x);
            cout << "Da them mat hang vao vi tri thu " << inp << "!\n";
        }
        ~DanhSachHangHoa(){};
};

class App{
    private:
        DanhSachHangHoa ds;
    public:
        void run(){
            int chon = 1;
            while (chon){
                cout << "\nAPP danh sach mat hang:\n";
                cout << "1. Nhap danh sach mat hang: \n";
                cout << "2. In danh sach mat hang: \n";
                cout << "3. Sap xep danh sach mat hang\n";
                cout << "4. Tim kiem ten mat hang\n";
                cout << "5. Xoa mot mat hang\n";
                cout << "6. Them mot mat hang\n";
                cout << "0. Thoat chuong trinh\n";
                cout << "Lua chon: ";
                cin >> chon;
                switch(chon){
                    case 1:
                        ds.Nhap();
                        break;
                    case 2:
                        ds.Xuat();
                        break;
                    case 3:
                        ds.SapXep();
                        break;
                    case 4:
                        ds.TimKiem();
                        break;
                    case 5:
                        ds.Xoa();
                        break;
                    case 6:
                        ds.Them();
                        break;

                    case 0:
                        cout << "Thoat chuong trinh!\n";
                        break;
                    default:
                        cout << "Lua chon khong hop le! Vui long chon lai.\n";
                }
            }
        }
};

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    App app;
    app.run();
    return 0;
}