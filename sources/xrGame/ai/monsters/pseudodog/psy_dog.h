#pragma once
#include "pseudodog.h"
#include "../../../script_export_space.h"

class CPsyDogPhantom;

class CPsyDog : public CAI_PseudoDog {
	typedef CAI_PseudoDog inherited;

	friend class CPsyDogPhantom;
	friend class CPsyDogAura;

	// �������� � ������ ��� ���������� � ����
	CPsyDogAura		*m_aura;

	// enemy transfered from phantom
	CActor			*m_enemy;

	// externals
	u8				m_phantoms_max;
	u8				m_phantoms_min;
	u32				m_time_phantom_appear;
	
	//internals
	u32				m_time_last_phantom_appear;

public:
						CPsyDog				();
		virtual			~CPsyDog			();

		virtual void	Load				(const char* section);
		virtual BOOL	net_Spawn			(CSE_Abstract *dc);
		virtual void	reinit				();
		virtual void	reload				(const char* section);
		virtual void	net_Destroy			();
		virtual void	Die					(CObject* who);

		virtual void	Think				();
//				void	on_phantom_appear	();
		virtual IStateManagerBase *create_state_manager	();

				u8		get_phantoms_count	();
				bool	must_hide			() {return (get_phantoms_count() < m_phantoms_min);}
private:
				bool	spawn_phantom		();
				void	delete_phantom		(CPsyDogPhantom*);
				void	register_phantom	(CPsyDogPhantom*);
				void	unregister_phantom	(CPsyDogPhantom*);

				void	delete_all_phantoms	();

private:
	xr_vector<CPsyDogPhantom*> m_storage;

	DECLARE_SCRIPT_REGISTER_FUNCTION
};

add_to_type_list(CPsyDog)
#undef script_type_list
#define script_type_list save_type_list(CPsyDog)

//////////////////////////////////////////////////////////////////////////
// Phantom Psy Dog
//////////////////////////////////////////////////////////////////////////

class CPsyDogPhantom : public CAI_PseudoDog {
	typedef CAI_PseudoDog inherited;
	
	CPsyDog			*m_parent;

	enum {
		eWaitToAppear,
		eAttack
	}m_state;

	SAttackEffector m_appear_effector;

	const char* m_particles_appear;
	const char* m_particles_disappear;

	u16				m_parent_id;
		
	u32				m_time_spawned;

public:
					CPsyDogPhantom		();
	virtual			~CPsyDogPhantom		();
	virtual BOOL	net_Spawn			(CSE_Abstract *dc);
	virtual void	Think				();
	virtual	void	Hit					(SHit* pHDS);

	virtual void	net_Destroy			();
	virtual void	Die					(CObject* who);

			void	destroy_from_parent	();
private:
			void	destroy_me					();
			void	try_to_register_to_parent	();
			bool	is_wait_to_destroy_object	() {return (m_parent_id == 0xffff);}

	DECLARE_SCRIPT_REGISTER_FUNCTION
};

add_to_type_list(CPsyDogPhantom)
#undef script_type_list
#define script_type_list save_type_list(CPsyDogPhantom)
