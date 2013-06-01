
#include "Context.hpp"

namespace gfx {

  Context::Context()
  {
  }

  void Context::registerRenderer(Renderer * renderer)
  {
    assert(renderer->type() < Handle::MAX_TYPES);
    m_typeRenderers[renderer->type()] = renderer;
  }

  void Context::render(Ogre::Camera * camera, Ogre::Viewport * viewport, Scene const& scene)
  {
    
  }

}