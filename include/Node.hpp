
#pragma once

#include "Handle.hpp"

#include "OgreMatrix4.h"

namespace gfx {

  struct Node
  {
    enum { TYPE = 1 };

    Handle handle;
    Handle attachment;
    uint32_t visibilityMask;
    float boundingRadius;

    Ogre::Matrix4 transform;
  };

}