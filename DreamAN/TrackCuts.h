#ifndef TRACKCUTS_H_
#define TRACKCUTS_H_
#include "Event.h"

class TrackCuts {
 public:
  TrackCuts();
  TrackCuts(const TrackCuts& cuts);
  TrackCuts &operator=(const TrackCuts& cuts);
  virtual ~TrackCuts();

    void SetPtRangeCut(float minPt, float maxPt) {
        fpTmin = minPt;
        fpTmax = maxPt;
    };
    void SetMomentumCut(float minP, float maxP){
        fPmin = minP;
        fPmax = maxP;
    };
    void SetVertexZCut(float minVz, float maxVz){
        fVtZmin = minVz;
        fVtZmax = maxVz;
    };
    void SetPIDCut(int pid){
        fPID = pid;
    };
    void SetChargeCut(int charge){
        fCharge = charge;
        };

    // Check if a track passes all cuts
    bool isSelected(const std::shared_ptr<clas12::particle>& track);

    bool TrackingCuts(const std::shared_ptr<clas12::particle> &track);
    bool PIDCuts(const std::shared_ptr<clas12::particle> &track);

private:
    float fPmin;
    float fPmax;
    float fpTmin;
    float fpTmax;
    float fcutPt;
    float fVtZmin;
    float fVtZmax;
    bool  fPID;
    int fCharge;

    // Individual cut functions
    bool PassesMomentumCut(const std::shared_ptr<clas12::particle>& track) const;
    bool PassesVertexCut(const std::shared_ptr<clas12::particle>& track) const;
    bool PassesPIDCut(const std::shared_ptr<clas12::particle>& track) const;
    bool PassesChargeCut(const std::shared_ptr<clas12::particle>& track) const;
};

#endif // TRACKCUTS_H
