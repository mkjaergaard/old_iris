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

};

template<int S>
struct StaticScopeImpl<true, S>
{
  static void llog(const char* event)
  {
    llog::llog<S>(event);
  }
};

template<int SeverityEnabled>
struct StaticScope
{
  template<int Severity>
  void llog(const char* event)
  {
    StaticScopeImpl<Severity <= SeverityEnabled, Severity>::llog(event);
  }

};

}


