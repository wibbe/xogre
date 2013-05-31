
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
      void destroyNode(Handle handle);

      void attachEntity(Handle node, Handle entity);
      void detachEntity(Handle node);

    private:
      HandleManager<Node> m_handles;
      std::vector<Node> m_nodes;
  };

}