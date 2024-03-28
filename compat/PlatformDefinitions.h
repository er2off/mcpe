//
//  PlatformDefinitions.h
//  Minecraft
//
//  Created by Brent on 11/27/23.
//
//

#pragma once

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#if TARGET_OS_SIMULATOR || TARGET_IPHONE_SIMULATOR
# define MC_TARGET_OS_SIMULATOR 1
#else
#endif
#if TARGET_OS_MAC
# define MC_TARGET_OS_MAC 1
#elif TARGET_OS_IOS && TARGET_OS_IPHONE
# define MC_TARGET_OS_IOS 1
#endif
