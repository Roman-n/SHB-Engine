#pragma once

// refs
struct xr_token;

CORE_API int		    	_GetItemCount			( LPCSTR , char separator=',');
CORE_API char* _GetItem				( LPCSTR, int, char*, char separator=',', LPCSTR ="", bool trim=true );
CORE_API char* _GetItems				( LPCSTR, int, int, char*, char separator=',');
CORE_API LPCSTR	    	_SetPos					( LPCSTR src, u32 pos, char separator=',' );
CORE_API LPCSTR	    	_CopyVal				( LPCSTR src, char* dst, char separator=',' );
CORE_API char* _Trim					(char* str );
CORE_API char* _TrimLeft				(char* str );
CORE_API char* _TrimRight				(char* str );
CORE_API char* _ChangeSymbol			(char* name, char src, char dest );
CORE_API u32		    	_ParseItem				(const char* src, xr_token* token_list);
CORE_API u32		    	_ParseItem				(const char* src, int ind, xr_token* token_list);
CORE_API char* _ReplaceItem 			( LPCSTR src, int index, LPCSTR new_item, char* dst, char separator );
CORE_API char* _ReplaceItems 			( LPCSTR src, int idx_start, int idx_end, LPCSTR new_items, char* dst, char separator );
CORE_API void 	    	_SequenceToList			( LPSTRVec& lst, LPCSTR in, char separator=',' );
CORE_API void 			_SequenceToList			( RStringVec& lst, LPCSTR in, char separator=',' );
CORE_API void 			_SequenceToList			( SStringVec& lst, LPCSTR in, char separator=',' );

CORE_API xr_string& 		_Trim					( xr_string& src );
CORE_API xr_string& 		_TrimLeft				( xr_string& src );
CORE_API xr_string&		_TrimRight				( xr_string& src );
CORE_API xr_string&   	_ChangeSymbol			( xr_string& name, char src, char dest );
CORE_API LPCSTR		 	_CopyVal 				( LPCSTR src, xr_string& dst, char separator=',' );
CORE_API LPCSTR			_GetItem				( LPCSTR src, int, xr_string& p, char separator=',', LPCSTR ="", bool trim=true );
CORE_API xr_string		_ListToSequence			( const SStringVec& lst );
CORE_API shared_str		_ListToSequence			( const RStringVec& lst );
