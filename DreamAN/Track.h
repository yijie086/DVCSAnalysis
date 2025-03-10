#ifndef TRACK_H
#define TRACK_H

#include <string>

class Track {
public:
    Track(double energy, double momentum);
    std::string identify() const;

private:
    double energy;
    double momentum;
};

#endif // TRACK_H
