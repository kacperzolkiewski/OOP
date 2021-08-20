#include "File.h"

void File::print(const int spaces) const {
  for(int i = 0; i < spaces; i++) {
    std::cout << " ";
  }
  std::cout << getName() << " (FILE)" << std::endl;
}