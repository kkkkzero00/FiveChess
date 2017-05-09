#include <iostream>

#include <Windows.h>


#include "MyStack.h"
#include "ChessInBoard.h"
#include "Hash.h"
#include "Chess.h"


//#include <stack>
using namespace std;

//#define MAX 15
////#define Offset 4
//
//#define OffsetSize 11
//#define Range 2
//#define COUNT 572
//
//#define NONE 0
//#define HUM 1
//#define COM 2
//
//#define Black 1
//#define White 2
//

//1�Ǻ��壬2�ǰ��壬0û������


int main(){
    HWND hwnd = GetForegroundWindow();//��ȡ����ǰ����
    SetWindowTextA(hwnd,"������");//���ô��ڱ���

    int x=500,y=500;
    MoveWindow(hwnd,0,0,x,y,true);//ǿ�ƹ̶���ǰ���ڵ�λ��

	//int i,j;
    bool isBlack = true;
    //���˶�ս������
	int map[MAX][MAX] = {0};
	system("color 70");
    system("mode con cols=60 lines=20");

    Chess chess(15,15);

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

//�����������ȩЩة���


