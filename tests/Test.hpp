
#pragma once

#include <stdarg.h>
#include <stdio.h>

namespace test {

  class Test;

  namespace {
    static Test * _testHead = NULL;
    static Test * _testTail = NULL;
  }

  class Test
  {
    public:
      Test(const char * name)
        : m_name(name),
          m_next(NULL)
      {
        if (_testHead)
        {
          _testTail->m_next = this;
          _testTail = this;
        }
        else
        {
          _testHead = this;
          _testTail = this;
        }
      }

      virtual void run() = 0;

      Test * next() const { return m_next; }
      const char * name() const { return m_name; }

    private:
      const char * m_name;
      Test * m_next;
  };

  class Exception
  {
    public:
      Exception(const char * str, ...)
      {
        va_list varArg;
        va_start(varArg, str);
        vsnprintf(m_message, 128, str, varArg);
        va_end(varArg);
      }

      const char * message() const { return m_message; }

    private:
      char m_message[128];
  };

  int runAllTests()
  {
    bool failed = false;
    int totalCount = 0;
    for (Test * it = _testHead; it; it = it->next())
      totalCount++;

    int i = 1;
    for (Test * it = _testHead; it; it = it->next())
    {
      printf("[%d/%d] %s - ", i, totalCount, it->name());

      try
      {
        it->run();
        printf("SUCCESS\n");
      }
      catch (Exception const& exception)
      {
        printf("FAILED\n");
        printf("  %s\n", exception.message());
        failed = true;
      }

      i++;
    }

    return failed ? 1 : 0;
  }
}


#define TEST(group, name) class group##_##name##_Test : test::Test \
                          { \
                            public: \
                              group##_##name##_Test(const char * name) \
                                : Test(name) \
                              { } \
                              void run(); \
                          }; \
                          static group##_##name##_Test __test_##group##_##name##__(#group"::"#name); \
                          void group##_##name##_Test::run()

#define CHECK(expr) do { \
                      if (!(expr)) throw test::Exception("%s(%d): %s", __FILE__, __LINE__, #expr); \
                    } while (0)

#define CHECK_TRUE(expr) do { \
                           if (!(expr)) throw test::Exception("%s(%d): %s", __FILE__, __LINE__, #expr); \
                         } while (0)

#define CHECK_FALSE(expr) do { \
                            if (expr) throw test::Exception("%s(%d): %s", __FILE__, __LINE__, #expr); \
                          } while (0)

#define CHECK_EQ(arg, expected) do {                                                         \
                                  if ((arg) != (expected)) throw test::Exception("%s(%d): %s == %s", __FILE__, __LINE__, #arg, #expected);  \
                                } while (0)

