// Console.h: interface for the CConsole class.

#pragma once

#include "iinputreceiver.h"

//refs
class ENGINE_API CGameFont;
class ENGINE_API IConsole_Command;

class ENGINE_API CConsole : public IInputReceiver, public pureRender, public pureFrame
{
public:
	//t-defs
	struct str_pred : public std::binary_function<char*, char*, bool>
	{
		IC bool operator()(const char* x, const char* y) const
		{
			return xr_strcmp(x, y) < 0;
		}
	};
	typedef xr_map<const char*, IConsole_Command*, str_pred>	vecCMD;
	typedef vecCMD::iterator							vecCMD_IT;
	enum
	{
		MAX_LEN = 1024
	};

private:
	u32				last_mm_timer;
	float			cur_time;
	float			rep_time;
	float			fAccel;

	int				cmd_delta;
	int				old_cmd_delta;

	char* editor_last;
	BOOL			bShift;

	BOOL			bRepeat;
	BOOL			RecordCommands;

protected:
	int				scroll_delta;
	char			editor[MAX_LEN];
	BOOL			bCursor;

	CGameFont* pFont;

public:
	virtual			~CConsole( )
	{ };
	string64		ConfigFile;
	BOOL			bVisible;
	vecCMD			Commands;

	void			AddCommand(IConsole_Command*);
	void			RemoveCommand(IConsole_Command*);
	void			Reset( );

	void			Show( );
	void			Hide( );

	void			Save( );
	void			Execute(const char* cmd);
	void			ExecuteScript(const char* name);
	void			ExecuteCommand( );

	// get
	BOOL			GetBool(const char* cmd, BOOL& val);
	float			GetFloat(const char* cmd, float& val, float& min, float& max);
	char* GetString(const char* cmd);
	int				GetInteger(const char* cmd, int& val, int& min, int& max);
	char* GetToken(const char* cmd);
	xr_token* GetXRToken(const char* cmd);

	void			SelectCommand( );

	// keyboard
	void			OnPressKey(int dik, BOOL bHold = false);
	virtual void	IR_OnKeyboardPress(int dik);
	virtual void	IR_OnKeyboardHold(int dik);
	virtual void	IR_OnKeyboardRelease(int dik);

	// render & onmove
	virtual void	OnRender(void);
	virtual void	OnFrame(void);

	virtual void	Initialize( );
	virtual void	Destroy( );
};

ENGINE_API extern CConsole* Console;
