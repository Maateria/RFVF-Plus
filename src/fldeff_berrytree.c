#include "global.h"
#include "script.h"
#include "task.h"

static void Task_EndWateringBerryTreeAnim(u8 taskId)
{
    ScriptContext_Enable();
    DestroyTask(taskId);
}

// From R/S, removed. RFVF+: the player has no watering sprite, so it only resumes the script's waitstate
// (the Frontier's Sudowoodo); the task runs after the waitstate stops the script.
void DoWateringBerryTreeAnim(void)
{
    CreateTask(Task_EndWateringBerryTreeAnim, 80);
}
