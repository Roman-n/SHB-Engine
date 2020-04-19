///////////////////////////////////
// class CUIOptionsManager
///////////////////////////////////

#pragma once

class CUIOptionsItem;

class CUIOptionsManager{
	friend class CUIOptionsItem;
public:	
	CUIOptionsManager();

	void SeveBackupValues(LPCSTR group);
	void SetCurrentValues(LPCSTR group);
	void SaveValues(LPCSTR group);
	bool IsGroupChanged(LPCSTR group);
	void UndoGroup(LPCSTR group);

	void OptionsPostAccept();
	void DoVidRestart();
	void DoSndRestart();

	void SendMessage2Group(LPCSTR group, LPCSTR message);

protected:	
	void RegisterItem(CUIOptionsItem* item, LPCSTR group);
	void UnRegisterGroup(LPCSTR group);
	void UnRegisterItem(CUIOptionsItem* item);


	typedef	xr_string									group_name;
	typedef xr_vector<CUIOptionsItem*>					items_list;
    typedef xr_map<group_name, items_list>				groups;
	typedef xr_map<group_name, items_list>::iterator	groups_it;

	groups	m_groups;

	bool	m_b_vid_restart;
	bool	m_b_snd_restart;
};