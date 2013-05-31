
#pragma once

#include "Handle.hpp"
#include <cassert>

namespace gfx {

  /// Manager for handles, generates handles that are associated with some type of data
  /// Implementation taken from this article: http://gamesfromwithin.com/managing-data-relationships
  template <typename T>
  class HandleManager
  {
    public:
      enum { MAX_ENTRIES = 16384 }; // 2^14

    public:
      HandleManager()
      {
        reset();
      }

      Handle add(T * object)
      {
        assert(m_activeEntryCount < MAX_ENTRIES - 1);

        const uint32_t newIndex = m_firstFreeEntry;
        assert(newIndex < MAX_ENTRIES);
        assert(m_entries[newIndex].active == false);
        assert(!m_entries[newIndex].endOfList);

        m_firstFreeEntry = m_entries[newIndex].nextFreeIndex;
        m_entries[newIndex].nextFreeIndex = 0;
        m_entries[newIndex].counter = m_entries[newIndex].counter + 1;
        if (m_entries[newIndex].counter == 0)
          m_entries[newIndex].counter = 1;
        m_entries[newIndex].active = true;
        m_entries[newIndex].entry = object;

        ++m_activeEntryCount;

        return Handle(newIndex, m_entries[newIndex].counter, T::TYPE);
      }

      void remove(Handle handle)
      {
        const uint32_t index = handle.index;
        assert(m_entries[index].counter == handle.counter);
        assert(m_entries[index].active == true);

        m_entries[index].nextFreeIndex = m_firstFreeEntry;
        m_entries[index].active = 0;
        m_entries[index].entry = 0;
        m_firstFreeEntry = index;

        --m_activeEntryCount;
      }

      void update(Handle handle, T * object)
      {
        const uint32_t index = handle.index;
        assert(m_entries[index].counter == handle.counter);
        assert(m_entries[index].active == true);

        m_entries[index].entry = object;
      }

      void reset()
      {
        m_activeEntryCount = 0;
        m_firstFreeEntry = 0;

        for (uint32_t i = 0; i < MAX_ENTRIES - 1; ++i)
          m_entries[i] = HandleEntry(i + 1);

        m_entries[MAX_ENTRIES - 1] = HandleEntry();
        m_entries[MAX_ENTRIES - 1].endOfList = true;
      }

      bool get(Handle handle, T *& out)
      {
        const uint32_t index = handle.index;
        if (m_entries[index].counter != handle.counter ||
            m_entries[index].active == false ||
            handle.type != T::TYPE)
          return false;

        out = m_entries[index].entry;
        return true;
      }

      T * get(Handle handle)
      {
        T * object;
        if (!get(handle, object))
          return 0;
        return object;
      }

      uint32_t count() const { return m_activeEntryCount; }

    private:
      struct HandleEntry
      {
        HandleEntry()
          : nextFreeIndex(0), counter(1), active(0), endOfList(0), entry(0)
        { }

        explicit HandleEntry(uint32_t nextFreeIndex)
          : nextFreeIndex(nextFreeIndex), counter(1), active(0), endOfList(0), entry(0)
        { }

        uint32_t nextFreeIndex : 14;
        uint32_t counter : 14;
        uint32_t active : 2;
        uint32_t endOfList : 2;
        T * entry;
      };

      HandleEntry m_entries[MAX_ENTRIES];

      uint32_t m_activeEntryCount;
      uint32_t m_firstFreeEntry;
  };

}