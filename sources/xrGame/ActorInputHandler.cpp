#include "stdafx.h"

#include "ActorInputHandler.h"
#include "actor.h"
#include "Level.h"

void CActorInputHandler::reinit( )
{
	m_actor = nullptr;
}

void CActorInputHandler::install( )
{
	m_actor = smart_cast<CActor*> (Level( ).CurrentEntity( ));
	VERIFY(m_actor);

	m_actor->set_input_external_handler(this);
}

void CActorInputHandler::install(CActor* actor)
{
	m_actor = actor;
	VERIFY(m_actor);
	actor->set_input_external_handler(this);
}

void CActorInputHandler::release( )
{
	VERIFY(m_actor);

	m_actor->set_input_external_handler(nullptr);
	m_actor = nullptr;
}
