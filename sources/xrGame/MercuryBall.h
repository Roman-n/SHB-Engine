///////////////////////////////////////////////////////////////
// MercuryBall.h	������� ���
// MercuryBall - �������������� � ������������ ���
// �������������� � ����� �� �����
///////////////////////////////////////////////////////////////

#pragma once

#include "Artefact.h"

class CMercuryBall : public CArtefact 
{
private:
	typedef CArtefact inherited;
public:
	CMercuryBall(void);
	virtual ~CMercuryBall(void);

	virtual void Load				(LPCSTR section);
protected:
	virtual void	UpdateCLChild	();

	//����� ���������� ���������� ��������� ����
	ALife::_TIME_ID m_timeLastUpdate;
	//����� ����� ���������
	ALife::_TIME_ID m_timeToUpdate;

	//�������� ��������� ������� ����
	float m_fImpulseMin;
	float m_fImpulseMax;
};
