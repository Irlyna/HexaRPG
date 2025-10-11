#pragma once

#include "UObject/Interface.h"
#include "IDamageable.generated.h"

UINTERFACE(Blueprintable)
class HEXARPG_API UDamageableInterface : public UInterface
{
	GENERATED_BODY()
};

class HEXARPG_API IDamageableInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Damage")
	void ApplyDamage(float const DamageAmount);
};