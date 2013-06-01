
#pragma once

namespace gfx {

  class Renderer
  {
    public:
      Renderer()
      { }

      virtual uint32_t type() const = 0;
  };

}