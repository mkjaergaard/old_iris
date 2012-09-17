#include <beam/static_scope.hpp>
#include <beam/severity_type.hpp>

struct Tester : public beam::static_scope<beam::Warning>
{
  void doit()
  {
    slog<beam::Debug>("1");
    slog<beam::Fatal>("1");
  }

};

int main(int arc, char** argv)
{
  beam::glog<beam::Warning>("Global Test");
  beam::glog<beam::Warning>("Global Test 2",
			    "Arg1", beam::arg<int>(5));

  Tester t;
  t.doit();
  return 0;
}
