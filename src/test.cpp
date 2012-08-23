#include <llog/static_context.hpp>
#include <llog/severity_type.hpp>

struct Tester : public llog::StaticScope<llog::Severity::Warning>
{

  void doit()
  {
    llog<llog::Severity::Debug>("1");
    llog<llog::Severity::Fatal>("1");
  }

};

int main(int arc, char** argv)
{
  Tester t;
  t.doit();
  return 0;
}
