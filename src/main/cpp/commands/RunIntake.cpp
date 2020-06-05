#include "commands/RunIntake.h"

RunIntake::RunIntake(IntakeSubsystem* intake, BeltSubsystem* belt)
: m_intake{intake},
  m_belt{belt} {
  AddRequirements({intake});
  AddRequirements({belt});
}

void RunIntake::Execute() {
  if(m_belt->m_ballDetector.GetBallCount() < 5) {
      m_intake->RunIntake();
      if((m_belt->m_ballDetector.GetBallCount()) <= 2 && (m_belt->m_ballDetector.GetBallCurrentlyPassingInFrontOfLidar())) {
          m_belt->RunBelt(1);
      } else {
      }
    } else {
        m_intake->Stop();
        m_belt->Stop();
    }
}

//RunIntake does not have an exit condition because it is bound to a trigger.
bool RunIntake::IsFinished() {
  return false;
}

void RunIntake::End(bool interrupted) {
  m_belt->Stop();
  m_intake->Stop();
}