#ifndef TRACKCUTS_H_
#define TRACKCUTS_H_
#include "Event.h"
#include "TrackHists.h"

class TrackCuts {
 public:
  TrackCuts();
  TrackCuts(const TrackCuts& cuts);
  TrackCuts &operator=(const TrackCuts& cuts);
  virtual ~TrackCuts();

  static TrackCuts *PhotonCuts();
  static TrackCuts *ElectronCuts();
  static TrackCuts *ProtonCuts();

 
    void SetMomentumCut(float minP, float maxP){
        fPmin = minP;
        fPmax = maxP;
        fcutP = true;
    };
    void SetVtxX(float minVx, float maxVx){
        fVtXmin = minVx;
        fVtXmax = maxVx;
    };
    void SetVtxY(float minVy, float maxVy){
        fVtYmin = minVy;
        fVtYmax = maxVy;
    };
    void SetVtxZ(float minVz, float maxVz){
        fVtZmin = minVz;
        fVtZmax = maxVz;
    };
    void SetPIDCut(int pid = -999, float chiSquaredVal =-999){
        fPdg = pid;
        fChiSquared = chiSquaredVal; // this is the chiSquared for the particle/// looking at DVCS Analysis note
        fcutPID = kTRUE;
    };
    void SetChargeCut(int charge){
        fCharge = charge;
        };

    // Check if a track passes all cuts
    bool isSelected(const  clas12::region_part_ptr &Track);
    bool TrackingCuts(const  clas12::region_part_ptr &track);
    bool PIDCuts(const clas12::region_part_ptr &track);
    void BookQA(const clas12:: region_part_ptr &Track);

private:
    bool fMinimalBooking;               
    int  fPdg;
    bool  fcutPID;
    int   fCharge;
    float fPmin;
    float fPmax;
    float fcutP;
    float fVtXmin;
    float fVtXmax;
    float fVtYmin;
    float fVtYmax;
    float fVtZmin;
    float fVtZmax;
    float fChiSquared;

    TrackHists *fHists;    

    

    // Individual cut functions
    bool PassesMomentumCut(const std::shared_ptr<clas12::particle>& track) const;
    bool PassesVertexCut(const std::shared_ptr<clas12::particle>& track) const;
    bool PassesPIDCut(const std::shared_ptr<clas12::particle>& track) const;
    bool PassesChargeCut(const std::shared_ptr<clas12::particle>& track) const;
};

#endif // TRACKCUTS_H
