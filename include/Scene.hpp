
#pragma once

#include "Node.hpp"
#include "HandleManager.hpp"

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

      void setVisibilityMask(Handle node, uint32_t visibilityMask);

      uint32_t nodeCount() const;

    private:
      HandleManager<Node> m_handles;
      Node m_nodes[HandleManager<Node>::MAX_ENTRIES];
      uint32_t m_nextFreeNode;
  };

}