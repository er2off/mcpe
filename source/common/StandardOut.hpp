#pragma once

#include <string>

class StandardOut
{
public:
	static StandardOut* const singleton();

	void print(const char* const str);
	void print(std::string str);
	void vprintf(const char* const fmt, va_list argPtr);
	void printf(const char* const fmt, ...);
};

#ifdef _DEBUG

#define LOG(...) StandardOut::singleton()->printf(__VA_ARGS__)

#ifdef PLATFORM_ANDROID
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO,  "MinecraftPE", __VA_ARGS__)
#define LOG_W(...) __android_log_print(ANDROID_LOG_WARN,  "MinecraftPE", __VA_ARGS__)
#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR, "MinecraftPE", __VA_ARGS__)
#else
#define LOG_I(...) LOG("[Info]:  " __VA_ARGS__)
#define LOG_W(...) LOG("[WARN]:  " __VA_ARGS__)
#define LOG_E(...) LOG("[ERROR]: " __VA_ARGS__)
#endif

#else

#define LOG(...)
#define LOG_I(...)
#define LOG_W(...)
#define LOG_E(...)

#endif
