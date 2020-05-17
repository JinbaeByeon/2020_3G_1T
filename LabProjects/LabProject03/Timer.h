#pragma once
//-----------------------------------------------------------------------------
// File: CGameTimer.h
//-----------------------------------------------------------------------------

// 50ȸ�� ������ ó���ð��� �����Ͽ� ����Ѵ�.
const ULONG MAX_SAMPLE_COUNT = 50;

class CGameTimer
{
public:
	CGameTimer();
	virtual ~CGameTimer();

	//Ÿ�̸��� �ð��� �����Ѵ�. 
	void Tick(float fLockFPS = 0.0f);

	//������ ����Ʈ�� ���ڿ��� ��ȯ�Ѵ�.
	unsigned long GetFrameRate(LPTSTR lpszString = NULL, int nCharacters = 0);
	//���� �������� ��� �ð��� ��ȯ�Ѵ�.
    float GetTimeElapsed();

private:
	double							m_fTimeScale;						
	float							m_fTimeElapsed;		

	__int64							m_nBasePerformanceCounter;
	__int64							m_nPausedPerformanceCounter;
	__int64							m_nStopPerformanceCounter;
	__int64							m_nCurrentPerformanceCounter;
    __int64							m_nLastPerformanceCounter;

	__int64							m_PerformanceFrequencyPerSec;				

    float							m_fFrameTime[MAX_SAMPLE_COUNT];
    ULONG							m_nSampleCount;

    unsigned long					m_nCurrentFrameRate;				
	unsigned long					m_FramePerSecond;					
	float							m_fFPSTimeElapsed;
};
