////////////////////////////////////////////////////////////////////////////
//	Module 		: pch_script.h
//	Created 	: 23.05.2007
//  Modified 	: 23.05.2007
//	Author		: Dmitriy Iassenev
//	Description : precompiled header for lua and luabind users
////////////////////////////////////////////////////////////////////////////
#pragma once

#include "stdafx.h"

extern "C" {
#include "..\..\xrLua\src\lua.h"
#include "..\..\xrLua\src\lualib.h"
#include "..\..\xrLua\src\lauxlib.h"
#include "..\..\xrLua\src\luajit.h"
};

#pragma warning(push)
#pragma warning(disable:4995)
#include <luabind/luabind.hpp>
#pragma warning(pop)

#include <luabind/object.hpp>
#include <luabind/functor.hpp>
#include <luabind/operator.hpp>
#include <luabind/adopt_policy.hpp>
#include <luabind/return_reference_to_policy.hpp>
#include <luabind/out_value_policy.hpp>
#include <luabind/iterator_policy.hpp>

#include <depr/dplay8.h>// ������ ������
