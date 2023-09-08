/*
 * cbmstate.h
 *
 *  Created on: Dec 5, 2012
 *      Author: consciousness
 */

#ifndef CBMSTATE_H_
#define CBMSTATE_H_

#include <fstream>
#include <iostream>
#include <limits.h>
#include <time.h>

#include "activityparams.h"
#include "connectivityparams.h" // <-- added in 06/01/2022
#include "innetactivitystate.h"
#include "innetconnectivitystate.h"
#include "mzoneactivitystate.h"
#include "mzoneconnectivitystate.h"
#include <cstdint>

class CBMState {
public:
  CBMState();
  CBMState(unsigned int nZones);
  // TODO: make a choice which of two below constructors want to keep
  CBMState(unsigned int nZones, std::fstream &sim_file_buf);
  // CBMState(unsigned int nZones, std::string inFile);
  ~CBMState();

  void readState(std::fstream &infile);
  void writeState(std::fstream &outfile);

  uint32_t getNumZones();

  InNetActivityState *getInnetActStateInternal();
  MZoneActivityState *getMZoneActStateInternal(unsigned int zoneN);

  InNetConnectivityState *getInnetConStateInternal();
  MZoneConnectivityState *getMZoneConStateInternal(unsigned int zoneN);

private:
  uint32_t numZones;

  InNetConnectivityState *innetConState;
  MZoneConnectivityState **mzoneConStates;

  InNetActivityState *innetActState;
  MZoneActivityState **mzoneActStates;
};

#endif /* CBMSTATE_H_ */
