#pragma once
#include "filemanager.h"
#include "renderer.h"
#include "surface.h"
#include "texture.h"
#include "window.h"

class Image
{
public:
  Image();
  Image(std::string image);
  ~Image();
  Window      *getWindow() const;
  Renderer    *getRenderer() const;
  Surface     *getSurface() const;
  Texture     *getTexture() const;
  FileManager *getFileManager() const;

private:
  std::unique_ptr<Window>      m_window;
  std::unique_ptr<Renderer>    m_renderer;
  std::unique_ptr<Surface>     m_surface;
  std::unique_ptr<Texture>     m_texture;
  std::unique_ptr<FileManager> m_fileManager;
};
