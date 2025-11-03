#pragma once

#include <stdlib.h>
#include <string.h>

//compile 할 때 코드 생성 - 오류 검출 가능
template<typename T>
class TDynamicArray
{
public:
	TDynamicArray()
	{
	}
	//deep copy 깊은 복사
	//copy constructor(복사 생성자)
	TDynamicArray(const TDynamicArray<T>& RHS)
	{
		this->Size = RHS.Size;
		this->Capacity = RHS.Capacity;

		this->CurrentIndex = RHS.CurrentIndex;

		this->Data = new T[Capacity];
		memmove(this->Data, RHS.Data, Size * sizeof(T));
	}
	virtual ~TDynamicArray()
	{
		if (Data)
		{
			delete[] Data;
			Data = nullptr;
		}
	}

	TDynamicArray<T>& operator=(const TDynamicArray<T>& RHS)
	{
		this->Size = RHS.Size;
		this->Capacity = RHS.Capacity;

		this->CurrentIndex = RHS.CurrentIndex;

		this->Data = new T[Capacity];
		memmove(this->Data, RHS.Data, Size * sizeof(T));
		return *this;
	}

protected:
	T* Data = nullptr;
	size_t Size = 0;
	size_t Capacity = 0;	// 연산보다 공간 늘리기가 성능에 더 영향을 주므로 한번에 많이 늘림
	int CurrentIndex = 0;

public:
	size_t GetSize()
	{
		return Size;
	}
	size_t GetCapacity()
	{
		return Capacity;
	}

	T& operator[](size_t _Index)
	{
		return Data[_Index];
	}

	void PushBack(T Value)
	{
		if (CurrentIndex < Capacity)
		{
			Data[CurrentIndex] = Value;
			CurrentIndex++;
			Size++;
		}
		else
		{
			//s Resize
			if (Capacity == 0)
			{
				Capacity = 1;
			}
			T* NewArray = new T[Capacity * 2];

			//memory copy
			//for (size_t i = 0; i < Size; ++i)
			//{
			//	NewArray[i] = Data[i];
			//}
			//memcpy(NewArray, Data, Size * sizeof(T));
			memmove(NewArray, Data, Size * sizeof(T));

			if (Data)
			{
				delete[] Data;
			}
			Data = NewArray;
			//e Resize

			Capacity = Capacity * 2;
			Data[CurrentIndex] = Value;
			CurrentIndex++;
			Size++;
		}
	}
};

