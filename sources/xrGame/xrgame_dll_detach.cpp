#include "stdafx.h"

#include "ai_space.h"
#include "object_factory.h"
#include "ai/monsters/ai_monster_squad_manager.h"
#include "StringTable.h"

#include "entity_alive.h"
#include "ui/UIInventoryUtilities.h"//
#include "ui/UIXmlInit.h"//

#include "InfoPortion.h"
#include "PhraseDialog.h"
#include "GameTask.h"
#include "EncyclopediaArticle.h"

#include "character_info.h"
//#include "SpecificCharacter.h"
#include "character_community.h"
#include "monster_community.h"
#include "character_rank.h"
#include "character_reputation.h"

#include "profiler.h"

#include "sound_collection_storage.h"
#include "relation_registry.h"

#include "..\ENGINE\IGamePersistent.h"//==>

typedef xr_vector<std::pair<shared_str,int> >	STORY_PAIRS;
extern STORY_PAIRS								story_ids;
extern STORY_PAIRS								spawn_story_ids;

extern void show_smart_cast_stats					();
extern void clear_smart_cast_stats					();
extern void release_smart_cast_stats				();
extern void dump_list_wnd							();
extern void dump_list_lines							();
extern void dump_list_sublines						();
extern void clean_wnd_rects							();
extern void dump_list_xmls							();
extern void CreateUIGeom							();
extern void DestroyUIGeom							();

void init_game_globals()
{
	CreateUIGeom									();

	CInfoPortion::InitInternal						();
	CEncyclopediaArticle::InitInternal				();
	CPhraseDialog::InitInternal						();
	InventoryUtilities::CreateShaders				();

	CCharacterInfo::InitInternal					();
	CSpecificCharacter::InitInternal				();
	CHARACTER_COMMUNITY::InitInternal				();
	CHARACTER_RANK::InitInternal					();
	CHARACTER_REPUTATION::InitInternal				();
	MONSTER_COMMUNITY::InitInternal					();
}

extern CUIXml*	g_gameTaskXml;
extern CUIXml*	g_uiSpotXml;

extern void destroy_lua_wpn_params	();

void clean_game_globals()
{
	destroy_lua_wpn_params							();
	// destroy ai space
	xr_delete										(g_ai_space);
	// destroy object factory
	xr_delete										(g_object_factory);
	// destroy monster squad global var
	xr_delete										(g_monster_squad);

	story_ids.clear									();
	spawn_story_ids.clear							();

	CInfoPortion::DeleteSharedData					();
	CInfoPortion::DeleteIdToIndexData				();

	CEncyclopediaArticle::DeleteSharedData			();
	CEncyclopediaArticle::DeleteIdToIndexData		();

	CPhraseDialog::DeleteSharedData					();
	CPhraseDialog::DeleteIdToIndexData				();

	InventoryUtilities::DestroyShaders				();

	CCharacterInfo::DeleteSharedData				();
	CCharacterInfo::DeleteIdToIndexData				();
	
	CSpecificCharacter::DeleteSharedData			();
	CSpecificCharacter::DeleteIdToIndexData			();

	CHARACTER_COMMUNITY::DeleteIdToIndexData		();
	CHARACTER_RANK::DeleteIdToIndexData				();
	CHARACTER_REPUTATION::DeleteIdToIndexData		();
	MONSTER_COMMUNITY::DeleteIdToIndexData			();

	//static shader for blood
	CEntityAlive::UnloadBloodyWallmarks				();
	CEntityAlive::UnloadFireParticles				();
	//�������� ������ ������� �����
	CStringTable::Destroy							();
	// �������� ������� ������
	CUIXmlInit::DeleteColorDefs						();
	// �������� ������� ��������������� ������ � ��������� ���������
	InventoryUtilities::ClearCharacterInfoStrings	();

	xr_delete										(g_sound_collection_storage);
	
#ifdef DEBUG
	xr_delete										(g_profiler);
	release_smart_cast_stats						();
#endif

	RELATION_REGISTRY::clear_relation_registry		();

	dump_list_wnd									();
	dump_list_lines									();
	dump_list_sublines								();
	clean_wnd_rects									();
	xr_delete										(g_gameTaskXml);
	xr_delete										(g_uiSpotXml);
	dump_list_xmls									();
	DestroyUIGeom									();
}
