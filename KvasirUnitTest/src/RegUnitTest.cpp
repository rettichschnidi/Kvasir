/**************************************************************************************************
 * Source file containing the unittests of the Reg.hpp file
 *
 *
 * List of bugs:
 * 			- none :P
 *
 *
 * List of requested funtionalities:
 * 			- many
 *
 *

*/
#pragma once
#include "Register.hpp"
#include "StartUp.hpp"

using namespace Kvasir;
using namespace MPL;

using ReadableTest = Register::Single<Int<1>,Int<0xFFFFFFFF>,Register::Policy::ReadableP,Register::Policy::IntConversionP>;
using WriteableTest = Register::Single<Int<1>,Int<0xFFFFFFFF>,Register::Policy::WriteableP,Register::Policy::IntConversionP>;
using PushableTest = Register::Single<Int<1>,Int<0xFFFFFFFF>,Register::Policy::PushableP,Register::Policy::IntConversionP>;
using PopableTest = Register::Single<Int<1>,Int<0xFFFFFFFF>,Register::Policy::PopableP,Register::Policy::IntConversionP>;
using ClearOnReadTest = Register::Single<Int<1>,Int<0xFFFFFFFF>,Register::Policy::ClearOnReadP,Register::Policy::IntConversionP>;

enum class CAN1PinSelectOption {Port0Pin0=0};


using CAN1PinSelect = Register::Single<Int<1234>,Int<0x0000000F>,List<Register::Policy::ReadableP,Register::Policy::WriteableP>,Register::Policy::EnumConversionP<CAN1PinSelectOption>>;

using RegList = List<Register::WriteActionT<1,1,2>,Register::WriteActionT<3,4,8>,Register::WriteActionT<1,8,16>,Register::WriteActionT<4,1,1>>;

using SortedRegisters = SortT<RegList,::Kvasir::Register::Detail::RegisterActionLessP>;
using MergedRegisters = typename ::Kvasir::Register::Detail::MergeRegisterActions<SortedRegisters>::Type;

static_assert(IsSame<SortedRegisters,List<Register::WriteActionT<1,8,16>,Register::WriteActionT<1,1,2>,Register::WriteActionT<3,4,8>,Register::WriteActionT<4,1,1>>>::value,"");
static_assert(IsSame<MergedRegisters,List<Register::WriteActionT<4,1,1>,Register::WriteActionT<3,4,8>,Register::WriteActionT<1,9,18>>>::value,"");

using FlattenedSequencePieces = MPL::List<
		MPL::SplitT<MPL::FlattenT<RegList>,Register::SequencePoint>,
		MPL::SplitT<MPL::FlattenT<RegList>,Register::SequencePoint>,
		MPL::SplitT<MPL::FlattenT<List<Register::WriteActionT<1,1,2>>>,Register::SequencePoint>
		>;
using Sorted = MPL::SortT<FlattenedSequencePieces,Startup::Detail::ListLengthLessP>;
using Type = typename Startup::Detail::Merge<MPL::List<>,Sorted>::Type;

template<typename>
struct Print;

void FTest(){
	//Print<MergedRegisters> p;
	ReadableTest::read();
	WriteableTest::write(1);
	PushableTest::push(1);
	PopableTest::pop();
	ClearOnReadTest::readAndClear();
	CAN1PinSelect::write(CAN1PinSelectOption::Port0Pin0);
}

int main(){}
void _kvasirInit(){}