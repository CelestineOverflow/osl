//==============================================================================
//Copyright(c)  Meilhaus Electronic GmbH
//              http://www.meilhaus.de
//              support@meilhaus.de
//
//Source File : meerror.h                                              
//              error code constants 
//==============================================================================

#ifndef _MEERROR_H_
#define _MEERROR_H_

extern char *meErrorMsgTable[];

#define ME_ERRNO_SUCCESS                         0
#define ME_ERRNO_INVALID_DEVICE                  1
#define ME_ERRNO_INVALID_SUBDEVICE               2
#define ME_ERRNO_INVALID_CHANNEL                 3
#define ME_ERRNO_INVALID_SINGLE_CONFIG           4
#define ME_ERRNO_INVALID_REF                     5
#define ME_ERRNO_INVALID_TRIG_CHAN               6
#define ME_ERRNO_INVALID_TRIG_TYPE               7
#define ME_ERRNO_INVALID_TRIG_EDGE               8
#define ME_ERRNO_INVALID_TIMEOUT                 9
#define ME_ERRNO_INVALID_FLAGS                  10
#define ME_ERRNO_OPEN                           11
#define ME_ERRNO_CLOSE                          12
#define ME_ERRNO_NOT_OPEN                       13
#define ME_ERRNO_INVALID_DIR                    14
#define ME_ERRNO_PREVIOUS_CONFIG                15
#define ME_ERRNO_NOT_SUPPORTED                  16
#define ME_ERRNO_SUBDEVICE_TYPE                 17
#define ME_ERRNO_USER_BUFFER_SIZE               18
#define ME_ERRNO_LOCKED                         19
#define ME_ERRNO_NOMORE_SUBDEVICE_TYPE          20
#define ME_ERRNO_TIMEOUT                        21
#define ME_ERRNO_SIGNAL                         22
#define ME_ERRNO_INVALID_IRQ_SOURCE             23
#define ME_ERRNO_THREAD_RUNNING                 24
#define ME_ERRNO_START_THREAD                   25
#define ME_ERRNO_CANCEL_THREAD                  26
#define ME_ERRNO_NO_CALLBACK                    27
#define ME_ERRNO_USED                           28
#define ME_ERRNO_INVALID_UNIT                   29
#define ME_ERRNO_INVALID_MIN_MAX                30
#define ME_ERRNO_NO_RANGE                       31
#define ME_ERRNO_INVALID_RANGE                  32
#define ME_ERRNO_SUBDEVICE_BUSY                 33
#define ME_ERRNO_INVALID_LOCK                   34
#define ME_ERRNO_INVALID_SWITCH                 35
#define ME_ERRNO_INVALID_ERROR_MSG_COUNT        36
#define ME_ERRNO_INVALID_STREAM_CONFIG          37
#define ME_ERRNO_INVALID_CONFIG_LIST_COUNT      38
#define ME_ERRNO_INVALID_ACQ_START_TRIG_TYPE    39
#define ME_ERRNO_INVALID_ACQ_START_TRIG_EDGE    40
#define ME_ERRNO_INVALID_ACQ_START_TRIG_CHAN    41
#define ME_ERRNO_INVALID_ACQ_START_TIMEOUT      42
#define ME_ERRNO_INVALID_ACQ_START_ARG          43
#define ME_ERRNO_INVALID_SCAN_START_TRIG_TYPE   44
#define ME_ERRNO_INVALID_SCAN_START_ARG         45
#define ME_ERRNO_INVALID_CONV_START_TRIG_TYPE   46
#define ME_ERRNO_INVALID_CONV_START_ARG         47
#define ME_ERRNO_INVALID_SCAN_STOP_TRIG_TYPE    48
#define ME_ERRNO_INVALID_SCAN_STOP_ARG          49
#define ME_ERRNO_INVALID_ACQ_STOP_TRIG_TYPE     50
#define ME_ERRNO_INVALID_ACQ_STOP_ARG           51
#define ME_ERRNO_SUBDEVICE_NOT_RUNNING          52
#define ME_ERRNO_INVALID_READ_MODE              53
#define ME_ERRNO_INVALID_VALUE_COUNT            54
#define ME_ERRNO_INVALID_WRITE_MODE             55
#define ME_ERRNO_INVALID_TIMER                  56
#define ME_ERRNO_DEVICE_UNPLUGGED               57
#define ME_ERRNO_USED_INTERNAL                  58
#define ME_ERRNO_INVALID_DUTY_CYCLE             59
#define ME_ERRNO_INVALID_WAIT                   60
#define ME_ERRNO_CONNECT_REMOTE                 61
#define ME_ERRNO_COMMUNICATION                  62
#define ME_ERRNO_INVALID_SINGLE_LIST            63
#define ME_ERRNO_INVALID_MODULE_TYPE            64
#define ME_ERRNO_INVALID_START_MODE             65
#define ME_ERRNO_INVALID_STOP_MODE              66
#define ME_ERRNO_INVALID_FIFO_IRQ_THRESHOLD     67
#define ME_ERRNO_INVALID_POINTER                68
#define ME_ERRNO_CREATE_EVENT                   69
#define ME_ERRNO_LACK_OF_RESOURCES              70
#define ME_ERRNO_CANCELLED                      71
#define ME_ERRNO_RING_BUFFER_OVERFLOW           72
#define ME_ERRNO_SOFTWARE_BUFFER_OVERFLOW       ME_ERRNO_RING_BUFFER_OVERFLOW
#define ME_ERRNO_RING_BUFFER_UNDERFLOW          73
#define ME_ERRNO_RING_BUFFER_UNDEFFLOW          ME_ERRNO_RING_BUFFER_UNDERFLOW
#define ME_ERRNO_SOFTWARE_BUFFER_UNDERFLOW      ME_ERRNO_RING_BUFFER_UNDERFLOW
#define ME_ERRNO_INVALID_IRQ_EDGE               74
#define ME_ERRNO_INVALID_IRQ_ARG                75
#define ME_ERRNO_INVALID_CAP                    76
#define ME_ERRNO_INVALID_CAP_ARG_COUNT          77
#define ME_ERRNO_INTERNAL                       78
#define ME_ERRNO_VALUE_OUT_OF_RANGE             79
#define ME_ERRNO_HARDWARE_FIFO_OVERFLOW         80
#define ME_ERRNO_HARDWARE_BUFFER_OVERFLOW       ME_ERRNO_HARDWARE_FIFO_OVERFLOW
#define ME_ERRNO_HARDWARE_FIFO_UNDERFLOW        81
#define ME_ERRNO_HARDWARE_FIFO_UNDEFFLOW        ME_ERRNO_HARDWARE_FIFO_UNDERFLOW
#define ME_ERRNO_HARDWARE_BUFFER_UNDERFLOW      ME_ERRNO_HARDWARE_FIFO_UNDERFLOW
#define ME_ERRNO_CONFIG_LOAD_FAILED				82
#define ME_ERRNO_PROPERTY_CONTAINER             83
#define ME_ERRNO_PROPERTY_NOT_A_CONTAINER       84
#define ME_ERRNO_PROPERTY_DATA_TYPE             85
#define ME_ERRNO_PROPERTY_PATH                  86
#define ME_ERRNO_PROPERTY_INDEX                 87
#define ME_ERRNO_PROPERTY_BUFFER_TOO_SMALL      88
#define ME_ERRNO_PROPERTY_UNKNOWN				89
#define ME_ERRNO_PROPERTY_ATTRIBUTE_UNKNOWN		90
#define ME_ERRNO_PROPERTY_ATTRIBUTE_UNSUPPORTED	91
#define ME_ERRNO_PROPERTY_SELECTION_INVALID		92
#define ME_ERRNO_PROPERTY_VALUE_INVALID			93
#define ME_ERRNO_PROPERTY_READ_ONLY				94


#define ME_ERRNO_INVALID_ERROR_NUMBER           95  //ME_ERRNO_INVALID_ERROR_NUMBER is always the greatest error constant

#endif
