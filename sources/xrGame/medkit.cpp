// Medkit - �������, ���������� ��������

#include "stdafx.h"

#include "Medkit.h"
#include "PhysicsShell.h"

CMedkit::CMedkit( )
{ }

CMedkit::~CMedkit( )
{ }

BOOL CMedkit::net_Spawn(CSE_Abstract* DC)
{
	return inherited::net_Spawn(DC);
}

void CMedkit::Load(const char* section)
{
	inherited::Load(section);
}

void CMedkit::net_Destroy( )
{
	inherited::net_Destroy( );
}

void CMedkit::shedule_Update(unsigned int dt)
{
	inherited::shedule_Update(dt);
}

void CMedkit::UpdateCL( )
{
	inherited::UpdateCL( );
}

void CMedkit::renderable_Render( )
{
	inherited::renderable_Render( );
}

void CMedkit::OnH_A_Chield( )
{
	inherited::OnH_A_Chield( );
}

void CMedkit::OnH_B_Independent(bool just_before_destroy)
{
	inherited::OnH_B_Independent(just_before_destroy);
}
