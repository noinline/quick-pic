#include "window.h"

/*
 ** clang-format off
 *
 * @brief Constructs a Window object.
 *
 * Creates an SDL window with the specified name, dimensions, and properties.
 * The window is centered on the screen and always on top. Throws an exception
 * if the window cannot be created.
 *
 * @param name The title of the window.
 * @param width The width of the window in pixels.
 * @param height The height of the window in pixels.
 *
 * @throws std::runtime_error If the window cannot be created.
 *
 ** clang-format on
 */

Window::Window(std::string name, int width, int height)
{
  this->m_sdl = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, width, height,
                                 SDL_WINDOW_ALWAYS_ON_TOP);
  helper::assert(this->m_sdl != nullptr, SDL_GetError());
}

/*
 ** clang-format off
 *
 * @brief Destructs the Window object.
 *
 * Frees the SDL window resources. Called automatically when the object goes
 * out of scope.
 *
 ** clang-format on
 */

Window::~Window(void)
{
  if (this->m_sdl)
    SDL_DestroyWindow(this->m_sdl);
}

/*
 ** clang-format off
 *
 * @brief Retrieves the underlying SDL window.
 *
 * @return A pointer to the SDL_Window object.
 *
 ** clang-format on
 */

SDL_Window *
Window::get(void) const
{
  return this->m_sdl;
}
