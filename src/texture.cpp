#include "texture.h"

/*
 ** clang-format off
 *
 * @brief Constructs a Texture object.
 *
 * Creates an SDL texture from the given SDL surface using the specified
 * renderer. Throws an exception if the texture cannot be created.
 *
 * @param renderer A pointer to the SDL_Renderer used to create the texture.
 * @param surface A pointer to the SDL_Surface used to create the texture.
 *
 * @throws std::runtime_error If the texture cannot be created.
 *
 ** clang-format on
 */

Texture::Texture(SDL_Renderer *renderer, SDL_Surface *surface)
{
  this->m_sdl = SDL_CreateTextureFromSurface(renderer, surface);
  helper::assert(this->m_sdl != nullptr, SDL_GetError());
}

/*
 ** clang-format off
 *
 * @brief Destructs the Texture object.
 *
 * Frees the SDL texture resources. Called automatically when the object goes
 * out of scope.
 *
 ** clang-format on
 */

Texture::~Texture(void)
{
  if (this->m_sdl)
    SDL_DestroyTexture(this->m_sdl);
}

/*
 ** clang-format off
 *
 * @brief Retrieves the underlying SDL texture.
 *
 * @return A pointer to the SDL_Texture object.
 *
 ** clang-format on
 */

SDL_Texture *
Texture::get(void) const
{
  return this->m_sdl;
}
