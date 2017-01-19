#pragma once

#include "cCharacter.h"

class cGun;
class cController;

class cAI : public cCharacter
{
	cSkinnedMesh*			m_pSkinnedMesh;				// ĳ���� ��ü

	LPD3DXMESH				m_pBoundingSphereDetailMesh;
	std::vector<ST_SPHERE>	m_vecBoundingSphereDetail;

	D3DXMATRIXA16*			m_matParentWorldTM;

public:
	cAI();
	~cAI();

	void Setup(char* szFolder, char* szFilename);
	void Update(iMap* pMap);
	void Render();

	void SetBoundingSphere();
	ST_SPHERE GetBoundingSphere();
	std::vector<ST_SPHERE> GetBoundingSphereDetail();
};

