#pragma once

#include "../../xrXMLParser/xrXMLParser.h"

class CUIXml : public CXml
{
	int						m_dbg_id;

public:
							CUIXml( );
	virtual					~CUIXml( );

	virtual shared_str		correct_file_name(const char* path, const char* fn);
};
