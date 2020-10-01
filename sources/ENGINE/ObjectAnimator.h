#pragma once

#include "motion.h"

// refs
class ENGINE_API CObjectAnimator
{
private:
	DEFINE_VECTOR		(COMotion*,MotionVec,MotionIt);
protected:
	bool				bLoop;

    shared_str			m_Name;
    
	Fmatrix				m_XFORM;
    SAnimParams			m_MParam;
	MotionVec			m_Motions;
    float				m_Speed;

    COMotion*			m_Current;
	void				LoadMotions		(const char* fname);
	void				SetActiveMotion	(COMotion* mot);
//	COMotion*			FindMotionByName(const char* name);
public:
						CObjectAnimator	();
	virtual				~CObjectAnimator();

	void				Clear			();
	void				Load			(const char* name);
    IC const char* Name			(){return *m_Name;}
    float&				Speed			(){return m_Speed;}

	COMotion*			Play			(bool bLoop, const char* name=0);
	void				Pause			(bool val){return m_MParam.Pause(val);}
	void				Stop			();
	IC BOOL				IsPlaying		(){return m_MParam.bPlay;}

    IC const Fmatrix&	XFORM			(){return m_XFORM;}
	float				GetLength		();
	// Update
	void				Update			(float dt);
//	void				DrawPath		();
};
