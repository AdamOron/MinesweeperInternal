#pragma once

template <class T>
class Feature
{
protected:
	static T *s_pInstance;

	bool m_bActive;

public:
	Feature() :
		m_bActive(false)
	{
	}

	static T *GetInstance()
	{
		if (!s_pInstance)
			s_pInstance = new T();

		return s_pInstance;
	}

	inline void Enable()
	{
		m_bActive = true;
	}

	inline void Disable()
	{
		m_bActive = false;
	}
};

template <typename T>
T *Feature<T>::s_pInstance = nullptr;
