// Scope - апгрейд оружия оптический прицел

#pragma once

#include "inventory_item_object.h"
#include "script_export_space.h"

class CScope : public CInventoryItemObject
{
private:
	using inherited			= CInventoryItemObject;

public:
					CScope		( );
	virtual			~CScope		( );

	DECLARE_SCRIPT_REGISTER_FUNCTION
};

add_to_type_list(CScope)
#undef script_type_list
#define script_type_list save_type_list(CScope)
