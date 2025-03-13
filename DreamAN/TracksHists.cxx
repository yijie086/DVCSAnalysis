#include "Tracks.h"
#include <iostream>

Tracks::Tracks(int pid, float px, float py, float pz) : pid(pid), px(px), py(py), pz(pz) {}

void Tracks::print() const {
    std::cout << "  Tracks: PID = " << pid
              << ", Px = " << px << ", Py = " << py << ", Pz = " << pz << std::endl;
}
