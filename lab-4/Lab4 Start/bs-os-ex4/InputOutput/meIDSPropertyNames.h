//==============================================================================
//Copyright(c)  Meilhaus Electronic GmbH
//              http://www.meilhaus.de
//              support@meilhaus.de
//
//Source File : meIDSPropertyNames.h
//              defines for properties used in ME-iDS, ANSI format
//==============================================================================

#ifndef _MEIDSPROPERTYNAMES_H_
#define _MEIDSPROPERTYNAMES_H_

//=================================================================
// Attributes
//=================================================================

#define ME_ATTRIBUTE_NAME_NUMBER_OF_ELEMENTS                     "NumberOfElements"

#define ME_ATTRIBUTE_NAME_PROPERTY_NAME                          "PropertyName"

#define ME_ATTRIBUTE_NAME_PROPERTY_TYPE                          "PrpertyType"

#define ME_ATTRIBUTE_NAME_PROPERTY_ACCESS                        "PropertyAccess"

#define ME_ATTRIBUTE_NAME_PROPERTY_DESCRIPTION                   "PropertyDescription"

#define ME_ATTRIBUTE_NAME_MIN_VALUE                              "MinValue"

#define ME_ATTRIBUTE_NAME_MAX_VALUE                              "MaxValue"

#define ME_ATTRIBUTE_NAME_LENGTH                                 "Length"

#define ME_ATTRIBUTE_NAME_MAX_LENGTH                             "MaxLength"

#define ME_ATTRIBUTE_NAME_NUMBER_OF_SELECTIONS                   "NumberOfSelections"

#define ME_ATTRIBUTE_NAME_PREFIX_SELECTION                       "Selection"    // The selection with index # is  "Selection#"

//=================================================================
// Root container (system container)
//=================================================================

#define ME_CONTAINER_NAME_ROOT                                   "\\\\" 

//=================================================================
// System properties and containers
//=================================================================

#define ME_PROPERTY_NAME_LIBRARY_VERSION                         "LibraryVersion"

#define ME_PROPERTY_NAME_MAIN_DRIVER_VERSION                     "MainDriverVersion"

#define ME_PROPERTY_NAME_NUMBER_OF_DEVICES                       "NumberOfDevices"

#define ME_CONTAINER_NAME_DEVICES                                "Devices"

//=================================================================
// General device properties and containers - not device specific
//=================================================================

#define ME_CONTAINER_NAME_PREFIX_DEVICE                          "Device"   // The container name for the device with index # is  "Device#"

#define ME_PROPERTY_NAME_NAME                                    "Name"

#define ME_PROPERTY_NAME_DRIVER_NAME                             "DriverName"

#define ME_PROPERTY_NAME_DRIVER_VERSION                          "DriverVersion"

#define ME_PROPERTY_NAME_DESCRIPTION                             "Description"

#define ME_PROPERTY_NAME_SERIAL_NUMBER                           "SerialNumber"

#define ME_PROPERTY_NAME_BUS_TYPE                                "BusType"

#define ME_PROPERTY_NAME_ACCESS_TYPE                             "AccessType"

#define ME_PROPERTY_NAME_PLUGGED                                 "Plugged"

#define ME_PROPERTY_NAME_FIRMWARE_SELECTABLE                     "FirmwareSelectable"

#define ME_PROPERTY_NAME_CURRENT_FIRMWARE_ID                     "CurrentFirmwareID"

#define ME_PROPERTY_NAME_NUMBER_OF_SUBDEVICES                    "NumberOfSubdevices"

#define ME_CONTAINER_NAME_SUBDEVICES                             "Subdevices"

//=================================================================
// Additional properties for PCI devices
//=================================================================

#define ME_PROPERTY_NAME_PCI_VENDOR_ID                           "PCIVendorID"

#define ME_PROPERTY_NAME_PCI_DEVICE_ID                           "PCIDeviceID"

#define ME_PROPERTY_NAME_PCI_BUS_NUMBER                          "PCIBusNumber"

#define ME_PROPERTY_NAME_PCI_SLOT_NUMBER                         "PCISlotNumber"

#define ME_PROPERTY_NAME_PCI_FUNCTION_NUMBER                     "PCIFunctionNumber"

//=================================================================
// General sub-device properties and containers - not sub-device specific
//=================================================================

#define ME_CONTAINER_NAME_PREFIX_SUBDEVICE                       "Subdevice"    // The container name for the sub-device with index # is  "Subdevice#"

#define ME_PROPERTY_NAME_TYPE                                    "Type"

#define ME_PROPERTY_NAME_SUBTYPE                                 "Subtype"

#define ME_PROPERTY_NAME_NUMBER_OF_CHANNELS                      "NumberOfChannels"

#define ME_PROPERTY_NAME_CONFIGURABLE                            "Configurable"

#define ME_PROPERTY_NAME_NUMBER_OF_CONFIGURATIONS                "NumberOfConfigurations"

#define ME_PROPERTY_NAME_CURRENT_CONFIGURATION                   "CurrentConfiguration"

#define ME_CONTAINER_NAME_CHANNELS                               "Channels"

#define ME_CONTAINER_NAME_PREFIX_CHANNEL                         "Channe "          // The container name for the channel with index # is  "Channel#"

#define ME_CONTAINER_NAME_CONFIGURATIONS                         "Configurations"

#define ME_CONTAINER_NAME_PREFIX_CONFIGURATION                   "Configuration"    // The container name for the configuration with index # is  "Configuration#"

//=================================================================
// Configuration properties
//=================================================================

#define ME_PROPERTY_NAME_SUBDEVICE_TYPE                          "SubdeviceType"

#define ME_PROPERTY_NAME_SUBDEVICE_SUBTYPE                       "SubdeviceSubtype"

#define ME_PROPERTY_NAME_SUBDEVICE_NUMBER_OF_CHANNELS            "SubdeviceNumberOfChannels"

//=================================================================
// ME-5100 and ME-5001 - additional device properties
//=================================================================

#define ME_PROPERTY_NAME_IO_PIN_VOLTAGE_LEVEL                    "IOPinVoltageLeve "

#define ME_PROPERTY_NAME_SUBDEVICES_0_AND_1_TERMINATED           "Subdevice0And1Terminated"

#define ME_PROPERTY_NAME_SUBDEVICES_2_AND_3_TERMINATED           "Subdevice2And3Terminated"

//=================================================================
// Additional sub-device properties for various sub-device types
//=================================================================

#define ME_PROPERTY_NAME_TERMINATED                              "Terminated"

#define ME_PROPERTY_NAME_SYSTEM_CLOCK_FREQUENCY                  "SystemClockFrequency"

//=================================================================
// Additional sub-device properties and containers for AI, DI, DO sub-device types
//=================================================================

#define ME_PROPERTY_NAME_TRIGGER_TYPE                            "TriggerType"

#define ME_PROPERTY_NAME_PREFIX_RISING_EDGE_BIT                  "RisingEdgeBit"    // The name for the trigger condition on bit # is  "RisingEdgeBit#"

#define ME_PROPERTY_NAME_PREFIX_FALLING_EDGE_BIT                 "FallingEdgeBit"   // The name for the trigger condition on bit # is  "FallngEdgeBit#"

#define ME_PROPERTY_NAME_INTERNAL_BUFFER_SIZE                    "InternalBufferSize"

#define ME_PROPERTY_NAME_SAMPLE_FREQUENCY                        "SampleFrequency"

#define ME_PROPERTY_NAME_SAMPLE_TIME                             "SampleTime"

#define ME_PROPERTY_NAME_START_TRIGGER_TYPE                      "StartTriggerType"

#define ME_PROPERTY_NAME_CONV_TRIGGER_TYPE                       "ConvTriggerType"

#define ME_PROPERTY_NAME_STOP_TRIGGER_TYPE                       "StopTriggerType"

#define ME_PROPERTY_NAME_START_STOP_PATTERN                      "StartStopPattern"

#define ME_PROPERTY_NAME_STOP_ON_COUNT                           "StopOnCount"

#define ME_PROPERTY_NAME_STOP_COUNT                              "StopCount"

#define ME_CONTAINER_NAME_INTERRUPT_CONDITION                    "InterruptCondition"

#define ME_CONTAINER_NAME_SINGLE_CONFIGURATION                   "SingleConfiguration"

#define ME_CONTAINER_NAME_EXT_DIGITAL_TRIGGER_CONDITION          "ExtDigitalTriggerCondition"

#define ME_CONTAINER_NAME_STREAMING_CONFIGURATION                "StreamingConfiguration"

#define ME_CONTAINER_NAME_START_AND_CONV_TRIGGER_CONDITION       "StartAndConvTriggerCondition"

#define ME_CONTAINER_NAME_STOP_TRIGGER_CONDITION                 "StopTriggerCondition"

#define ME_CONTAINER_NAME_IRQ_CONFIGURATION                      "IRQConfiguration"

//=================================================================
// Additional sub-device properties for AI sub-device types
//=================================================================

#define ME_PROPERTY_NAME_CALIBRATION                             "Calibration"

#define ME_PROPERTY_NAME_RISING_EDGE_TRIGGER_A1                  "RisingEdgeTriggerA1"

#define ME_PROPERTY_NAME_FALLING_EDGE_TRIGGER_A1                 "FallingEdgeTriggerA1"

#define ME_PROPERTY_NAME_RISING_EDGE_TRIGGER_A2                  "RisingEdgeTriggerA2"

#define ME_PROPERTY_NAME_FALLING_EDGE_TRIGGER_A2                 "FallingEdgeTriggerA2"

#define ME_PROPERTY_NAME_ACQUIRE_CHANNEL                         "AcquireChanne "

//=================================================================
// Additional sub-device properties and containers for DI sub-device types
//=================================================================

#define ME_PROPERTY_NAME_RISING_EDGE_TRIGGER_A                   "RisingEdgeTriggerA"

#define ME_PROPERTY_NAME_FALLING_EDGE_TRIGGER_A                  "FallingEdgeTriggerA"

#define ME_PROPERTY_NAME_USE_INTERNAL_TEST_COUNTER               "UseInternalTestCounter"

#define ME_PROPERTY_NAME_TRANSFER_SIZE                           "TransferSize"

#define ME_PROPERTY_NAME_IRQ_SOURCE                              "IRQSource"

#define ME_PROPERTY_NAME_BIT_PATTERN                             "BitPattern"

#define ME_PROPERTY_NAME_BIT_PATTERN_FILTERING                   "BitPatternFiltering"

#define ME_PROPERTY_CONTAINER_BIT_MASK                           "BitMask"

//=================================================================
// Additional sub-device properties and containers forDO sub-device types
//=================================================================

#define ME_PROPERTY_NAME_RISING_EDGE_TRIGGER_B                   "RisingEdgeTriggerB"

#define ME_PROPERTY_NAME_FALLING_EDGE_TRIGGER_B                  "FallingEdgeTriggerB"

#define ME_PROPERTY_NAME_IRQ_ON_EXCESS_TEMPERATURE               "IRQOnExcessTemperature"

#define ME_PROPERTY_NAME_IRQ_ON_NORMAL_TEMPERATURE               "IRQOnNormalTemperature"

#define ME_PROPERTY_NAME_STOP_PATTERN                            "StopPattern"

#define ME_PROPERTY_NAME_WRAPAROUND                              "Wraparound"

#define ME_PROPERTY_NAME_WRAPAROUND_LOOPS                        "WraparoundLoops"

//=================================================================
// Additional sub-device properties and containers for DO and FO sub-device types
//=================================================================

#define ME_PROPERTY_NAME_OUTPUT_MODE                             "OutputMode"

//=================================================================
// Additional sub-device properties and containers for DIO sub-device types
//=================================================================

#define ME_PROPERTY_NAME_DIRECTION                               "Direction"

//=================================================================
// Additional sub-device properties FI sub-device types
//=================================================================

#define ME_PROPERTY_NAME_MIN_MEASURABLE_TOTAL_TICKS              "MinMeasurableTotalTicks"

#define ME_PROPERTY_NAME_MAX_MEASURABLE_TOTAL_TICK               "MaxMeasurableTotalTicks"

#define ME_PROPERTY_NAME_MIN_MEASURABLE_FIRST_PHASE_TICKS        "MinMeasurableFirstPhaseTicks"

#define ME_PROPERTY_NAME_MAX_MEASURABLE_FIRST_PHASE_TICKS        "MaxMeasurableFirstPhaseTicks"

#define ME_PROPERTY_NAME_MIN_MEASURABLE_TOTAL_TIME               "MinMeasurableTotalTime"

#define ME_PROPERTY_NAME_MAX_MEASURABLE_TOTAL_TIME               "MaxMeasurableTotalTime"

#define ME_PROPERTY_NAME_MIN_MEASURABLE_FIRST_PHASE_TIME         "MinMeasurableFirstPhaseTime"

#define ME_PROPERTY_NAME_MAX_MEASURABLE_FIRST_PHASE_TIME         "MaxMeasurableFirstPhaseTime"

//=================================================================
// Additional sub-device properties for FO sub-device types
//=================================================================

#define ME_PROPERTY_NAME_MIN_TOTAL_TICKS                         "MinTotalTicks"

#define ME_PROPERTY_NAME_MAX_TOTAL_TICK                          "MaxTotalTicks"

#define ME_PROPERTY_NAME_MIN_FIRST_PHASE_TICKS                   "MinFirstPhaseTicks"

#define ME_PROPERTY_NAME_MAX_FIRST_PHASE_TICKS                   "MaxFirstPhaseTicks"

#define ME_PROPERTY_NAME_MIN_TOTAL_TIME                          "MinTotalTime"

#define ME_PROPERTY_NAME_MAX_TOTAL_TIME                          "MaxTotalTime"

#define ME_PROPERTY_NAME_MIN_FIRST_PHASE_TIME                    "MinFirstPhaseTime"

#define ME_PROPERTY_NAME_MAX_FIRST_PHASE_TIME                    "MaxFirstPhaseTime"

//=================================================================
// FO sub-device channel properties
//=================================================================

#define ME_PROPERTY_NAME_INVERTED                                "Inverted"

#define ME_PROPERTY_NAME_SYNCHRONOUS_START                       "SynchronousStart"

#define ME_PROPERTY_NAME_SOFT_START                              "SoftStart"


//=================================================================
// Counter sub-devices - additional sub-device properties
//=================================================================

#define ME_PROPERTY_NAME_WIDTH_IN_BITS                           "WidthInBits"

#define ME_PROPERTY_NAME_CLOCK_SOURCE                            "ClockSource"

#define ME_PROPERTY_NAME_COUNTER_MODE                            "CounterMode"

#endif
