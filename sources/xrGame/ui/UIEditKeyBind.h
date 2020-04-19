#pragma once

#include "UILabel.h"
#include "UIOptionsItem.h"

struct _action;
struct _keyboard;
class CUIColorAnimatorWrapper;

class CUIEditKeyBind : public CUILabel, public CUIOptionsItem 
{
	bool			m_bPrimary;
	_action*		m_action;
	_keyboard*		m_keyboard;
public:
					CUIEditKeyBind			(bool bPrim);
	virtual			~CUIEditKeyBind			();
	// options item
	virtual void	Register				(LPCSTR entry, LPCSTR group);
	virtual void	SetCurrentValue			();
	virtual void	SaveValue				();
	virtual	void	OnMessage				(LPCSTR message);
	virtual bool	IsChanged				();

	// CUIWindow methods
	virtual void	Init					(float x, float y, float width, float height);
	virtual void	Update					();
	virtual bool	OnMouseDown				(int mouse_btn);
	virtual void	OnFocusLost				();
	virtual bool	OnKeyboard				(int dik, EUIMessages keyboard_action);
	// IUITextControl
	virtual void	SetText					(LPCSTR text);

protected:
	void			BindAction2Key			();
	virtual void	InitTexture				(LPCSTR texture, bool horizontal = true);

	bool		m_bEditMode;
	bool		m_bChanged;

	CUIColorAnimatorWrapper*				m_pAnimation;
};