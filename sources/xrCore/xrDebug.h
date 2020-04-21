#pragma once

typedef	void		crashhandler		(void);
typedef	void		on_dialog			(bool before);

class XRCORE_API	xrDebug
{
private:
	crashhandler*	handler	;
	on_dialog*		m_on_dialog;

public:
	void			_initialize			(const bool &dedicated);
	
public:
	crashhandler*	get_crashhandler	()							{ return handler;	};
	void			set_crashhandler	(crashhandler* _handler)	{ handler=_handler;	};

	on_dialog*		get_on_dialog		()							{ return m_on_dialog;	}
	void			set_on_dialog		(on_dialog* on_dialog)		{ m_on_dialog = on_dialog;	}

	LPCSTR			error2string		(long  code	);

	void			fail				(LPCSTR e1, LPCSTR file, int line, LPCSTR unction, bool &ignore_always);
	void			fail				(LPCSTR e1, const std::string &e2, LPCSTR file, int line, LPCSTR function, bool &ignore_always);
	void			fail				(LPCSTR e1, LPCSTR e2, LPCSTR file, int line, LPCSTR function, bool &ignore_always);
	void			fail				(LPCSTR e1, LPCSTR e2, LPCSTR e3, LPCSTR file, int line, LPCSTR function, bool &ignore_always);
	void			fail				(LPCSTR e1, LPCSTR e2, LPCSTR e3, LPCSTR e4, LPCSTR file, int line, LPCSTR function, bool &ignore_always);
	void			error				(long  code, LPCSTR e1, LPCSTR file, int line, LPCSTR function, bool &ignore_always);
	void			error				(long  code, LPCSTR e1, LPCSTR e2, LPCSTR file, int line, LPCSTR function, bool &ignore_always);
	void _cdecl		fatal				(LPCSTR file, int line, LPCSTR function, LPCSTR F,...);
	void			backend				(LPCSTR reason, LPCSTR expression, LPCSTR argument0, LPCSTR argument1, LPCSTR file, int line, LPCSTR function, bool &ignore_always);
	void			do_exit				(const std::string &message);
};

// warning
// this function can be used for debug purposes only
IC	std::string __cdecl	make_string		(LPCSTR format,...)
{
	va_list		args;
	va_start	(args,format);

	char		temp[4096];
	vsprintf	(temp,format,args);

	return		(temp);
}

extern XRCORE_API	xrDebug		Debug;

XRCORE_API void LogStackTrace	(LPCSTR header);

#include "xrDebug_macros.h"
