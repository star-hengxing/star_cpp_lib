#pragma once

#ifndef NAMESPACE_BEGIN
#define NAMESPACE_BEGIN(name) namespace name {
#endif

#ifndef NAMESPACE_END
#define NAMESPACE_END(name) }
#endif

#ifdef _MSC_VER
#define ALWAYS_INLINE __forceinline
#else
#define ALWAYS_INLINE [[gnu::always_inline]]
#endif

#ifdef _WIN32
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif
#elif
#define LIBRARY_API
#endif
