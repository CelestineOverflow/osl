//==============================================================================
//Copyright(c)  Meilhaus Electronic GmbH
//              http://www.meilhaus.de
//              support@meilhaus.de
//
//Source File : meIDSPropertiesWideCharacter.h
//              defines for properties used in ME-iDS, UNICODE format
//==============================================================================

#ifndef _MEIDSPROPERTIESWIDECHARACTER_H_
#define _MEIDSPROPERTIESWIDECHARACTER_H_

//=================================================================
// Attributes
//=================================================================

#define ME_ATTRIBUTE_NAME_WC_NUMBER_OF_ELEMENTS                     L"NumberOfElements"

#define ME_ATTRIBUTE_NAME_WC_PROPERTY_NAME                          L"PropertyName"

#define ME_ATTRIBUTE_NAME_WC_PROPERTY_TYPE                          L"PropertyType"

#define ME_ATTRIBUTE_NAME_WC_PROPERTY_ACCESS                        L"PropertyAccess"

#define ME_ATTRIBUTE_NAME_WC_PROPERTY_DESCRIPTION                   L"PropertyDescription"

#define ME_ATTRIBUTE_NAME_WC_MIN_VALUE                              L"MinValue"

#define ME_ATTRIBUTE_NAME_WC_MAX_VALUE                              L"MaxValue"

#define ME_ATTRIBUTE_NAME_WC_LENGTH                                 L"Length"

#define ME_ATTRIBUTE_NAME_WC_MAX_LENGTH                             L"MaxLength"

#define ME_ATTRIBUTE_NAME_WC_NUMBER_OF_SELECTIONS                   L"NumberOfSelections"

#define ME_ATTRIBUTE_NAME_WC_PREFIX_SELECTION                       L"Selection"    // The selection with index # is L"Selection#"

//=================================================================
// Root container (system container)
//=================================================================

#define ME_CONTAINER_NAME_WC_ROOT                                   L"\\\\" 

//=================================================================
// System properties and containers
//=================================================================

#define ME_PROPERTY_NAME_WC_LIBRARY_VERSION                         L"LibraryVersion"

#define ME_PROPERTY_NAME_WC_MAIN_DRIVER_VERSION                     L"MainDriverVersion"

#define ME_PROPERTY_NAME_WC_NUMBER_OF_DEVICES                       L"NumberOfDevices"

#define ME_CONTAINER_NAME_WC_DEVICES                                L"Devices"

//=================================================================
// General device properties and containers - not device specific
//=================================================================

#define ME_CONTAINER_NAME_PREFIX_WC_DEVICE                          L"Device"   // The container name for the device with index # is L"Device#"

#define ME_PROPERTY_NAME_WC_NAME                                    L"Name"

#define ME_PROPERTY_NAME_WC_DRIVER_NAME                             L"DriverName"

#define ME_PROPERTY_NAME_WC_DRIVER_VERSION                          L"DriverVersion"

#define ME_PROPERTY_NAME_WC_DESCRIPTION                             L"Description"

#define ME_PROPERTY_NAME_WC_SERIAL_NUMBER                           L"SerialNumber"

#define ME_PROPERTY_NAME_WC_BUS_TYPE                                L"BusType"

#define ME_PROPERTY_NAME_WC_ACCESS_TYPE                             L"AccessType"

#define ME_PROPERTY_NAME_WC_PLUGGED                                 L"Plugged"

#define ME_PROPERTY_NAME_WC_FIRMWARE_SELECTABLE                     L"FirmwareSelectable"

#define ME_PROPERTY_NAME_WC_CURRENT_FIRMWARE_ID                     L"CurrentFirmwareID"

#define ME_PROPERTY_NAME_WC_NUMBER_OF_SUBDEVICES                    L"NumberOfSubdevices"

#define ME_CONTAINER_NAME_WC_SUBDEVICES                             L"Subdevices"

//=================================================================
// Additional properties for PCI devices
//=================================================================

#define ME_PROPERTY_NAME_WC_PCI_VENDOR_ID                           L"PCIVendorID"

#define ME_PROPERTY_NAME_WC_PCI_DEVICE_ID                           L"PCIDeviceID"

#define ME_PROPERTY_NAME_WC_PCI_BUS_NUMBER                          L"PCIBusNumber"

#define ME_PROPERTY_NAME_WC_PCI_SLOT_NUMBER                         L"PCISlotNumber"

#define ME_PROPERTY_NAME_WC_PCI_FUNCTION_NUMBER                     L"PCIFunctionNumber"

//=================================================================
// General sub-device properties and containers - not sub-device specific
//=================================================================

#define ME_CONTAINER_NAME_PREFIX_WC_SUBDEVICE                       L"Subdevice"    // The container name for the sub-device with index # is L"Subdevice#"

#define ME_PROPERTY_NAME_WC_TYPE                                    L"Type"

#define ME_PROPERTY_NAME_WC_SUBTYPE                                 L"Subtype"

#define ME_PROPERTY_NAME_WC_NUMBER_OF_CHANNELS                      L"NumberOfChannels"

#define ME_PROPERTY_NAME_WC_CONFIGURABLE                            L"Configurable"

#define ME_PROPERTY_NAME_WC_NUMBER_OF_CONFIGURATIONS                L"NumberOfConfigurations"

#define ME_PROPERTY_NAME_WC_CURRENT_CONFIGURATION                   L"CurrentConfiguration"

#define ME_CONTAINER_NAME_WC_CHANNELS                               L"Channels"

#define ME_CONTAINER_NAME_PREFIX_WC_CHANNEL                         L"Channel"          // The container name for the channel with index # is L"Channel#"

#define ME_CONTAINER_NAME_WC_CONFIGURATIONS                         L"Configurations"

#define ME_CONTAINER_NAME_PREFIX_WC_CONFIGURATION                   L"Configuration"    // The container name for the configuration with index # is L"Configuration#"

//=================================================================
// Configuration properties
//=================================================================

#define ME_PROPERTY_NAME_WC_SUBDEVICE_TYPE                          L"SubdeviceType"

#define ME_PROPERTY_NAME_WC_SUBDEVICE_SUBTYPE                       L"SubdeviceSubtype"

#define ME_PROPERTY_NAME_WC_SUBDEVICE_NUMBER_OF_CHANNELS            L"SubdeviceNumberOfChannels"

//=================================================================
// ME-5100 and ME-5001 - additional device properties
//=================================================================

#define ME_PROPERTY_NAME_WC_IO_PIN_VOLTAGE_LEVEL                    L"IOPinVoltageLevel"

#define ME_PROPERTY_NAME_WC_SUBDEVICES_0_AND_1_TERMINATED           L"Subdevice0And1Terminated"

#define ME_PROPERTY_NAME_WC_SUBDEVICES_2_AND_3_TERMINATED           L"Subdevice2And3Terminated"

//=================================================================
// Additional sub-device properties for various sub-device types
//=================================================================

#define ME_PROPERTY_NAME_WC_TERMINATED                              L"Terminated"

#define ME_PROPERTY_NAME_WC_SYSTEM_CLOCK_FREQUENCY                  L"SystemClockFrequency"

//=================================================================
// Additional sub-device properties and containers for AI, DI, DO sub-device types
//=================================================================

#define ME_PROPERTY_NAME_WC_TRIGGER_TYPE                            L"TriggerType"

#define ME_PROPERTY_NAME_PREFIX_WC_RISING_EDGE_BIT                  L"RisingEdgeBit"    // The name for the trigger condition on bit # is L"RisingEdgeBit#"

#define ME_PROPERTY_NAME_PREFIX_WC_FALLING_EDGE_BIT                 L"FallingEdgeBit"   // The name for the trigger condition on bit # is L"FallngEdgeBit#"

#define ME_PROPERTY_NAME_WC_INTERNAL_BUFFER_SIZE                    L"InternalBufferSize"

#define ME_PROPERTY_NAME_WC_SAMPLE_FREQUENCY                        L"SampleFrequency"

#define ME_PROPERTY_NAME_WC_SAMPLE_TIME                             L"SampleTime"

#define ME_PROPERTY_NAME_WC_START_TRIGGER_TYPE                      L"StartTriggerType"

#define ME_PROPERTY_NAME_WC_CONV_TRIGGER_TYPE                       L"ConvTriggerType"

#define ME_PROPERTY_NAME_WC_STOP_TRIGGER_TYPE                       L"StopTriggerType"

#define ME_PROPERTY_NAME_WC_START_STOP_PATTERN                      L"StartStopPattern"

#define ME_PROPERTY_NAME_WC_STOP_ON_COUNT                           L"StopOnCount"

#define ME_PROPERTY_NAME_WC_STOP_COUNT                              L"StopCount"

#define ME_CONTAINER_NAME_WC_INTERRUPT_CONDITION                    L"InterruptCondition"

#define ME_CONTAINER_NAME_WC_SINGLE_CONFIGURATION                   L"SingleConfiguration"

#define ME_CONTAINER_NAME_WC_EXT_DIGITAL_TRIGGER_CONDITION          L"ExtDigitalTriggerCondition"

#define ME_CONTAINER_NAME_WC_STREAMING_CONFIGURATION                L"StreamingConfiguration"

#define ME_CONTAINER_NAME_WC_START_AND_CONV_TRIGGER_CONDITION       L"StartAndConvTriggerCondition"

#define ME_CONTAINER_NAME_WC_STOP_TRIGGER_CONDITION                 L"StopTriggerCondition"

#define ME_CONTAINER_NAME_WC_IRQ_CONFIGURATION                      L"IRQConfiguration"

//=================================================================
// Additional sub-device properties for AI sub-device types
//=================================================================

#define ME_PROPERTY_NAME_WC_CALIBRATION                             L"Calibration"

#define ME_PROPERTY_NAME_WC_RISING_EDGE_TRIGGER_A1                  L"RisingEdgeTriggerA1"

#define ME_PROPERTY_NAME_WC_FALLING_EDGE_TRIGGER_A1                 L"FallingEdgeTriggerA1"

#define ME_PROPERTY_NAME_WC_RISING_EDGE_TRIGGER_A2                  L"RisingEdgeTriggerA2"

#define ME_PROPERTY_NAME_WC_FALLING_EDGE_TRIGGER_A2                 L"FallingEdgeTriggerA2"

#define ME_PROPERTY_NAME_WC_ACQUIRE_CHANNEL                         L"AcquireChannel"

//=================================================================
// Additional sub-device properties and containers for DI sub-device types
//=================================================================

#define ME_PROPERTY_NAME_WC_RISING_EDGE_TRIGGER_A                   L"RisingEdgeTriggerA"

#define ME_PROPERTY_NAME_WC_FALLING_EDGE_TRIGGER_A                  L"FallingEdgeTriggerA"

#define ME_PROPERTY_NAME_WC_USE_INTERNAL_TEST_COUNTER               L"UseInternalTestCounter"

#define ME_PROPERTY_NAME_WC_TRANSFER_SIZE                           L"TransferSize"

#define ME_PROPERTY_NAME_WC_IRQ_SOURCE                              L"IRQSource"

#define ME_PROPERTY_NAME_WC_BIT_PATTERN                             L"BitPattern"

#define ME_PROPERTY_NAME_WC_BIT_PATTERN_FILTERING                   L"BitPatternFiltering"

#define ME_PROPERTY_CONTAINER_WC_BIT_MASK                           L"BitMask"

//=================================================================
// Additional sub-device properties and containers forDO sub-device types
//=================================================================

#define ME_PROPERTY_NAME_WC_RISING_EDGE_TRIGGER_B                   L"RisingEdgeTriggerB"

#define ME_PROPERTY_NAME_WC_FALLING_EDGE_TRIGGER_B                  L"FallingEdgeTriggerB"

#define ME_PROPERTY_NAME_WC_IRQ_ON_EXCESS_TEMPERATURE               L"IRQOnExcessTemperature"

#define ME_PROPERTY_NAME_WC_IRQ_ON_NORMAL_TEMPERATURE               L"IRQOnNormalTemperature"

#define ME_PROPERTY_NAME_WC_STOP_PATTERN                            L"StopPattern"

#define ME_PROPERTY_NAME_WC_WRAPAROUND                              L"Wraparound"

#define ME_PROPERTY_NAME_WC_WRAPAROUND_LOOPS                        L"WraparoundLoops"

//=================================================================
// Additional sub-device properties and containers for DO and FO sub-device types
//=================================================================

#define ME_PROPERTY_NAME_WC_OUTPUT_MODE                             L"OutputMode"

//=================================================================
// Additional sub-device properties and containers for DIO sub-device types
//=================================================================

#define ME_PROPERTY_NAME_WC_DIRECTION                               L"Direction"

//=================================================================
// Additional sub-device properties FI sub-device types
//=================================================================

#define ME_PROPERTY_NAME_WC_MIN_MEASURABLE_TOTAL_TICKS              L"MinMeasurableTotalTicks"

#define ME_PROPERTY_NAME_WC_MAX_MEASURABLE_TOTAL_TICK               L"MaxMeasurableTotalTicks"

#define ME_PROPERTY_NAME_WC_MIN_MEASURABLE_FIRST_PHASE_TICKS        L"MinMeasurableFirstPhaseTicks"

#define ME_PROPERTY_NAME_WC_MAX_MEASURABLE_FIRST_PHASE_TICKS        L"MaxMeasurableFirstPhaseTicks"

#define ME_PROPERTY_NAME_WC_MIN_MEASURABLE_TOTAL_TIME               L"MinMeasurableTotalTime"

#define ME_PROPERTY_NAME_WC_MAX_MEASURABLE_TOTAL_TIME               L"MaxMeasurableTotalTime"

#define ME_PROPERTY_NAME_WC_MIN_MEASURABLE_FIRST_PHASE_TIME         L"MinMeasurableFirstPhaseTime"

#define ME_PROPERTY_NAME_WC_MAX_MEASURABLE_FIRST_PHASE_TIME         L"MaxMeasurableFirstPhaseTime"

//=================================================================
// Additional sub-device properties for FO sub-device types
//=================================================================

#define ME_PROPERTY_NAME_WC_MIN_TOTAL_TICKS                         L"MinTotalTicks"

#define ME_PROPERTY_NAME_WC_MAX_TOTAL_TICK                          L"MaxTotalTicks"

#define ME_PROPERTY_NAME_WC_MIN_FIRST_PHASE_TICKS                   L"MinFirstPhaseTicks"

#define ME_PROPERTY_NAME_WC_MAX_FIRST_PHASE_TICKS                   L"MaxFirstPhaseTicks"

#define ME_PROPERTY_NAME_WC_MIN_TOTAL_TIME                          L"MinTotalTime"

#define ME_PROPERTY_NAME_WC_MAX_TOTAL_TIME                          L"MaxTotalTime"

#define ME_PROPERTY_NAME_WC_MIN_FIRST_PHASE_TIME                    L"MinFirstPhaseTime"

#define ME_PROPERTY_NAME_WC_MAX_FIRST_PHASE_TIME                    L"MaxFirstPhaseTime"

//=================================================================
// FO sub-device channel properties
//=================================================================

#define ME_PROPERTY_NAME_WC_INVERTED                                L"Inverted"

#define ME_PROPERTY_NAME_WC_SYNCHRONOUS_START                       L"SynchronousStart"

#define ME_PROPERTY_NAME_WC_SOFT_START                              L"SoftStart"


//=================================================================
// Counter sub-devices - additional sub-device properties
//=================================================================

#define ME_PROPERTY_NAME_WC_WIDTH_IN_BITS                           L"WidthInBits"

#define ME_PROPERTY_NAME_WC_CLOCK_SOURCE                            L"ClockSource"

#define ME_PROPERTY_NAME_WC_COUNTER_MODE                            L"CounterMode"

#endif
