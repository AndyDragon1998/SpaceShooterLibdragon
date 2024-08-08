#ifndef STATE_MANAGER
#define STATE_MANAGER

typedef void _voidCallBack();

typedef struct
{
    _voidCallBack *Start;

    _voidCallBack *Update;
    
    _voidCallBack *Draw;

    _voidCallBack *End;

    int TransisionIn;

    int TransisionOut;
}StateManager;

typedef struct
{
    int TransisionOutFrames;
    int TransisionInFrames;

    StateManager* CurrentState;
    StateManager* ChangeTo;

}StateMachine;

void StateMachineStart(StateMachine* machine, StateManager* state);
void StateMachineChange(StateMachine* machine, StateManager* state);
void StateMachineUpdate(StateMachine* machine);
void StateMachineDraw(StateMachine* machine);
#endif
