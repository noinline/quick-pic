#include "renderer.h"

/*
 ** clang-format off
 *
 * @brief Constructs a Renderer object.
 *
 * Initializes an SDL renderer for the given window. Uses hardware acceleration
 * by default. Throws an exception if the renderer cannot be created.
 *
 * @param window A pointer to the SDL_Window for which the renderer is created.
 *
 * @throws std::runtime_error If the renderer cannot be created.
 *
 ** clang-format on
 */

Renderer::Renderer(SDL_Window *window)
{
  this->m_sdl = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  helper::assert(this->m_sdl != nullptr, SDL_GetError());
}

/*
 ** clang-format off
 *
 * @brief Destructs the Renderer object.
 *
 * Cleans up the SDL renderer resources. Called automatically when the object
 * goes out of scope.
 *
 ** clang-format on
 */

Renderer::~Renderer(void)
{
  if (this->m_sdl)
    SDL_DestroyRenderer(this->m_sdl);
}

/*
 ** clang-format off
 *
 * @brief Retrieves the underlying SDL renderer.
 *
 * @return A pointer to the SDL_Renderer object.
 *
 ** clang-format on
 */

SDL_Renderer *
Renderer::get(void) const
{
  return this->m_sdl;
}
