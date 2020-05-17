// File:		UIMessagesWindow.h
// Description:	Window with MP chat and Game Log ( with PDA messages in single and Kill Messages in MP)

#pragma once

#include "UIWindow.h"//
#include "../pda_space.h"
#include "../InfoPortionDefs.h"

class CUIGameLog;
class game_cl_GameState;
class CUIPdaMsgListItem;
class CUIProgressShape;

class CUIMessagesWindow : public CUIWindow {
public:
						CUIMessagesWindow				();
	virtual				~CUIMessagesWindow				();

	void				AddIconedPdaMessage				(LPCSTR textureName, Frect originalRect, LPCSTR message, int iDelay);

	void				AddLogMessage					(const shared_str& msg);

	virtual void		Update();


protected:
	virtual void Init(float x, float y, float width, float height);

	CUIGameLog*			m_pGameLog;
};
