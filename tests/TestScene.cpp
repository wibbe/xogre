
#include "Test.hpp"
#include "Scene.hpp"

TEST(Scene, Construction)
{
  gfx::Scene scene;
}

TEST(Scene, NodeCreationDestruction)
{
  gfx::Scene scene;
  gfx::Handle node = scene.createNode();
  scene.destroyNode(node);
}

TEST(Scene, MultipleNodeCreationDestruction)
{
  gfx::Scene scene;
  std::vector<gfx::Handle> nodes;

  // Create some nodes
  for (int i = 0; i < 50; ++i)
    nodes.push_back(scene.createNode());

  // Destroy some of the nodes
  for (int i = 0; i < 20; ++i)
  {
    scene.destroyNode(nodes.back());
    nodes.pop_back();
  }

  // Create some more nodes
  for (int i = 0; i < 50; ++i)
    nodes.push_back(scene.createNode());

  // Destroy the rest of the nodes
  while (!nodes.empty())
  {
    scene.destroyNode(nodes.back());
    nodes.pop_back();
  }

  CHECK_EQ(scene.nodeCount(), 0);
}

TEST(Scene, ClearScene)
{
  gfx::Scene scene;

  for (int i = 0; i < 100; ++i)
    scene.createNode();

  scene.clear();
  CHECK_EQ(scene.nodeCount(), 0);
}