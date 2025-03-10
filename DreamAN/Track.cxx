#include "Track.h"
#include <iostream>

Track::Track(double energy, double momentum)
    : energy(energy), momentum(momentum) {}

std::string Track::identify() const {
    if (momentum > energy) {
        return "Unphysical particle";
    } else if (energy > 1000) {
        return "High-energy particle";
    } else {
        return "Low-energy particle";
    }
}
