#pragma once
#include "Logger.h"
#include <cassert>
#include <exception>

template <typename T>
class NonNullObserverPtr
{
	T* mPtr;
public:
	NonNullObserverPtr(T* ptr)
		: mPtr(ptr)
	{
		if (!mPtr)
		{
			throw std::invalid_argument("Ptr is null!");
		}
	}


	[[nodiscard]] inline const T* Get() const noexcept { return mPtr; }
	[[nodiscard]] inline T* Get() noexcept { return mPtr; }

	[[nodiscard]] inline T& operator*() const{return *mPtr;}

	[[nodiscard]] inline T* operator->() const noexcept { return mPtr; }
};