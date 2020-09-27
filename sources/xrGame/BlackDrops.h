///////////////////////////////////////////////////////////////
// BlackDrops.h
// BlackDrops - черные капли
///////////////////////////////////////////////////////////////

#pragma once
#include "Artefact.h"

class CBlackDrops : public CArtefact 
{
private:
	typedef CArtefact inherited;
public:
	CBlackDrops( );
	virtual ~CBlackDrops( );

	virtual void Load				(const char* section);

protected:
};