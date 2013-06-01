
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

TEST(Scene, NodeVerification)
{
  gfx::Scene scene;
  gfx::Handle first = scene.createNode();
  gfx::Handle second = scene.createNode();
  gfx::Handle third = scene.createNode();

  scene.destroyNode(first);

  CHECK_FALSE(scene.verifyNode(first));
  CHECK_TRUE(scene.verifyNode(second));
  CHECK_TRUE(scene.verifyNode(third));
}

TEST(Scene, MultipleNodeCreationDestruction)
{
  gfx::Scene scene;
  std::vector<gfx::Handle> nodes;

  // Create some nodes
  for (int i = 0; i < 50; ++i)
    nodes.push_back(scene.createNode());

  // Destroy some of the nodes
  for (int i = 0; i < 50; ++i)
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

TEST(Scene, Fill)
{
  gfx::Scene scene;

  // Fill scene
  for (int i = 0; i < gfx::Handle::MAX_INDEX; ++i)
    CHECK_TRUE(scene.createNode().isValid());

  CHECK_FALSE(scene.createNode().isValid());
}
