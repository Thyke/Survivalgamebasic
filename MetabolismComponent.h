UCLASS(Blueprintable)
class UMetabolismComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Yapıcı fonksiyon
    UMetabolismComponent();

    // Karakterin metabolizma değişkenleri
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float Hunger;        // Açlık seviyesi
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float Thirst;        // Susuzluk seviyesi
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float Energy;        // Enerji seviyesi
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float BodyTemperature;  // Vücut ısısı

    // Karakterin metabolizma özellikleri
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float MaxHunger;     // Maksimum açlık seviyesi
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float MaxThirst;     // Maksimum susuzluk seviyesi
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float MaxEnergy;     // Maksimum enerji seviyesi
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float NormalBodyTemperature;    // Normal vücut ısısı

    // Karakterin metabolizma hızları
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float HungerRate;    // Açlık hızı
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float ThirstRate;    // Susuzluk hızı
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float EnergyRate;    // Enerji tüketim hızı
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Metabolism")
    float TemperatureRate;  // Vücut ısısı değişim hızı

    // Metabolizma değişkenlerini güncelleme fonksiyonu
    UFUNCTION(BlueprintCallable, Category = "Metabolism")
    void UpdateMetabolism(float DeltaTime);

    // Karakterin metabolizmasını başlatma fonksiyonu
    UFUNCTION(BlueprintCallable, Category = "Metabolism")
    void StartMetabolism();

private:
    // Karakterin metabolizma değişkenlerini güncelleme fonksiyonu
    void UpdateHunger(float DeltaTime);
    void UpdateThirst(float DeltaTime);
    void UpdateEnergy(float DeltaTime);
    void UpdateBodyTemperature(float DeltaTime);
};
