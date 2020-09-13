#pragma once

#define VPUSH(a)	a.x,a.y,a.z

void 	CORE_API	__cdecl		Msg			(LPCSTR format, ...);
void 	CORE_API		Log			(LPCSTR msg);
void 	CORE_API		Log			(LPCSTR msg, LPCSTR			dop);
void 	CORE_API		Log			(LPCSTR msg, u32			dop);
void 	CORE_API		Log			(LPCSTR msg, int  			dop);
void 	CORE_API		Log			(LPCSTR msg, float			dop);
void 	CORE_API		Log			(LPCSTR msg, const Fvector& dop);
void 	CORE_API		Log			(LPCSTR msg, const Fmatrix& dop);
void 	CORE_API		LogWinErr	(LPCSTR msg, long 			err_code);

typedef void	( * LogCallback)	(LPCSTR string);
void	CORE_API				SetLogCB	(LogCallback cb);
void 							CreateLog	(BOOL no_log=FALSE);
void 							InitLog		();
void 							CloseLog	();
void	CORE_API				FlushLog	();

extern 	CORE_API	xr_vector<shared_str>*		LogFile;
extern 	CORE_API	BOOL						LogExecCB;
