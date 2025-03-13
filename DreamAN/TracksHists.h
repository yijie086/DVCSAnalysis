#ifndef TRACKSHISTS_H
#define TRACKSHISTS_H

class Tracks {
public:
    int pid;
    float px, py, pz;

    Tracks(int pid, float px, float py, float pz);
    void print() const;
};

#endif // TRACKSHISTS_H
