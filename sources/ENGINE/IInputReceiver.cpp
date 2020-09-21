#include "stdafx.h"

#include "Input.h"
#include "IInputReceiver.h"

void IInputReceiver::IR_Capture( )
{
	VERIFY(pInput);
	pInput->iCapture(this);
}

void IInputReceiver::IR_Release( )
{
	VERIFY(pInput);
	pInput->iRelease(this);
}

void IInputReceiver::IR_OnDeactivate( )
{
	int i;
	for (i = 0; i < CInput::COUNT_KB_BUTTONS; i++)
	{
		if (IR_GetKeyState(i))
		{
			IR_OnKeyboardRelease(i);
		}
	}

	for (i = 0; i < CInput::COUNT_MOUSE_BUTTONS; i++)
	{
		if (IR_GetBtnState(i))
		{
			IR_OnMouseRelease(i);
		}
	}

	IR_OnMouseStop(DIMOFS_X, 0);
	IR_OnMouseStop(DIMOFS_Y, 0);
}

void IInputReceiver::IR_OnActivate( )
{ }

BOOL IInputReceiver::IR_GetKeyState(int dik)
{
	VERIFY(pInput);
	return pInput->iGetAsyncKeyState(dik);
}

BOOL IInputReceiver::IR_GetBtnState(int btn)
{
	VERIFY(pInput);
	return pInput->iGetAsyncBtnState(btn);
}
