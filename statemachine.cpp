#include <string>
#include <unordered_map>
#include <functional>
#include <iostream>

using namespace std;


//---------------״̬���ܹ���ʼ----------------------
typedef int eState;
eState NullState = -1;

class FSM;

// ״̬�Ļ���
class State
{
public:
    virtual void OnStateEnter() = 0;
    virtual void OnStateTick() = 0;
    virtual void OnStateExit() = 0;

    State(FSM* _fsm)
    {
        fsm = _fsm;
    }
protected:
    FSM* fsm = nullptr;
};

// ״̬����ͳ������״̬
class FSM
{
private:
    unordered_map<eState, State*> all_states;
    eState curState = -1;

public:
    // ע���µ�״̬
    bool Register(eState e, State* pState)
    {
        all_states[e] = pState;
        return true;
    }
    // ��Ҫ״̬ת������ô˺���
    bool Trans(eState newState)
    {
        all_states[curState]->OnStateExit();

        all_states[newState]->OnStateEnter();
        curState = newState;
        return true;
    }
    // ���ó�ʼ״̬
    void SetInitState(eState s)
    {
        curState = s;
    }
    // ÿ֡����
    void Tick()
    {
        all_states[curState]->OnStateTick();
    }
};

// -----------------ʵ��ʹ�����ӿ�ʼ-----------------
const int State_Idle = 1;
const int State_Attack = 2;
const int State_GoHome = 3;

// ʵ��Ӧ�ã������������״̬������State�̳У�Ȼ��ֱ�ʵ���Լ���Enter��Tick��Exit����

class StateIdle : public State
{
public:
    StateIdle(FSM* fsm) : State(fsm)
    {
    }

    int test_counter = 0;

    void OnStateEnter()
    {
        cout << "---- Idle Enter" << endl;
        test_counter = 0;
    }

    void OnStateTick()
    {
        cout << "Idle Tick" << endl;
        // ģ��һ����ʱ״̬ת�ơ���ʵ�ʹ������Ǹ��������߼�д��
        test_counter++;
        if ( test_counter == 5 )
        {
            fsm->Trans(State_Attack);
        }
    }

    void OnStateExit()
    {
        cout << "==== Idle Exit" << endl;
    }
};

class StateAttack : public State
{
public:
    StateAttack(FSM* fsm) : State(fsm)
    {
    }

    void OnStateEnter()
    {
        cout << "---- Attack Enter" << endl;
    }

    void OnStateTick()
    {
        cout << "Attack Tick" << endl;
        fsm->Trans(State_GoHome);
    }

    void OnStateExit()
    {
        cout << "==== Attack Exit" << endl;
    }
};

class StateGoHome : public State
{
public:
    StateGoHome(FSM* fsm) : State(fsm)
    {
    }

    void OnStateEnter()
    {
        cout << "---- GoHome Enter" << endl;
    }

    void OnStateTick()
    {
        cout << "GoHome Tick" << endl;
        fsm->Trans(State_Idle);
    }

    void OnStateExit()
    {
        cout << "==== GoHome Exit" << endl;
    }
};

int statemachinemain()
{
    // ����״̬��
    FSM* fsm = new FSM();
    State* stateIdle = new StateIdle(fsm);
    State* stateAttack = new StateAttack(fsm);
    State* stateGoHome = new StateGoHome(fsm);

    fsm->Register(State_Idle, stateIdle);
    fsm->Register(State_Attack, stateAttack);
    fsm->Register(State_GoHome, stateGoHome);
    fsm->SetInitState(State_Idle);

    // ��״̬��Tick���������ѭ����, ��ʾ��
    while ( true )
    {
        fsm->Tick();
    }

    return 0;
}