#include "Actionable.h"

void IActionable::OnOverlapBegin(UPrimitiveComponent *Comp, AActor *otherActor, UPrimitiveComponent *otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    UE_LOG(LogTemp, Display, TEXT("GOT HIT"));
}
