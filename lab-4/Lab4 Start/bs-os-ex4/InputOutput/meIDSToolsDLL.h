#ifndef _MEIDSTOOLSDLL_H_
#define _MEIDSTOOLSDLL_H_

// Error codes
#define MEIDS_TOOLS_ERRNO_SUCCESS								0
#define MEIDS_TOOLS_ERRNO_WAVEGEN_SIGNAL_OUT_OF_RANGE			10001
#define MEIDS_TOOLS_ERRNO_WAVEGEN_FREQUENCY_OUT_OF_RANGE		10002
#define MEIDS_TOOLS_ERRNO_WAVEGEN_INVALID_WAVE_SHAPE			10003

// Signal forms for the function meIDSToolsWaveGen - Parameter iShape
#define MEIDS_TOOLS_WAVEGEN_SHAPE_RECTANGLE						0x10010001
#define MEIDS_TOOLS_WAVEGEN_SHAPE_TRIANGLE						0x10010002
#define MEIDS_TOOLS_WAVEGEN_SHAPE_SINUS							0x10010003
#define MEIDS_TOOLS_WAVEGEN_SHAPE_COSINUS						0x10010004
#define MEIDS_TOOLS_WAVEGEN_SHAPE_POS_RAMP						0x10010005
#define MEIDS_TOOLS_WAVEGEN_SHAPE_NEG_RAMP						0x10010006

#ifdef __cplusplus
extern "C" {
#endif

int meIDSToolsWaveGen(int iDevice, int iSubdevice, int iUnit, int iShape, double dAmplitude, double dOffset, double* pdFrequency);


#ifdef __cplusplus
}
#endif

#endif
