#pragma once

//Data 저장용
//C++에서는 class와 동일하게 동작
//C#에서는 struct는 Stack영역 class는 Heap영역
struct FVector2D
{
public:
	FVector2D(int InX = 0, int InY = 0) : X(InX), Y(InY)
	{

	}
	FVector2D(const FVector2D& RHS)
	{
		this->X = RHS.X;
		this->Y = RHS.Y;
	}
	virtual ~FVector2D() {}

	FVector2D& operator=(const FVector2D& RHS)
	{
		this->X = RHS.X;
		this->Y = RHS.Y;
		return *this;
	}
	FVector2D operator+(const FVector2D& RHS)
	{
		return FVector2D(this->X + RHS.X, this->Y + RHS.Y);
	}
	FVector2D operator-(const FVector2D& RHS)
	{
		return FVector2D(this->X - RHS.X, this->Y - RHS.Y);
	}
	bool operator==(const FVector2D& RHS)
	{
		return (this->X == RHS.X && this->Y == RHS.Y);
	}

	int X;
	int Y;
};