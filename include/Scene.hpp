
#pragma once

#include "Node.hpp"
#include "HandleManager.hpp"

#include "OgreVector3.h"
#include "OgreQuaternion.h"
#include <vector>

namespace gfx {

  class Scene
  {
    public:
      Scene();
      ~Scene();

      void clear();

      Handle createNode();
      void destroyNode(Handle node);

      bool verifyNode(Handle node);

      void attachEntity(Handle node, Handle entity);
      void detachEntity(Handle node);

      void setTransform(Handle node, Ogre::Vector3 const& position, Ogre::Vector3 const& scale, Ogre::Quaternion const& orientation);
      void setVisibilityMask(Handle node, uint32_t visibilityMask);

      uint32_t nodeCount() const;

    private:
      HandleManager<Node> m_handles;
      Node m_nodes[Handle::MAX_INDEX];
      uint32_t m_nextFreeNode;
  };

}