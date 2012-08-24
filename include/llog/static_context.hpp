#pragma once

#include <llog/severity_type.hpp>
#include <llog/logger.hpp>

namespace llog
{

template<bool B, int S>
struct StaticScopeImpl
{
  static void llog(const char* event)
  {
  }

  template<typename T1>
  static void llog(const char* event,
		   const char* name1, const Argument<T1>& argument1)
  {
  }

  template<typename T1, typename T2>
  static void llog(const char* event,
		   const char* name1, const Argument<T1>& argument1,
		   const char* name2, const Argument<T2>& argument2)
  {
  }

  template<typename T1, typename T2, typename T3>
  static void llog(const char* event,
		   const char* name1, const Argument<T1>& argument1,
		   const char* name2, const Argument<T2>& argument2,
		   const char* name3, const Argument<T3>& argument3)
  {
  }

};

template<int S>
struct StaticScopeImpl<true, S>
{
  static void llog(const char* event)
  {
    llog::llog<S>(event);
  }

  template<typename T1>
  static void llog(const char* event,
		   const char* name1, const Argument<T1>& argument1)
  {
    llog::llog<S>(event,
		  name1, argument1);
  }

  template<typename T1, typename T2>
  static void llog(const char* event,
		   const char* name1, const Argument<T1>& argument1,
		   const char* name2, const Argument<T2>& argument2)
  {
    llog::llog<S>(event,
		  name1, argument1,
		  name2, argument2);
  }

  template<typename T1, typename T2, typename T3>
  static void llog(const char* event,
		   const char* name1, const Argument<T1>& argument1,
		   const char* name2, const Argument<T2>& argument2,
		   const char* name3, const Argument<T3>& argument3)
  {
    llog::llog<S>(event,
		  name1, argument1,
		  name2, argument2,
		  name3, argument3);
  }
};

template<int SeverityEnabled>
struct StaticScope
{
  template<int Severity>
  void llog(const char* event)
  {
    StaticScopeImpl<Severity <= SeverityEnabled, Severity>::
      llog(event);
  }

  template<int Severity, typename T1>
  void llog(const char* event,
	    const char* name1, const Argument<T1>& argument1)
  {
    StaticScopeImpl<Severity <= SeverityEnabled, Severity>::
      llog(event,
	   name1, argument1);
  }

  template<int Severity, typename T1, typename T2>
  void llog(const char* event,
	    const char* name1, const Argument<T1>& argument1,
	    const char* name2, const Argument<T2>& argument2)
  {
    StaticScopeImpl<Severity <= SeverityEnabled, Severity>::
      llog(event,
	   name1, argument1,
	   name2, argument2);
  }

  template<int Severity, typename T1, typename T2, typename T3>
  void llog(const char* event,
	    const char* name1, const Argument<T1>& argument1,
	    const char* name2, const Argument<T2>& argument2,
	    const char* name3, const Argument<T3>& argument3)
  {
    StaticScopeImpl<Severity <= SeverityEnabled, Severity>::
      llog(event,
	   name1, argument1,
	   name2, argument2,
	   name3, argument3);
  }


};

}
