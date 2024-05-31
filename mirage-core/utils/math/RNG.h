#ifndef RNG_H
#define RNG_H

#include <array>
#include <cstdint>
#include <random>
#include <sodium.h>

namespace utils::math {
 /**
  * @class RNG
  * @brief A class for generating random numbers with enhanced entropy.
  *
  * This class utilizes both the standard random number generation and additional entropy
  * from the Lorenz attractor to provide high-quality random numbers. It also uses libsodium
  * for secure random number generation and memory handling.
  */
 class RNG {
 public:
  /**
   * @brief Constructs a new RNG object and seeds the random number generator.
   *
   * Initializes libsodium and seeds the std::mt19937 random number generator using a combination
   * of std::random_device and std::seed_seq.
   */
  RNG();

  /**
   * @brief Generates random numbers of the specified integral type.
   *
   * This method generates random numbers of the specified integral type. The count parameter
   * specifies the number of random numbers to generate. The method uses a combination of
   * generated seed, Lorenz entropy, and std::mt19937 to fill a buffer with random bytes.
   *
   * @tparam T The integral type of the random number to generate.
   * @param count The number of random numbers to generate (default is 1).
   * @return A random number of the specified integral type.
   */
  template<typename T>
  T random(size_t count = 1);

 private:
  /**
   * @brief Generates a seed for the random number generator.
   *
   * This method generates a 32-byte seed by combining operating system entropy and
   * additional entropy from std::mt19937.
   *
   * @return A 32-byte array containing the generated seed.
   */
  std::array<uint8_t, 32> generateSeed();

  /**
   * @brief Mixes the generated seed with Lorenz entropy.
   *
   * This method enhances the provided seed by mixing it with entropy derived from the
   * Lorenz attractor. The enhanced seed provides better randomness for cryptographic purposes.
   *
   * @param seed A reference to the seed array to be mixed with Lorenz entropy.
   */
  static void mixSeedWithLorenzEntropy(std::array<uint8_t, 32> &seed);

  /**
   * @brief Fills a buffer with random bytes.
   *
   * This method fills the provided buffer with random bytes using a uniform distribution.
   * The buffer is filled with random values generated by std::mt19937.
   *
   * @tparam T The type of the buffer to fill with random bytes.
   * @param buffer The buffer to be filled with random bytes.
   * @param size The size of the buffer.
   */
  template<typename T>
  void fillBufferWithRandomBytes(T &buffer, size_t size);

  std::mt19937 rng_; /**< Mersenne Twister random number generator. */
 };
} // namespace utils::math

#endif // RNG_H
