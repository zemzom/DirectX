#pragma once

#define GUNMAX 3

class cGun;
class cController;

class cPlayer : public cGameObject
{
	std::vector<cGun*>	m_vecGun;

	int					m_nSelectGun;

	cGun*				m_pGun;
	cController*		m_pController;

	D3DXVECTOR3			m_vCamAngle;
	D3DXMATRIXA16		m_matWorldTM;

public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update(D3DXVECTOR3& camAngle, iMap* pMap = NULL);
	void Render();

	cGun* GetGun();
	void GunSetting(D3DXVECTOR3 & camAngle);

private:
	void BulletFire();


};

