#include <iostream>
#include "CLRS/core/internal.hpp"

namespace CLRS {

template <typename Printable, typename OStream = std::ostream,
          typename =
              std::enable_if_t<internal::has_shl<OStream, Printable>::value>>
class Printer {
 public:
  Printer(OStream& os) : os{os} {}

  inline OStream& operator()(const Printable& printable) {
    return os << printable;
  }

 private:
  OStream& os;
};  // class Printer

}  // namespace CLRS
