#include"aboutme.h"

void aboutMe()
{
    string aboutme;
    aboutme+="Xin moi ban den voi game xe tang 2D\n";
    aboutme+="Den voi game cua chung toi ban se duoc tan huong nhung phut giay thoai mai\n";
    aboutme+="Hay cung tieu diet nhung biet doi xe tang may hung ac nao cac ban\n";
    aboutme+="Sau day la cach choi:\n";
    aboutme+="-Nhan phim len xuong trai phai de dieu khien xe tang\n";
    aboutme+="-Nhan phim SPACE de ban\n";
    aboutme+="-Ban se danh chien thang neu nhu tieu diet het toan bo so xe tang may\n";
    aboutme+="Con neu khong thi ...................................................\n";
    aboutme+="Ban tu biet roi day\n\n";
    aboutme+="Chuc ban choi game vui ve";
    for(int i=0;i<aboutme.size();i++){
            TextColor(14);
            cout<<aboutme[i];
            Sleep(100);}
}
