// File:        UITabButton.h
// Description: 

#pragma once

#include "UI3tButton.h"//
//.#include "UIFrameWindow.h"//

class CUITabButton : public CUI3tButton {
	typedef CUI3tButton inherited;
public:
	CUITabButton();
	virtual ~CUITabButton();
	
	// behavior	
//.	virtual void AssociateWindow(CUIFrameWindow* pWindow);
//.	virtual CUIFrameWindow* GetAssociatedWindow();
//.	virtual void ShowAssociatedWindow(bool bShow = true);
	virtual void SendMessage(CUIWindow* pWnd, s16 msg, void* pData = nullptr);
	virtual bool OnMouse(float x, float y, EUIMessages mouse_action);
	virtual bool OnMouseDown(int mouse_btn);
	virtual void Update();

//.protected:
	// associated window
//.	CUIFrameWindow* m_pAssociatedWindow;
};