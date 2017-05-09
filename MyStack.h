#ifndef MYSTACK_H
#define MYSTACK_H
#define MAX 15
#include "ChessInBoard.h"

class MyStack{
public:
    MyStack(int size=MAX*MAX);
    ~MyStack();
    bool stackEmpty();
    bool stackFull();
    void clearStack();
    int stackLength();
    bool push(ChessInBoard elem);
    bool pop(ChessInBoard &elem);
    void stackTraverse(bool isFromTop=false);
    ChessInBoard getElement(int i);
private:
    ChessInBoard *arr;//ָ��ջ�ռ�
    int m_iSize;//ջ����
    int m_iTop;//ջ����ջԪ�ظ���
};

#endif // MYSTACK_H
