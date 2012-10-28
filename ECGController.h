#pragma once

#include "ECGSignal.h"
#include "ECGRs.h"
#include "ECGWaves.h"
#include "ECGHRV1.h"
#include "ECGHRV2.h"
#include "ECGHRVDFA.h"
#include "ECGClasses.h"
#include "ECGHRT.h"
#include "ECGST.h"
#include "ECGTWave.h"

#include "ModulesInterfaces.h"
#include "ModulesMethods.h"

/**
 * @class Class which controls executing all modules.
 */
class ECGController
{
public:
  ECGController (void);
  ~ECGController (void);

  void setParamsECGBaseline(ParametersTypes & params);
  void setParamsRPeaks(ParametersTypes & params);
  void setParamsnWaves(ParametersTypes & params);
  void setParamsHRV1(ParametersTypes & params);
  void setParamsHRV2(ParametersTypes & params);
  void setParamsHRVDFA(ParametersTypes & params);
  void setParamsQRSClass(ParametersTypes & params);
  void setParamsSTInterval(ParametersTypes & params);
  void setParamsTwaveAlt(ParametersTypes & params);
  void setParamsHRT(ParametersTypes & params);
  
  void runECGBaseline();
  void runRPeaks();
  void runWaves();
  void runHRV1();
  void runHRV2();
  void runHRVDFA();
  void runQRSClass();
  void runSTInterval();
  void runTwaveAlt();
  void runHRT();

  void setECGBaselineNotRunned();
  void setRPeaksNotRunned();
  void setWavesNotRunned();
  void setHRV1NotRunned();
  void setHRV2NotRunned();
  void setHRVDFANotRunned();
  void setQRSClassNotRunned();
  void setSTIntervalNotRunned();
  void setTwaveAltNotRunned();
  void setHRTNotRunned();

private:
  //data
  ECGSignal raw_signal;
  ECGSignal filtered_signal;
  ECGRs r_peaks_data;
  ECGWaves waves_data;
  ECGHRV1 hrv1_data;
  ECGHRV2 hrv2_data;
  ECGHRVDFA hrv_dfa_data;
  ECGClasses classes_data;
  ECGST st_data;
  ECGTWave twave_data;
  ECGHRT hrt_data;

  //modules
  ECGBaselineModule *ecg_baseline_module;
  RPeaksModule *rpeaks_module;
  WavesModule *waves_module;
  HRV1Module *hrv1_module;
  HRV2Module *hrv2_module;
  HRVDFAModule *hrv_dfa_module;
  QRSClassModule *qrs_class_module;
  STIntervalModule *st_interval_module;
  TWaveAltModule *t_wave_alt_module;
  HRTModule *hrt_module;
};
