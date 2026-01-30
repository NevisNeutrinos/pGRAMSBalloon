#ifndef pGRAMS_CommunicationCodes_hh
#define pGRAMS_CommunicationCodes_hh 1
#include <cstdint>
namespace pgrams::communication {
constexpr uint16_t construct_code(uint16_t code, uint16_t subsystem_mask) {
  return code + subsystem_mask;
}

#ifndef PGRAMS_COM_CODE_PDU
#define PGRAMS_COM_CODE_PDU(name, code)                          \
  PDU_##name##_ON = construct_code(code, COM_SUBSYSTEM_PDU_MSK), \
  PDU_##name##_OFF = construct_code(code + 0x1, COM_SUBSYSTEM_PDU_MSK)
#else
#error "PGRAMS_COM_CODE_PDU is already defined. Please ensure it is defined only once."
#endif

constexpr uint16_t COM_SUBSYSTEM_HUB_MSK = 0x1000;
constexpr uint16_t COM_SUBSYSTEM_PDU_MSK = 0x2000;
constexpr uint16_t COM_SUBSYSTEM_ORC_MSK = 0x3000;
constexpr uint16_t COM_SUBSYSTEM_COL_MSK = 0x4000; // Columbia readout
constexpr uint16_t COM_SUBSYSTEM_TOF_MSK = 0x5000;
constexpr uint16_t COM_SUBSYSTEM_TOF_BIAS_MSK = 0x6000;
constexpr uint16_t COM_SUBSYSTEM_CMN_MSK = 0x7000; // Common commands
constexpr uint16_t COM_SUBSYSTEM_MSK = 0xF000; // Mask for all subsystems

enum class CommunicationCodes : uint16_t {
  // Special command for heart beat.
  COM_HeartBeat = 0xFFFF,

  // Hub computer
  HUB_Emergency_Daq_shutdown = construct_code(0xFF, COM_SUBSYSTEM_HUB_MSK),
  HUB_Prepare_Shutdown = construct_code(0x0, COM_SUBSYSTEM_HUB_MSK),
  HUB_Exec_Shutdown = construct_code(0x1, COM_SUBSYSTEM_HUB_MSK),
  HUB_Prepare_Restart = construct_code(0x2, COM_SUBSYSTEM_HUB_MSK),
  HUB_Exec_Restart = construct_code(0x3, COM_SUBSYSTEM_HUB_MSK),
  HUB_Reset_Error = construct_code(0x4, COM_SUBSYSTEM_HUB_MSK),
  HUB_Set_Link = construct_code(0x5, COM_SUBSYSTEM_HUB_MSK),
  HUB_Dummy1 = construct_code(0xF1, COM_SUBSYSTEM_HUB_MSK),
  HUB_Dummy2 = construct_code(0xF2, COM_SUBSYSTEM_HUB_MSK),

  // PDU
  PGRAMS_COM_CODE_PDU(Cold_TPC_HV, 0x0),
  PGRAMS_COM_CODE_PDU(Cold_Charge_PreAmp, 0x2),
  PGRAMS_COM_CODE_PDU(Cold_SiPM_PreAmp, 0x4),
  PGRAMS_COM_CODE_PDU(Warm_TPC_Shaper, 0x6),
  PGRAMS_COM_CODE_PDU(SiPM, 0x8),
  PGRAMS_COM_CODE_PDU(CAEN_P3V3, 0xA),
  PGRAMS_COM_CODE_PDU(CAEN_PM5V, 0xC),
  PGRAMS_COM_CODE_PDU(CAEN_P12V, 0xE),
  PGRAMS_COM_CODE_PDU(DAQ_CPU, 0x10),
  PDU_SiPM0_VSET = construct_code(0x10, COM_SUBSYSTEM_PDU_MSK),
  PDU_SiPM1_VSET = construct_code(0x11, COM_SUBSYSTEM_PDU_MSK),
  PDU_SiPM2_VSET = construct_code(0x12, COM_SUBSYSTEM_PDU_MSK),
  PDU_SiPM3_VSET = construct_code(0x13, COM_SUBSYSTEM_PDU_MSK),
  PDU_SiPM4_VSET = construct_code(0x14, COM_SUBSYSTEM_PDU_MSK),
  PDU_SiPM5_VSET = construct_code(0x15, COM_SUBSYSTEM_PDU_MSK),
  PDU_PressureReg_VSET = construct_code(0x16, COM_SUBSYSTEM_PDU_MSK),

  // Orchestrator
  ORC_Exec_CPU_Restart = construct_code(0x0, COM_SUBSYSTEM_ORC_MSK),
  ORC_Exec_CPU_Shutdown = construct_code(0x1, COM_SUBSYSTEM_ORC_MSK),
  ORC_Boot_All_DAQ = construct_code(0x2, COM_SUBSYSTEM_ORC_MSK),
  ORC_Shutdown_All_DAQ = construct_code(0x3, COM_SUBSYSTEM_ORC_MSK),
  ORC_Start_Computer_Status = construct_code(0x4, COM_SUBSYSTEM_ORC_MSK),
  ORC_Stop_Computer_Status = construct_code(0x5, COM_SUBSYSTEM_ORC_MSK),
  ORC_Init_PCIe_Driver = construct_code(0x6, COM_SUBSYSTEM_ORC_MSK),
  ORC_Boot_Monitor = construct_code(0x7, COM_SUBSYSTEM_ORC_MSK),
  ORC_Shutdown_Monitor = construct_code(0x8, COM_SUBSYSTEM_ORC_MSK),
  ORC_Boot_Tof_Daq = construct_code(0x9, COM_SUBSYSTEM_ORC_MSK),
  ORC_Shutdown_Tof_Daq = construct_code(0x10, COM_SUBSYSTEM_ORC_MSK),

  //Columbia Readout
  COL_Configure = construct_code(0x0, COM_SUBSYSTEM_COL_MSK),
  COL_Start_Run = construct_code(0x1, COM_SUBSYSTEM_COL_MSK),
  COL_Stop_Run = construct_code(0x2, COM_SUBSYSTEM_COL_MSK),
  COL_Reset_Run = construct_code(0x3, COM_SUBSYSTEM_COL_MSK),
  COL_Boot_DAQ = construct_code(0x4, COM_SUBSYSTEM_COL_MSK),
  COL_Boot_Monitor = construct_code(0x5, COM_SUBSYSTEM_COL_MSK),
  COL_Query_LB_Data = construct_code(0x7, COM_SUBSYSTEM_COL_MSK),
  COL_Query_Event_Data = construct_code(0x8, COM_SUBSYSTEM_COL_MSK),

  // TOF
  TOF_Start_DAQ = construct_code(0x0, COM_SUBSYSTEM_TOF_MSK),
  TOF_Stop_DAQ = construct_code(0x1, COM_SUBSYSTEM_TOF_MSK),
  TOF_Reset_DAQ = construct_code(0x2, COM_SUBSYSTEM_TOF_MSK),

  TOF_Run_Init_System = construct_code(0x100, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Make_Bias_Calib_Table = construct_code(0x101, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Make_Simple_Bias_Set_Table = construct_code(0x102, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Make_Simple_Channel_Map = construct_code(0x103, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Make_Simple_Disc_Set_Table = construct_code(0x104, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Read_Temperature_Sensors = construct_code(0x105, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Acquire_Threshold_Calibration = construct_code(0x106, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Acquire_TDC_Calibration = construct_code(0x107, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Acquire_QDC_Calibration = construct_code(0x108, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Acquire_SiPM_Data = construct_code(0x109, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Acquire_Threshold_Calibration_BN = construct_code(0x110, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Acquire_Threshold_Calibration_D = construct_code(0x111, COM_SUBSYSTEM_TOF_MSK),

  TOF_Run_Process_Threshold_Calibration = construct_code(0x200, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Process_TDC_Calibration = construct_code(0x201, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Process_QDC_Calibration = construct_code(0x202, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Convert_Raw_To_Raw = construct_code(0x203, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Convert_Raw_To_Singles = construct_code(0x204, COM_SUBSYSTEM_TOF_MSK),
  TOF_Run_Process_TOF_Coin_Evt_QA = construct_code(0x205, COM_SUBSYSTEM_TOF_MSK),

  TOF_ACK = construct_code(0xFFF, COM_SUBSYSTEM_TOF_MSK),
  TOF_Callback = construct_code(0xFFE, COM_SUBSYSTEM_TOF_MSK),
  TOF_Status = construct_code(0xFFD, COM_SUBSYSTEM_TOF_MSK),
  TOF_DummyTest = construct_code(0xFFC, COM_SUBSYSTEM_TOF_MSK),

  // TOF Bias
  TOF_Bias_ON = construct_code(0x0, COM_SUBSYSTEM_TOF_BIAS_MSK),
  TOF_Bias_OFF = construct_code(0x1, COM_SUBSYSTEM_TOF_BIAS_MSK),
  TOF_Bias_Set_Voltage = construct_code(0x2, COM_SUBSYSTEM_TOF_BIAS_MSK),

  CMN_Command_Error = construct_code(0x0, COM_SUBSYSTEM_CMN_MSK),

};

// Functions
inline bool isSubsystem(uint16_t code, uint16_t subsystem_mask) {
  return (code & COM_SUBSYSTEM_MSK) == subsystem_mask;
}
inline uint16_t castCommandCode(CommunicationCodes code) {
  return static_cast<uint16_t>(code);
}
constexpr uint16_t to_u16(CommunicationCodes code) noexcept {
  return static_cast<uint16_t>(code);
}

enum class TelemetryCodes : uint16_t {
  HUB_Telemetry_Normal = 0x0,
  ORC_Hardware_Status = construct_code(0x20, COM_SUBSYSTEM_ORC_MSK),
  COL_Hardware_Status = construct_code(0x20, COM_SUBSYSTEM_COL_MSK),
  COL_Query_Hardware_Status = construct_code(0x22, COM_SUBSYSTEM_COL_MSK)
};
constexpr uint16_t to_telem_u16(TelemetryCodes code) noexcept {
  return static_cast<uint16_t>(code);
}
} // namespace pgrams::communication

#endif //pGRAMS_CommunicationCodes_hh
