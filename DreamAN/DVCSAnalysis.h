#ifndef DVCSANALYSIS_H
#define DVCSANALYSIS_H
// this task related includes

#include "AnalysisTask.h"
#include "Event.h"
#include "EventCuts.h"
#include <TObject.h>
#include <iostream>

class DVCSAnalysis : public AnalysisTask {
public:
  DVCSAnalysis(); // Declare the constructor
  DVCSAnalysis(bool isMC); // Declare the constructor
  virtual ~DVCSAnalysis();
  virtual void UserCreateOutputObjects();
  void UserExec(Event &event);
  virtual void Terminate(Option_t *) {};
  void SetEventCuts(EventCuts *evtCuts) { fEventCuts = evtCuts; };

private:
  DVCSAnalysis(const DVCSAnalysis &task);
  DVCSAnalysis &operator=(const DVCSAnalysis &task);
  bool fisLightWeight;  //
  bool fIsMC;           //
  Event *fEvent;        //!
  // Track *fTrack;               //!
  EventCuts *fEventCuts; //
};
#endif // DVCSANALYSIS_H
