#pragma once

typedef	void		crashhandler		(void);
typedef	void		on_dialog			(bool before);

class CORE_API	CDebug
{
private:
	crashhandler*	handler	;
	on_dialog*		m_on_dialog;

public:
	void			_initialize			( );
	
public:
	crashhandler*	get_crashhandler	()							{ return handler;	};
	void			set_crashhandler	(crashhandler* _handler)	{ handler=_handler;	};

	on_dialog*		get_on_dialog		()							{ return m_on_dialog;	}
	void			set_on_dialog		(on_dialog* on_dialog)		{ m_on_dialog = on_dialog;	}

	const char* error2string		(long  code	);

	void			fail				(const char* e1, const char* file, int line, const char* unction, bool &ignore_always);
	void			fail				(const char* e1, const std::string &e2, const char* file, int line, const char* function, bool &ignore_always);
	void			fail				(const char* e1, const char* e2, const char* file, int line, const char* function, bool &ignore_always);
	void			fail				(const char* e1, const char* e2, const char* e3, const char* file, int line, const char* function, bool &ignore_always);
	void			fail				(const char* e1, const char* e2, const char* e3, const char* e4, const char* file, int line, const char* function, bool &ignore_always);
	void			error				(long  code, const char* e1, const char* file, int line, const char* function, bool &ignore_always);
	void			error				(long  code, const char* e1, const char* e2, const char* file, int line, const char* function, bool &ignore_always);
	void _cdecl		fatal				(const char* file, int line, const char* function, const char* F,...);
	void			backend				(const char* reason, const char* expression, const char* argument0, const char* argument1, const char* file, int line, const char* function, bool &ignore_always);
	void			do_exit				(const std::string &message);
};

// warning
// this function can be used for debug purposes only
IC	std::string __cdecl	make_string		(const char* format,...)
{
	va_list		args;
	va_start	(args,format);

	char		temp[4096];
	vsprintf	(temp,format,args);

	return		(temp);
}

extern CORE_API	CDebug		Debug;

CORE_API void LogStackTrace	(const char* header);

#include "Debug_macros.h"
