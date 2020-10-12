///////////////////////////////////////////////////////////////
// GraviArtifact.h
// GraviArtefact - �������������� ��������, ������� �� �����
// � ����� ��� ������
///////////////////////////////////////////////////////////////

#pragma once
#include "Artefact.h"

class CGraviArtefact : public CArtefact 
{
private:
	typedef CArtefact inherited;
public:
	CGraviArtefact(void);
	virtual ~CGraviArtefact(void);

	virtual void Load				(const char* section);

protected:
	virtual void	UpdateCLChild	();
	//��������� ���������
	float m_fJumpHeight;
	float m_fEnergy;
};
