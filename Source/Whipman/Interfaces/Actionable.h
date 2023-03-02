#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Actionable.generated.h"

UINTERFACE(MinimalAPI)
class UActionable : public UInterface
{
	GENERATED_BODY()
};


class WHIPMAN_API IActionable
{
	GENERATED_BODY()

public:

	UFUNCTION() 
	virtual void OnOverlap();
};