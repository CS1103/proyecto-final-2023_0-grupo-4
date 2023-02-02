
#include "Utils.hpp"

#include <random>
#include <stdexcept>

namespace Utils {

using std::uniform_int_distribution;
using std::uniform_real_distribution;

template <std::integral T> T RandomNum(const T &min, const T &max) {
  if (min >= max) {
    throw std::invalid_argument(
        "El primer valor del rango debe ser menor al segundo");
  }

  std::random_device r_d;
  std::default_random_engine generator(r_d());

  uniform_int_distribution<T> rand_num(min, max);

  return rand_num(generator);
}
template <std::floating_point T> T RandomNum(const T &min, const T &max) {
  if (min >= max) {
    throw std::invalid_argument(
        "El primer valor del rango debe ser menor al segundo");
  }

  std::random_device r_d;
  std::default_random_engine generator(r_d());

  uniform_real_distribution<T> rand_num(min, max);

  return rand_num(generator);
}

// explicit instantiation

template uint8_t RandomNum<uint8_t>(const uint8_t &min, const uint8_t &max);
template size_t RandomNum<size_t>(const size_t &min, const size_t &max);
template int RandomNum<int>(const int &min, const int &max);

} // namespace Utils
