#pragma once

class AActor;

//추상 클래스
class IInterface
{
public:
	//순수 가상 함수
	//상속받는 클래스는 무조건 아래 함수를 재정의 해야 함
	virtual void Tick() = 0;
};

class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	virtual void Tick() = 0;

	AActor* GetOwner() const;
	void SetOwner(AActor* InOwner);

protected:
	AActor* Owner;
};

