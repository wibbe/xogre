
#include "Scene.hpp"

namespace gfx {

  Scene::Scene()
    : m_nextFreeNode(0)
  {
  }

  Scene::~Scene()
  {
    clear();
  }

  void Scene::clear()
  {
    for (uint32_t i = 0; i < m_nextFreeNode; ++i)
      m_nodes[i] = Node();

    m_nextFreeNode = 0;
    m_handles.reset();
  }

  Handle Scene::createNode()
  {
    if (m_nextFreeNode >= HandleManager<Node>::MAX_ENTRIES)
      return Handle();

    Handle handle = m_handles.add(&m_nodes[m_nextFreeNode]);
    m_nodes[m_nextFreeNode].handle = handle;
    m_nextFreeNode++;

    return handle;
  }

  void Scene::destroyNode(Handle handle)
  {
    if (Node * node = m_handles.get(handle))
    {
      if (m_nextFreeNode > 0)
        m_nextFreeNode--;

      *node = m_nodes[m_nextFreeNode];
      m_nodes[m_nextFreeNode] = Node();
      
      if (node->handle)
        m_handles.update(node->handle, node);

      m_handles.remove(handle);
    }
  }

  bool Scene::verifyNode(Handle nodeRef)
  {
    if (Node * node = m_handles.get(nodeRef))
      return node->handle == nodeRef;
    return false;
  }

  void Scene::attachEntity(Handle nodeRef, Handle entity)
  {
    if (Node * node = m_handles.get(nodeRef))
      node->attachment = entity;
  }

  void Scene::detachEntity(Handle nodeRef)
  {
    if (Node * node = m_handles.get(nodeRef))
      node->attachment = Handle();
  }

  void Scene::setVisibilityMask(Handle nodeRef, uint32_t visibilityMask)
  {
    if (Node * node = m_handles.get(nodeRef))
      node->visibilityMask = visibilityMask;
  }

  uint32_t Scene::nodeCount() const
  {
    return m_nextFreeNode;
  }

}