#include "AppPlatform_sdl_base.hpp"

#include <sstream>
#include <fstream>
#include <sys/stat.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#else
#include "thirdparty/GL/GL.hpp"
#endif

#include "common/Utils.hpp"

#include "SoundSystemAL.hpp"

void AppPlatform_sdl_base::_init(std::string storageDir, SDL_Window *window)
{
	_storageDir = storageDir;
	_window = window;

	_iconTexture = nullptr;
	_icon = nullptr;

	m_bShiftPressed[0] = false;
	m_bShiftPressed[1] = false;

	ensureDirectoryExists(_storageDir.c_str());

	m_pLogger = new Logger;
	m_pSoundSystem = nullptr;
}

void AppPlatform_sdl_base::initSoundSystem()
{
	if (!m_pSoundSystem)
	{
		m_pSoundSystem = new SoundSystemAL();
		LOG_I("Initializing OpenAL SoundSystem...");
	}
	else
	{
		LOG_E("Trying to initialize SoundSystem more than once!");
	}
}

void AppPlatform_sdl_base::setIcon(const Texture& icon)
{
	if (!icon.m_pixels)
		return;

	SAFE_DELETE(_iconTexture);
	if (_icon) SDL_FreeSurface(_icon);

	_iconTexture = new Texture(icon);
	_icon = getSurfaceForTexture(_iconTexture);

	if (_icon)
		SDL_SetWindowIcon(_window, _icon);
}

AppPlatform_sdl_base::~AppPlatform_sdl_base()
{
	if (_icon) SDL_FreeSurface(_icon);
	SAFE_DELETE(_iconTexture);

	SAFE_DELETE(m_pSoundSystem);

	// DELETE THIS LAST
	SAFE_DELETE(m_pLogger);
}

SDL_Surface* AppPlatform_sdl_base::getSurfaceForTexture(const Texture* const texture)
{
	if (!texture) return nullptr;

	void * const pixels = texture->m_pixels;
	const int width = texture->m_width;
	const int height = texture->m_height;
	const int depth = 32; // Color depth (32-bit by default)
	SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(
			pixels, width, height, depth,
			width * 4, // Pitch
			0x000000FF, 0x0000FF00, 0x00FF0000,
			0xFF000000
	);
	if (!surface)
		LOG_E("Failed loading SDL_Surface from Texture: %s", SDL_GetError());

	return surface;
}

int AppPlatform_sdl_base::checkLicense()
{
	// we own the game!!
	return 1;
}

const char* const AppPlatform_sdl_base::getWindowTitle() const
{
	return SDL_GetWindowTitle(_window);
}

int AppPlatform_sdl_base::getScreenWidth() const
{
	int width;
	SDL_GL_GetDrawableSize(_window, &width, nullptr);
	return width;
}

int AppPlatform_sdl_base::getScreenHeight() const
{
	int height;
	SDL_GL_GetDrawableSize(_window, nullptr, &height);
	return height;
}

void AppPlatform_sdl_base::setMouseGrabbed(bool b)
{
	SDL_SetWindowGrab(_window, b ? SDL_TRUE : SDL_FALSE);
	SDL_SetRelativeMouseMode(b ? SDL_TRUE : SDL_FALSE);
}

void AppPlatform_sdl_base::setMouseDiff(int x, int y)
{
	xrel = x;
	yrel = y;
}

void AppPlatform_sdl_base::getMouseDiff(int& x, int& y)
{
	x = xrel;
	y = yrel;
}

void AppPlatform_sdl_base::clearDiff()
{
	xrel = 0;
	yrel = 0;
}

bool AppPlatform_sdl_base::shiftPressed()
{
	return m_bShiftPressed[0] || m_bShiftPressed[1];
}

void AppPlatform_sdl_base::setShiftPressed(bool b, bool isLeft)
{
	m_bShiftPressed[isLeft ? 0 : 1] = b;
}

int AppPlatform_sdl_base::getUserInputStatus()
{
	return -1;
}

MouseButtonType AppPlatform_sdl_base::GetMouseButtonType(SDL_Event event)
{
	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		return BUTTON_LEFT;
	case SDL_BUTTON_RIGHT:
		return BUTTON_RIGHT;
	case SDL_BUTTON_MIDDLE:
		return BUTTON_MIDDLE;
	default:
		return BUTTON_NONE;
	}
}

bool AppPlatform_sdl_base::GetMouseButtonState(SDL_Event event)
{
	bool result;

	switch (event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		result = true;
		break;
	case SDL_MOUSEBUTTONUP:
		result = false;
		break;
	case SDL_MOUSEWHEEL:
	{
		short wheelDelta = event.wheel.y;
		if (wheelDelta > 0)
		{
			// "A positive value indicates that the wheel was rotated forward, away from the user."
			result = false;
		}
		else
		{
			// "A negative value indicates that the wheel was rotated backward, toward the user."
			result = true;
		}
		break;
	}
	default:
		result = false;
		break;
	}

	return result;
}

Keyboard::KeyState AppPlatform_sdl_base::GetKeyState(SDL_Event event)
{
	switch (event.key.state)
	{
	case SDL_RELEASED:
		return Keyboard::UP;
	case SDL_PRESSED:
	default:
		return Keyboard::DOWN;
	}
}
