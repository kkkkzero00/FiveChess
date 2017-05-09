#include <iostream>
#include <Windows.h>
#include "Chess.h"
#include "HumVsHum.h"

using namespace std;
//POINT point = { 0,0 };//�����ͱ�����������ȡ���λ��
void setSystemWindow(){
    HWND hwnd = GetForegroundWindow();//��ȡ����ǰ����
    SetWindowTextA(hwnd,"������");//���ô��ڱ���

    int x=500,y=500;
    MoveWindow(hwnd,0,0,x,y,true);//ǿ�ƹ̶���ǰ���ڵ�λ��

    system("color 70");
    system("mode con cols=60 lines=20");
}

int main(){

    setSystemWindow();
    //���˶�ս������
	int map[MAX][MAX] = {0};

    int type = 0;
    int level = 0;
    int board = 0;
    cout<< "��ѡ���ս��ʽ 1�����˶�ս 2���˻���ս" << endl;
    cin>>type;

    if(type==1){
        system("cls");
        HumVsHum hum;

        while(true){
            if(hum.isOver){
                if(hum.isBlackWin){
                    cout<<"�ڷ�ʤ����"<<endl;
                }else if(hum.isWhiteWin){
                    cout<<"�׷�ʤ����"<<endl;
                }else{
                    cout<<"ƽ��"<<endl;
                }
                break;
            }

            hum.put();
            system("cls");
            hum.showMap();
            Sleep(1000);
        }
    }else if(type==2){

        cout<< "��ѡ�����̴�С����15����15*15" << endl;
        cin>>board;
        cout<< "��ѡ���Ѷ� 1:���ּ���2����ͨ����3�����Ѽ���4�����޼�" << endl;
        cin>>level;
        system("cls");

        Chess chess(board,board,level);

        while(true){

            if(chess.isOver)break;

            if(chess.isHum){
                 chess.humPut();

                if(chess.isHumWin()){
                    chess.isOver = true;
                    cout<< "����Ӯ��!" << endl;
                    break;
                }
                chess.isHum = false;

            }else{
                chess.computerAI();

                if(chess.isComWin()){
                    chess.isOver = true;
                    cout<< "����Ӯ��!" << endl;
                    //chess.showMap();
                    break;
                }
                chess.isHum = true;

            }

            system("cls");
            chess.showMap();
            Sleep(1000);
        }
    }

    return 0;
}




