
#pragma once

#include <stdint.h>

namespace gfx {

  struct Handle
  {
    Handle()
      : index(0),
        counter(0),
        type(0)
    { }

    Handle(uint32_t index, uint32_t counter, uint32_t type)
      : index(index),
        counter(counter),
        type(type)
    { }

    inline operator uint32_t () const;

    uint32_t index : 14;
    uint32_t counter : 14;
    uint32_t type : 4;
  };

  Handle::operator uint32_t () const
  {
    return type << 28 | counter << 14 | index;
  }

}