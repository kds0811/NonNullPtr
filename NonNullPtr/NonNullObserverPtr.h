#pragma once
#include "Logger.h"
#include <cassert>
#include <exception>

template <typename T>
class NonNullObserverPtr
{
    T* mPtr;

public:
    // Policy for handling nullptr: log or throw
    enum class NullPolicy { Log, Throw };

    NonNullObserverPtr(T* ptr, NullPolicy policy = NullPolicy::Throw)
        : mPtr(ptr)
    {
        if (!mPtr)
        {
            switch (policy)
            {
            case NullPolicy::Log:
                assert(mPtr);
                LOG_ERROR("Ptr is null!");
                break;
            case NullPolicy::Throw:
                throw std::invalid_argument("Ptr is null!");
            }
        }
    }

    [[nodiscard]] inline const T* Get() const noexcept { return mPtr; }
    [[nodiscard]] inline T* Get() noexcept { return mPtr; }

    [[nodiscard]] inline T& operator*() const
    {
        if (!mPtr)
            throw std::runtime_error("Dereferencing null pointer!");
        return *mPtr;
    }

    [[nodiscard]] inline T* operator->() const noexcept { return mPtr; }
};