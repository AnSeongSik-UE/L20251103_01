//#include "DynamicArray.h"
//
//void TDynamicArray::PushBack(T Value)
//{
//	if (Index < Capacity)
//	{
//		Data[Index] = Value;
//		Index++;
//		Size++;
//	}
//	else
//	{
//		if (Capacity == 0)
//		{
//			Capacity = 1;
//		}
//		T* NewArray = new T[Capacity * 2];
//
//		//memory copy
//		//for (int i = 0; i < Size; ++i)
//		//{
//		//	NewArray[i] = Data[i];
//		//}
//		//memcpy(NewArray, Data, Size * sizeof(int));
//		memmove(NewArray, Data, Size * sizeof(T));
//
//		if(Data)
//		{
//			delete[] Data;
//		}
//		Data = NewArray;
//
//		Capacity = Capacity * 2;
//		Data[Index] = Value;
//		Index++;
//		Size++;
//	}
//}