
#include "Handle.hpp"

TEST(Handle, DefaultConstruction)
{
  gfx::Handle handle;

  CHECK_EQ(handle.index, 0);
  CHECK_EQ(handle.counter, 0);
  CHECK_EQ(handle.type, 0);
}

TEST(Handle, Construction)
{
  gfx::Handle handle(1, 2, 3);

  CHECK_EQ(handle.index, 1);
  CHECK_EQ(handle.counter, 2);
  CHECK_EQ(handle.type, 3);
}

TEST(Handle, TypeConversion)
{
  gfx::Handle handle(5, 0, 0);

  CHECK_EQ((uint32_t)handle, 5);
}

TEST(Handle, Copy)
{
  gfx::Handle handle(1, 2, 3);
  gfx::Handle copy = handle;

  CHECK_EQ(handle.index, 1);
  CHECK_EQ(handle.counter, 2);
  CHECK_EQ(handle.type, 3);
  CHECK_EQ(copy.index, 1);
  CHECK_EQ(copy.counter, 2);
  CHECK_EQ(copy.type, 3);
}

TEST(Handle, Size)
{
  gfx::Handle handle;
  CHECK_EQ(sizeof(handle), sizeof(uint32_t));
}