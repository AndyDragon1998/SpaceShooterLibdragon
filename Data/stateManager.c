/*****************************************************************************/
/*  Автор         		: Дракончик			                                 */
/*  Приставка     		: Sony PlayStation 2					             */
/*  ОС			  		: OSDSYS											 */
/*  Язык	      		: GNU C                                              */
/*                                                                           */
/*  Содержимое файла	: Управление стадии игри		                     */
/*  Атрибут файла		: SOURCE                                             */
/*  Имя файла     		: stateManager.c	                                 */
/*                                                                           */
/*****************************************************************************/
#include "include/stateManager.h"

void StateMachineStart(StateMachine* machine, StateManager* state)
{
    if (state != 0 && machine != 0)
    {
        machine->ChangeTo = 0;
        machine->TransisionOutFrames = -1;
        machine->TransisionInFrames = -1;

        machine->CurrentState = state;
        machine->CurrentState->Start();
    }
}


void StateMachineChange(StateMachine* machine, StateManager* state)
{
    if (state != 0 && machine != 0)
    {
        machine->ChangeTo = 0;

        machine->CurrentState->End();

        machine->CurrentState = state;

        machine->CurrentState->Start();
    }
}


void StateMachineUpdate(StateMachine* machine)
{
    if (machine != 0)
    {
        machine->CurrentState->Update();
    }
}


void StateMachineDraw(StateMachine* machine)
{
    if (machine != 0)
    {
        machine->CurrentState->Draw();
    }
}
