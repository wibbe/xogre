
#pragma once

#include "Scene.hpp"
#include "Renderer.hpp"
#include "OgreCamera.h"
#include "OgreViewport.h"

namespace gfx {

  class Context
  {
    public:
      Context();

      void registerRenderer(Renderer * renderer);

      void render(Ogre::Camera * camera, Ogre::Viewport * viewport, Scene const& scene);

    private:
      Renderer * m_typeRenderers[Handle::MAX_TYPES];
  };

}