#pragma once
#include "frc2/command/SubsystemBase.h"
#include "Constants.h"
#include "ctre/Phoenix.h"
#include "Lidar.h"
#include "frc/Encoder.h"
#include <units/units.h>
class BeltSubsystem : public frc2::SubsystemBase {
public:
BeltSubsystem(int beltID, frc::I2C::Port lidarPort );
void Periodic() override;
void UpdateBallCount();
bool BallDetectedByLidar();
void RunBelt(double percentDampen);
void PutDiagnostics();
void Stop();
units::inch_t m_currentLidarDistance; // temp, probably. Would want to move into update and make `const` eventually, but need global to reference in `PutDiagnostics()`.
public:
bool m_ballCurrentlyPassingInFrontOfLidar;
WPI_TalonSRX m_beltMotor;
int m_ballCount = 3;
Lidar m_ballDetector;
std::shared_ptr<frc::Encoder> m_beltEncoder = std::make_shared<frc::Encoder>(PenguinConstants::DIO::BELT_ENCODER_A, PenguinConstants::DIO::BELT_ENCODER_B);
};