#ifndef FIRSTDVCSANALYSIS_H
#define FIRSTDVCSANALYSIS_H

#include <string>

class FirstDVCSanalysis{
public:
    Track(double energy, double momentum);
    std::string identify() const;

private:
    double energy;
    double momentum;
};

#endif //  FIRSTDVCSANALYSIS_H