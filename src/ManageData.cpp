#include "Object.h"
#include "AddData.h"
#include "ModifyData.h"
#include "DeleteData.h"
//--------------THAO TAC QUAN LY THONG TIN KHACH HANG--------------

void ManageCustomer(LIST &l, LIST &tmp){
    while(1){
        system("cls");
        cout<<"\n\t\t=================TUY CHON===================";
        cout<<"\n\t\t|  1. In thong tin Khach hang ra man hinh  |";
        cout<<"\n\t\t|  2. In thong tin Khach hang ra FILE      |";
        cout<<"\n\t\t|  3. Xoa thong tin Khach hang trong FILE  |";
        cout<<"\n\t\t|  4. Sua thong tin Khach hang trong FILE  |";
        cout<<"\n\t\t|  0. Thoat chuong trinh                   |";
        cout<<"\n\t\t============================================";
        cout<<"\n\t\tNhap lua chon: ";
        string choice1;
        cin>>choice1;
        if(choice1 == "0"){
            return;
        }
        else if(choice1 == "1"){
            tmp.XuatDS();
            system("pause");
        }
        else if(choice1 == "2"){
            ofstream FileOut;
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, tmp);
            cout<<"\t\tIn FILE thanh cong\n\t\t";
            system("pause");
            FileOut.close();
        }
        else if(choice1 == "3"){
            ofstream FileOut;
            NODE *q = tmp.pHead;
            while(q != NULL){
                XoaInfo(l, q);
                q = q->pNext;
            }
            FileOut.open("data.txt", ios::out);
            XuatDSInFoRaFile(FileOut, l);
            FileOut.close();
            cout<<"\t\tDa xoa thong tin Khach hang\n\t\t";
            system("pause");
            return;
        }
        else if(choice1 == "4"){
            SuaInfo(l, tmp);
        }
        else{
            cout<<"\t\tBan da nhap sai cu phap\n\t\t";
            system("pause");
        }
    }    
}