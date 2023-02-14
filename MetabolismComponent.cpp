#include "MetabolismComponent.h"

UMetabolismComponent::UMetabolismComponent()
{
    // Varsayılan özellik değerleri
    MaxHunger = 100.0f;
    MaxThirst = 100.0f;
    MaxEnergy = 100.0f;
    NormalBodyTemperature = 37.0f;

    HungerRate = 0.1f;
    ThirstRate = 0.2f;
    EnergyRate = 0.1f;
    TemperatureRate = 0.01f;

    Hunger = MaxHunger;
    Thirst = MaxThirst;
    Energy = MaxEnergy;
    BodyTemperature = NormalBodyTemperature;
}

void UMetabolismComponent::UpdateMetabolism(float DeltaTime)
{
    // Açlık, susuzluk ve enerji seviyelerini güncelle
    UpdateHunger(DeltaTime);
    UpdateThirst(DeltaTime);
    UpdateEnergy(DeltaTime);

    // Vücut ısısını güncelle
    UpdateBodyTemperature(DeltaTime);
}

void UMetabolismComponent::StartMetabolism()
{
    // Metabolizmayı başlat
    SetComponentTickEnabled(true);
}

void UMetabolismComponent::UpdateHunger(float DeltaTime)
{
    // Açlık seviyesini güncelle
    Hunger = FMath::Clamp(Hunger + (HungerRate * DeltaTime), 0.0f, MaxHunger);

    // Eğer açlık seviyesi 0 ise, enerji seviyesini azalt
    if (Hunger <= 0.0f)
    {
        Energy = FMath::Clamp(Energy - (EnergyRate * DeltaTime), 0.0f, MaxEnergy);
    }
}

void UMetabolismComponent::UpdateThirst(float DeltaTime)
{
    // Susuzluk seviyesini güncelle
    Thirst = FMath::Clamp(Thirst + (ThirstRate * DeltaTime), 0.0f, MaxThirst);

    // Eğer susuzluk seviyesi 0 ise, enerji seviyesini azalt
    if (Thirst <= 0.0f)
    {
        Energy = FMath::Clamp(Energy - (EnergyRate * DeltaTime), 0.0f, MaxEnergy);
    }
}

void UMetabolismComponent::UpdateEnergy(float DeltaTime)
{
    // Enerji seviyesini güncelle
    Energy = FMath::Clamp(Energy - (EnergyRate * DeltaTime), 0.0f, MaxEnergy);
}

void UMetabolismComponent::UpdateBodyTemperature(float DeltaTime)
{
    // Vücut ısısını güncelle
    if (BodyTemperature > NormalBodyTemperature)
    {
        BodyTemperature = FMath::Max(BodyTemperature - (TemperatureRate * DeltaTime), NormalBodyTemperature);
    }
    else if (BodyTemperature < NormalBodyTemperature)
    {
        BodyTemperature = FMath::Min(BodyTemperature + (TemperatureRate * DeltaTime), NormalBodyTemperature);
    }
}

