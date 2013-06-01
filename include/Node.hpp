
#pragma once

#include "Handle.hpp"

#include "OgreVector3.h"
#include "OgreQuaternion.h"

namespace gfx {

  struct Node
  {
    enum { TYPE = 1 };

    Handle handle;
    Handle attachment;
    uint32_t visibilityMask;
    float boundingRadius;
    /*
    Ogre::Vector3 position;
    Ogre::Vector3 scale;
    Ogre::Quaternion orientation;
    */
  };

}