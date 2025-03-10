#include "DVCSAnalysis.h"

DVCSAnalysis::DVCSAnalysis()
    : fisLightWeight(false), fIsMC(false), fEvent(nullptr),
      // fTrack(nullptr),
      fEventCuts(nullptr) {
  std::cout << "Performing DVCSAnalysis Yey!" << std::endl;
}

DVCSAnalysis::DVCSAnalysis( bool isMC)
    : fisLightWeight(false), fIsMC(isMC),
      fEvent(nullptr),
      // fTrack(nullptr),
      fEventCuts(nullptr) {}

DVCSAnalysis::~DVCSAnalysis() { // Destructor (clean up if necessary)
  delete fEvent;
  // delete fTrack;
}

void DVCSAnalysis::UserCreateOutputObjects() {

  if (!fEventCuts) {
    std::cerr << "No Event cuts." << std::endl;
  } else {
  }
}

void DVCSAnalysis::UserExec(Event &event) {
  if (!event.isValid()) {
    std::cerr << "No events lol." << std::endl;
  } else {
    for (const auto &particle : event.getDetParticles()) {
      // particle.print();
    }
  }
}