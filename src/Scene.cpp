
#include "Scene.hpp"

namespace gfx {

  Scene::Scene()
  {
  }

  Scene::~Scene()
  {
    clear();
  }

  void Scene::clear()
  {
    m_nodes.clear();
    m_handles.reset();
  }

  Handle Scene::createNode()
  {
    m_nodes.push_back(Node());
    Handle handle = m_handles.add(&m_nodes.back());
    m_nodes.back().handle = handle;
    return handle;
  }

  void Scene::destroyNode(Handle handle)
  {
    Node * node = NULL;
    if (m_handles.get(handle, node))
    {
      *node = m_nodes.back();
      m_handles.update(node->handle, node);
      m_handles.remove(handle);
      m_nodes.pop_back();
    }
  }

  bool Scene::verifyNode(Handle nodeRef)
  {
    Node * node = NULL;
    if (m_handles.get(nodeRef, node))
      return node->handle == nodeRef;
    return false;
  }

  void Scene::attachEntity(Handle nodeRef, Handle entity)
  {
    Node * node = NULL;
    if (m_handles.get(nodeRef, node))
      node->attachment = entity;
  }

  void Scene::detachEntity(Handle nodeRef)
  {
    Node * node = NULL;
    if (m_handles.get(nodeRef, node))
      node->attachment = Handle();
  }

  uint32_t Scene::nodeCount() const
  {
    return m_handles.count();
  }

}