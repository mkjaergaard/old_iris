#include <beam/glog.hpp>

namespace beam
{

inline
void assert_failed(const char* func, const char* file, int line)
{
  beam::glog<beam::Fatal>("Assertion Failed",
			  "function", arg<const char*>(func),
			  "file", arg<const char*>(file),
			  "line", arg<int>(line));
  abort();
}

template<typename T1>
void assert_failed(const char* func, const char* file, int line,
		   const char* name1, const arg<T1>& argument1)
{
  beam::glog<beam::Fatal>("Assertion Failed",
			  "function", arg<const char*>(func),
			  "file", arg<const char*>(file),
			  "line", arg<int>(line),
			  name1, argument1);
  abort();
}

inline
void test_assert(bool condition,
		 const char* func,
		 const char* file,
		 int line)
{
  ((condition)
   ? __ASSERT_VOID_CAST(0)
   : beam::assert_failed(func, file, line));
}

template<typename T1>
void test_assert(bool condition,
		 const char* func,
		 const char* file,
		 int line,
		 const char* name1, const arg<T1>& argument1)
{
  ((condition)
   ? __ASSERT_VOID_CAST(0)
   : beam::assert_failed(func, file, line, name1, argument1));
}

}

#define BEAM_ASSERT(c)\
  beam::test_assert((c), BOOST_CURRENT_FUNCTION, __FILE__, __LINE__)

#define BEAM_ASSERT_1(x, a1, v1)\
  beam::test_assert((x), BOOST_CURRENT_FUNCTION, __FILE__, __LINE__, a1, v1)

