#include <beam/static_scope.hpp>

extern const char some_name[] = "mscope";

class myclass : public beam::static_scope<beam::Info, some_name>
{
public:
  void test()
  {
    slog<beam::Info>("hej");
  }

};

int main(int argc, char ** argv)
{
  myclass a;
  a.test();
}
