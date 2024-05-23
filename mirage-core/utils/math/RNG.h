//
// Created by Daniel M on 23/05/2024.
//

#ifndef RNG_H
#define RNG_H

#include <array>
#include <cstdint>
#include <random>

namespace utils::math {
    class RNG {
    public:
        RNG();

        void generateRandomBytes(std::array<uint8_t, 12> &buffer);

        void generateRandomBytes(std::vector<uint8_t> &buffer);

    private:
        std::array<uint8_t, 32> generateCombinedSeed();

        static void enhanceSeedWithLorenzEntropy(std::array<uint8_t, 32> &seed,
                                                 const std::vector<uint8_t> &lorenzEntropy);

        static std::vector<uint8_t> generateRandomizedLorenzEntropy(size_t steps,
                                                                    const std::tuple<double, double, double>
                                                                    &initialConditions);

        void shuffleSeed(std::array<uint8_t, 32> &seed);

        std::mt19937 rng_;
    };
}

#endif // RNG_H
