// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#include "include/EsunnyQuot.h"
#include "include/EsunnyForeignApi.h"

#include "EsStruct.h"
#include "Delegates.h"
#include <vcclr.h>

using namespace System;

namespace EsForeignWrapper 
{
	/// 非托管类, 自动转换 Managed <==> Native 
	template<typename ManagedType, typename NativeType>
	class TypeConverter
	{
	public:
		/// Native to Managed
		static ManagedType ToManagedType(NativeType* pNative)
		{
			return safe_cast<ManagedType>(Marshal::PtrToStructure(IntPtr(pNative), ManagedType::typeid));
		}

		static void ToNativeType(ManagedType managed, NativeType* pNative)
		{
			Marshal::StructureToPtr(managed, IntPtr(pNative), true);
		}
	};
}

