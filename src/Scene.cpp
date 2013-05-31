
#include "Scene.hpp"

namespace gfx {

  Scene::Scene()
  {
  }

  Scene::~Scene()
  {
  }

  void Scene::clear()
  {
    m_nodes.clear();
    m_handles.reset();
  }

  Handle Scene::createNode()
  {
    m_nodes.push_back(Node());
    return m_handles.add(&m_nodes.back());
  }

  void Scene::destroyNode(Handle handle)
  {
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

}