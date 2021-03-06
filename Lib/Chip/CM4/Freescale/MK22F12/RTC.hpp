#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Secure Real Time Clock
    namespace RtcTsr{    ///<RTC Time Seconds Register
        using Addr = Register::Address<0x4003d000,0x00000000,0x00000000,unsigned>;
        ///Time Seconds Register
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> tsr{}; 
    }
    namespace RtcTpr{    ///<RTC Time Prescaler Register
        using Addr = Register::Address<0x4003d004,0xffff0000,0x00000000,unsigned>;
        ///Time Prescaler Register
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> tpr{}; 
    }
    namespace RtcTar{    ///<RTC Time Alarm Register
        using Addr = Register::Address<0x4003d008,0x00000000,0x00000000,unsigned>;
        ///Time Alarm Register
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> tar{}; 
    }
    namespace RtcTcr{    ///<RTC Time Compensation Register
        using Addr = Register::Address<0x4003d00c,0x00000000,0x00000000,unsigned>;
        ///Time Compensation Register
        enum class TcrVal {
            v10000000=0x00000080,     ///<Time Prescaler Register overflows every 32896 clock cycles.
            v11111111=0x000000ff,     ///<Time Prescaler Register overflows every 32769 clock cycles.
            v0=0x00000000,     ///<Time Prescaler Register overflows every 32768 clock cycles.
            v1=0x00000001,     ///<Time Prescaler Register overflows every 32767 clock cycles.
            v1111111=0x0000007f,     ///<Time Prescaler Register overflows every 32641 clock cycles.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,TcrVal> tcr{}; 
        namespace TcrValC{
            constexpr Register::FieldValue<decltype(tcr)::Type,TcrVal::v10000000> v10000000{};
            constexpr Register::FieldValue<decltype(tcr)::Type,TcrVal::v11111111> v11111111{};
            constexpr Register::FieldValue<decltype(tcr)::Type,TcrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tcr)::Type,TcrVal::v1> v1{};
            constexpr Register::FieldValue<decltype(tcr)::Type,TcrVal::v1111111> v1111111{};
        }
        ///Compensation Interval Register
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,8),Register::ReadWriteAccess,unsigned> cir{}; 
        ///Time Compensation Value
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,16),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> tcv{}; 
        ///Compensation Interval Counter
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,24),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> cic{}; 
    }
    namespace RtcCr{    ///<RTC Control Register
        using Addr = Register::Address<0x4003d010,0xffffc0e0,0x00000000,unsigned>;
        ///Software Reset
        enum class SwrVal {
            v0=0x00000000,     ///<No effect.
            v1=0x00000001,     ///<Resets all RTC registers except for the SWR bit and the RTC_WAR and RTC_RAR registers . The SWR bit is cleared by POR and by software explicitly clearing it.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,SwrVal> swr{}; 
        namespace SwrValC{
            constexpr Register::FieldValue<decltype(swr)::Type,SwrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(swr)::Type,SwrVal::v1> v1{};
        }
        ///Wakeup Pin Enable
        enum class WpeVal {
            v0=0x00000000,     ///<Wakeup pin is disabled.
            v1=0x00000001,     ///<Wakeup pin is enabled and wakeup pin asserts if the RTC interrupt asserts or the wakeup pin is turned on.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,WpeVal> wpe{}; 
        namespace WpeValC{
            constexpr Register::FieldValue<decltype(wpe)::Type,WpeVal::v0> v0{};
            constexpr Register::FieldValue<decltype(wpe)::Type,WpeVal::v1> v1{};
        }
        ///Supervisor Access
        enum class SupVal {
            v0=0x00000000,     ///<Non-supervisor mode write accesses are not supported and generate a bus error.
            v1=0x00000001,     ///<Non-supervisor mode write accesses are supported.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,SupVal> sup{}; 
        namespace SupValC{
            constexpr Register::FieldValue<decltype(sup)::Type,SupVal::v0> v0{};
            constexpr Register::FieldValue<decltype(sup)::Type,SupVal::v1> v1{};
        }
        ///Update Mode
        enum class UmVal {
            v0=0x00000000,     ///<Registers cannot be written when locked.
            v1=0x00000001,     ///<Registers can be written when locked under limited conditions.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,UmVal> um{}; 
        namespace UmValC{
            constexpr Register::FieldValue<decltype(um)::Type,UmVal::v0> v0{};
            constexpr Register::FieldValue<decltype(um)::Type,UmVal::v1> v1{};
        }
        ///Wakeup Pin Select
        enum class WpsVal {
            v0=0x00000000,     ///<Wakeup pin asserts (active low, open drain) if the RTC interrupt asserts or the wakeup pin is turned on.
            v1=0x00000001,     ///<Wakeup pin instead outputs the RTC 32kHz clock, provided the wakeup pin is turned on and the 32kHz clock is output to other peripherals.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,WpsVal> wps{}; 
        namespace WpsValC{
            constexpr Register::FieldValue<decltype(wps)::Type,WpsVal::v0> v0{};
            constexpr Register::FieldValue<decltype(wps)::Type,WpsVal::v1> v1{};
        }
        ///Oscillator Enable
        enum class OsceVal {
            v0=0x00000000,     ///<32.768 kHz oscillator is disabled.
            v1=0x00000001,     ///<32.768 kHz oscillator is enabled. After setting this bit, wait the oscillator startup time before enabling the time counter to allow the 32.768 kHz clock time to stabilize.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,OsceVal> osce{}; 
        namespace OsceValC{
            constexpr Register::FieldValue<decltype(osce)::Type,OsceVal::v0> v0{};
            constexpr Register::FieldValue<decltype(osce)::Type,OsceVal::v1> v1{};
        }
        ///Clock Output
        enum class ClkoVal {
            v0=0x00000000,     ///<The 32 kHz clock is output to other peripherals.
            v1=0x00000001,     ///<The 32 kHz clock is not output to other peripherals.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,ClkoVal> clko{}; 
        namespace ClkoValC{
            constexpr Register::FieldValue<decltype(clko)::Type,ClkoVal::v0> v0{};
            constexpr Register::FieldValue<decltype(clko)::Type,ClkoVal::v1> v1{};
        }
        ///Oscillator 16pF Load Configure
        enum class Sc16pVal {
            v0=0x00000000,     ///<Disable the load.
            v1=0x00000001,     ///<Enable the additional load.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,Sc16pVal> sc16p{}; 
        namespace Sc16pValC{
            constexpr Register::FieldValue<decltype(sc16p)::Type,Sc16pVal::v0> v0{};
            constexpr Register::FieldValue<decltype(sc16p)::Type,Sc16pVal::v1> v1{};
        }
        ///Oscillator 8pF Load Configure
        enum class Sc8pVal {
            v0=0x00000000,     ///<Disable the load.
            v1=0x00000001,     ///<Enable the additional load.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,Sc8pVal> sc8p{}; 
        namespace Sc8pValC{
            constexpr Register::FieldValue<decltype(sc8p)::Type,Sc8pVal::v0> v0{};
            constexpr Register::FieldValue<decltype(sc8p)::Type,Sc8pVal::v1> v1{};
        }
        ///Oscillator 4pF Load Configure
        enum class Sc4pVal {
            v0=0x00000000,     ///<Disable the load.
            v1=0x00000001,     ///<Enable the additional load.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(12,12),Register::ReadWriteAccess,Sc4pVal> sc4p{}; 
        namespace Sc4pValC{
            constexpr Register::FieldValue<decltype(sc4p)::Type,Sc4pVal::v0> v0{};
            constexpr Register::FieldValue<decltype(sc4p)::Type,Sc4pVal::v1> v1{};
        }
        ///Oscillator 2pF Load Configure
        enum class Sc2pVal {
            v0=0x00000000,     ///<Disable the load.
            v1=0x00000001,     ///<Enable the additional load.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,13),Register::ReadWriteAccess,Sc2pVal> sc2p{}; 
        namespace Sc2pValC{
            constexpr Register::FieldValue<decltype(sc2p)::Type,Sc2pVal::v0> v0{};
            constexpr Register::FieldValue<decltype(sc2p)::Type,Sc2pVal::v1> v1{};
        }
    }
    namespace RtcSr{    ///<RTC Status Register
        using Addr = Register::Address<0x4003d014,0xffffffe0,0x00000000,unsigned>;
        ///Time Invalid Flag
        enum class TifVal {
            v0=0x00000000,     ///<Time is valid.
            v1=0x00000001,     ///<Time is invalid and time counter is read as zero.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,TifVal> tif{}; 
        namespace TifValC{
            constexpr Register::FieldValue<decltype(tif)::Type,TifVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tif)::Type,TifVal::v1> v1{};
        }
        ///Time Overflow Flag
        enum class TofVal {
            v0=0x00000000,     ///<Time overflow has not occurred.
            v1=0x00000001,     ///<Time overflow has occurred and time counter is read as zero.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,TofVal> tof{}; 
        namespace TofValC{
            constexpr Register::FieldValue<decltype(tof)::Type,TofVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tof)::Type,TofVal::v1> v1{};
        }
        ///Time Alarm Flag
        enum class TafVal {
            v0=0x00000000,     ///<Time alarm has not occurred.
            v1=0x00000001,     ///<Time alarm has occurred.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,TafVal> taf{}; 
        namespace TafValC{
            constexpr Register::FieldValue<decltype(taf)::Type,TafVal::v0> v0{};
            constexpr Register::FieldValue<decltype(taf)::Type,TafVal::v1> v1{};
        }
        ///Monotonic Overflow Flag
        enum class MofVal {
            v0=0x00000000,     ///<Monotonic counter overflow has not occurred.
            v1=0x00000001,     ///<Monotonic counter overflow has occurred and monotonic counter is read as zero.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,MofVal> mof{}; 
        namespace MofValC{
            constexpr Register::FieldValue<decltype(mof)::Type,MofVal::v0> v0{};
            constexpr Register::FieldValue<decltype(mof)::Type,MofVal::v1> v1{};
        }
        ///Time Counter Enable
        enum class TceVal {
            v0=0x00000000,     ///<Time counter is disabled.
            v1=0x00000001,     ///<Time counter is enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,TceVal> tce{}; 
        namespace TceValC{
            constexpr Register::FieldValue<decltype(tce)::Type,TceVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tce)::Type,TceVal::v1> v1{};
        }
    }
    namespace RtcLr{    ///<RTC Lock Register
        using Addr = Register::Address<0x4003d018,0xfffff087,0x00000000,unsigned>;
        ///Time Compensation Lock
        enum class TclVal {
            v0=0x00000000,     ///<Time Compensation Register is locked and writes are ignored.
            v1=0x00000001,     ///<Time Compensation Register is not locked and writes complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,TclVal> tcl{}; 
        namespace TclValC{
            constexpr Register::FieldValue<decltype(tcl)::Type,TclVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tcl)::Type,TclVal::v1> v1{};
        }
        ///Control Register Lock
        enum class CrlVal {
            v0=0x00000000,     ///<Control Register is locked and writes are ignored.
            v1=0x00000001,     ///<Control Register is not locked and writes complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,CrlVal> crl{}; 
        namespace CrlValC{
            constexpr Register::FieldValue<decltype(crl)::Type,CrlVal::v0> v0{};
            constexpr Register::FieldValue<decltype(crl)::Type,CrlVal::v1> v1{};
        }
        ///Status Register Lock
        enum class SrlVal {
            v0=0x00000000,     ///<Status Register is locked and writes are ignored.
            v1=0x00000001,     ///<Status Register is not locked and writes complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,SrlVal> srl{}; 
        namespace SrlValC{
            constexpr Register::FieldValue<decltype(srl)::Type,SrlVal::v0> v0{};
            constexpr Register::FieldValue<decltype(srl)::Type,SrlVal::v1> v1{};
        }
        ///Lock Register Lock
        enum class LrlVal {
            v0=0x00000000,     ///<Lock Register is locked and writes are ignored.
            v1=0x00000001,     ///<Lock Register is not locked and writes complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,LrlVal> lrl{}; 
        namespace LrlValC{
            constexpr Register::FieldValue<decltype(lrl)::Type,LrlVal::v0> v0{};
            constexpr Register::FieldValue<decltype(lrl)::Type,LrlVal::v1> v1{};
        }
        ///Tamper Time Seconds Lock
        enum class TtslVal {
            v0=0x00000000,     ///<Tamper Time Seconds Register is locked and writes are ignored.
            v1=0x00000001,     ///<Tamper Time Seconds Register is not locked and writes complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,TtslVal> ttsl{}; 
        namespace TtslValC{
            constexpr Register::FieldValue<decltype(ttsl)::Type,TtslVal::v0> v0{};
            constexpr Register::FieldValue<decltype(ttsl)::Type,TtslVal::v1> v1{};
        }
        ///Monotonic Enable Lock
        enum class MelVal {
            v0=0x00000000,     ///<Monotonic Enable Register is locked and writes are ignored.
            v1=0x00000001,     ///<Monotonic Enable Register is not locked and writes complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,MelVal> mel{}; 
        namespace MelValC{
            constexpr Register::FieldValue<decltype(mel)::Type,MelVal::v0> v0{};
            constexpr Register::FieldValue<decltype(mel)::Type,MelVal::v1> v1{};
        }
        ///Monotonic Counter Low Lock
        enum class McllVal {
            v0=0x00000000,     ///<Monotonic Counter Low Register is locked and writes are ignored.
            v1=0x00000001,     ///<Monotonic Counter Low Register is not locked and writes complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,McllVal> mcll{}; 
        namespace McllValC{
            constexpr Register::FieldValue<decltype(mcll)::Type,McllVal::v0> v0{};
            constexpr Register::FieldValue<decltype(mcll)::Type,McllVal::v1> v1{};
        }
        ///Monotonic Counter High Lock
        enum class MchlVal {
            v0=0x00000000,     ///<Monotonic Counter High Register is locked and writes are ignored.
            v1=0x00000001,     ///<Monotonic Counter High Register is not locked and writes complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,MchlVal> mchl{}; 
        namespace MchlValC{
            constexpr Register::FieldValue<decltype(mchl)::Type,MchlVal::v0> v0{};
            constexpr Register::FieldValue<decltype(mchl)::Type,MchlVal::v1> v1{};
        }
    }
    namespace RtcIer{    ///<RTC Interrupt Enable Register
        using Addr = Register::Address<0x4003d01c,0xffffff60,0x00000000,unsigned>;
        ///Time Invalid Interrupt Enable
        enum class TiieVal {
            v0=0x00000000,     ///<Time invalid flag does not generate an interrupt.
            v1=0x00000001,     ///<Time invalid flag does generate an interrupt.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,TiieVal> tiie{}; 
        namespace TiieValC{
            constexpr Register::FieldValue<decltype(tiie)::Type,TiieVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tiie)::Type,TiieVal::v1> v1{};
        }
        ///Time Overflow Interrupt Enable
        enum class ToieVal {
            v0=0x00000000,     ///<Time overflow flag does not generate an interrupt.
            v1=0x00000001,     ///<Time overflow flag does generate an interrupt.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,ToieVal> toie{}; 
        namespace ToieValC{
            constexpr Register::FieldValue<decltype(toie)::Type,ToieVal::v0> v0{};
            constexpr Register::FieldValue<decltype(toie)::Type,ToieVal::v1> v1{};
        }
        ///Time Alarm Interrupt Enable
        enum class TaieVal {
            v0=0x00000000,     ///<Time alarm flag does not generate an interrupt.
            v1=0x00000001,     ///<Time alarm flag does generate an interrupt.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,TaieVal> taie{}; 
        namespace TaieValC{
            constexpr Register::FieldValue<decltype(taie)::Type,TaieVal::v0> v0{};
            constexpr Register::FieldValue<decltype(taie)::Type,TaieVal::v1> v1{};
        }
        ///Monotonic Overflow Interrupt Enable
        enum class MoieVal {
            v0=0x00000000,     ///<Monotonic overflow flag does not generate an interrupt.
            v1=0x00000001,     ///<Monotonic overflow flag does generate an interrupt.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,MoieVal> moie{}; 
        namespace MoieValC{
            constexpr Register::FieldValue<decltype(moie)::Type,MoieVal::v0> v0{};
            constexpr Register::FieldValue<decltype(moie)::Type,MoieVal::v1> v1{};
        }
        ///Time Seconds Interrupt Enable
        enum class TsieVal {
            v0=0x00000000,     ///<Seconds interrupt is disabled.
            v1=0x00000001,     ///<Seconds interrupt is enabled.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,TsieVal> tsie{}; 
        namespace TsieValC{
            constexpr Register::FieldValue<decltype(tsie)::Type,TsieVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tsie)::Type,TsieVal::v1> v1{};
        }
        ///Wakeup Pin On
        enum class WponVal {
            v0=0x00000000,     ///<No effect.
            v1=0x00000001,     ///<If the wakeup pin is enabled, then the wakeup pin will assert.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,WponVal> wpon{}; 
        namespace WponValC{
            constexpr Register::FieldValue<decltype(wpon)::Type,WponVal::v0> v0{};
            constexpr Register::FieldValue<decltype(wpon)::Type,WponVal::v1> v1{};
        }
    }
    namespace RtcTtsr{    ///<RTC Tamper Time Seconds Register
        using Addr = Register::Address<0x4003d020,0x00000000,0x00000000,unsigned>;
        ///Tamper Time Seconds
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::Access<Register::AccessType::readOnly,Register::ReadActionType::normal,Register::ModifiedWriteValueType::normal>,unsigned> tts{}; 
    }
    namespace RtcMer{    ///<RTC Monotonic Enable Register
        using Addr = Register::Address<0x4003d024,0xffffffef,0x00000000,unsigned>;
        ///Monotonic Counter Enable
        enum class MceVal {
            v0=0x00000000,     ///<Writes to the monotonic counter load the counter with the value written.
            v1=0x00000001,     ///<Writes to the monotonic counter increment the counter.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,MceVal> mce{}; 
        namespace MceValC{
            constexpr Register::FieldValue<decltype(mce)::Type,MceVal::v0> v0{};
            constexpr Register::FieldValue<decltype(mce)::Type,MceVal::v1> v1{};
        }
    }
    namespace RtcMclr{    ///<RTC Monotonic Counter Low Register
        using Addr = Register::Address<0x4003d028,0x00000000,0x00000000,unsigned>;
        ///Monotonic Counter Low
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> mcl{}; 
    }
    namespace RtcMchr{    ///<RTC Monotonic Counter High Register
        using Addr = Register::Address<0x4003d02c,0x00000000,0x00000000,unsigned>;
        ///Monotonic Counter High
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> mch{}; 
    }
    namespace RtcWar{    ///<RTC Write Access Register
        using Addr = Register::Address<0x4003d800,0xfffff000,0x00000000,unsigned>;
        ///Time Seconds Register Write
        enum class TsrwVal {
            v0=0x00000000,     ///<Writes to the Time Seconds Register are ignored.
            v1=0x00000001,     ///<Writes to the Time Seconds Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,TsrwVal> tsrw{}; 
        namespace TsrwValC{
            constexpr Register::FieldValue<decltype(tsrw)::Type,TsrwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tsrw)::Type,TsrwVal::v1> v1{};
        }
        ///Time Prescaler Register Write
        enum class TprwVal {
            v0=0x00000000,     ///<Writes to the Time Prescaler Register are ignored.
            v1=0x00000001,     ///<Writes to the Time Prescaler Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,TprwVal> tprw{}; 
        namespace TprwValC{
            constexpr Register::FieldValue<decltype(tprw)::Type,TprwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tprw)::Type,TprwVal::v1> v1{};
        }
        ///Time Alarm Register Write
        enum class TarwVal {
            v0=0x00000000,     ///<Writes to the Time Alarm Register are ignored.
            v1=0x00000001,     ///<Writes to the Time Alarm Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,TarwVal> tarw{}; 
        namespace TarwValC{
            constexpr Register::FieldValue<decltype(tarw)::Type,TarwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tarw)::Type,TarwVal::v1> v1{};
        }
        ///Time Compensation Register Write
        enum class TcrwVal {
            v0=0x00000000,     ///<Writes to the Time Compensation Register are ignored.
            v1=0x00000001,     ///<Writes to the Time Compensation Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,TcrwVal> tcrw{}; 
        namespace TcrwValC{
            constexpr Register::FieldValue<decltype(tcrw)::Type,TcrwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tcrw)::Type,TcrwVal::v1> v1{};
        }
        ///Control Register Write
        enum class CrwVal {
            v0=0x00000000,     ///<Writes to the Control Register are ignored.
            v1=0x00000001,     ///<Writes to the Control Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,CrwVal> crw{}; 
        namespace CrwValC{
            constexpr Register::FieldValue<decltype(crw)::Type,CrwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(crw)::Type,CrwVal::v1> v1{};
        }
        ///Status Register Write
        enum class SrwVal {
            v0=0x00000000,     ///<Writes to the Status Register are ignored.
            v1=0x00000001,     ///<Writes to the Status Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,SrwVal> srw{}; 
        namespace SrwValC{
            constexpr Register::FieldValue<decltype(srw)::Type,SrwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(srw)::Type,SrwVal::v1> v1{};
        }
        ///Lock Register Write
        enum class LrwVal {
            v0=0x00000000,     ///<Writes to the Lock Register are ignored.
            v1=0x00000001,     ///<Writes to the Lock Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,LrwVal> lrw{}; 
        namespace LrwValC{
            constexpr Register::FieldValue<decltype(lrw)::Type,LrwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(lrw)::Type,LrwVal::v1> v1{};
        }
        ///Interrupt Enable Register Write
        enum class IerwVal {
            v0=0x00000000,     ///<Writes to the Interupt Enable Register are ignored.
            v1=0x00000001,     ///<Writes to the Interrupt Enable Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,IerwVal> ierw{}; 
        namespace IerwValC{
            constexpr Register::FieldValue<decltype(ierw)::Type,IerwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(ierw)::Type,IerwVal::v1> v1{};
        }
        ///Tamper Time Seconds Write
        enum class TtswVal {
            v0=0x00000000,     ///<Writes to the Tamper Time Seconds Register are ignored.
            v1=0x00000001,     ///<Writes to the Tamper Time Seconds Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,TtswVal> ttsw{}; 
        namespace TtswValC{
            constexpr Register::FieldValue<decltype(ttsw)::Type,TtswVal::v0> v0{};
            constexpr Register::FieldValue<decltype(ttsw)::Type,TtswVal::v1> v1{};
        }
        ///Monotonic Enable Register Write
        enum class MerwVal {
            v0=0x00000000,     ///<Writes to the Monotonic Enable Register are ignored.
            v1=0x00000001,     ///<Writes to the Monotonic Enable Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,MerwVal> merw{}; 
        namespace MerwValC{
            constexpr Register::FieldValue<decltype(merw)::Type,MerwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(merw)::Type,MerwVal::v1> v1{};
        }
        ///Monotonic Counter Low Write
        enum class MclwVal {
            v0=0x00000000,     ///<Writes to the Monotonic Counter Low Register are ignored.
            v1=0x00000001,     ///<Writes to the Monotonic Counter Low Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,MclwVal> mclw{}; 
        namespace MclwValC{
            constexpr Register::FieldValue<decltype(mclw)::Type,MclwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(mclw)::Type,MclwVal::v1> v1{};
        }
        ///Monotonic Counter High Write
        enum class MchwVal {
            v0=0x00000000,     ///<Writes to the Monotonic Counter High Register are ignored.
            v1=0x00000001,     ///<Writes to the Monotonic Counter High Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,MchwVal> mchw{}; 
        namespace MchwValC{
            constexpr Register::FieldValue<decltype(mchw)::Type,MchwVal::v0> v0{};
            constexpr Register::FieldValue<decltype(mchw)::Type,MchwVal::v1> v1{};
        }
    }
    namespace RtcRar{    ///<RTC Read Access Register
        using Addr = Register::Address<0x4003d804,0xfffff000,0x00000000,unsigned>;
        ///Time Seconds Register Read
        enum class TsrrVal {
            v0=0x00000000,     ///<Reads to the Time Seconds Register are ignored.
            v1=0x00000001,     ///<Reads to the Time Seconds Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(0,0),Register::ReadWriteAccess,TsrrVal> tsrr{}; 
        namespace TsrrValC{
            constexpr Register::FieldValue<decltype(tsrr)::Type,TsrrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tsrr)::Type,TsrrVal::v1> v1{};
        }
        ///Time Prescaler Register Read
        enum class TprrVal {
            v0=0x00000000,     ///<Reads to the Time Pprescaler Register are ignored.
            v1=0x00000001,     ///<Reads to the Time Prescaler Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,1),Register::ReadWriteAccess,TprrVal> tprr{}; 
        namespace TprrValC{
            constexpr Register::FieldValue<decltype(tprr)::Type,TprrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tprr)::Type,TprrVal::v1> v1{};
        }
        ///Time Alarm Register Read
        enum class TarrVal {
            v0=0x00000000,     ///<Reads to the Time Alarm Register are ignored.
            v1=0x00000001,     ///<Reads to the Time Alarm Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,TarrVal> tarr{}; 
        namespace TarrValC{
            constexpr Register::FieldValue<decltype(tarr)::Type,TarrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tarr)::Type,TarrVal::v1> v1{};
        }
        ///Time Compensation Register Read
        enum class TcrrVal {
            v0=0x00000000,     ///<Reads to the Time Compensation Register are ignored.
            v1=0x00000001,     ///<Reads to the Time Compensation Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,TcrrVal> tcrr{}; 
        namespace TcrrValC{
            constexpr Register::FieldValue<decltype(tcrr)::Type,TcrrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(tcrr)::Type,TcrrVal::v1> v1{};
        }
        ///Control Register Read
        enum class CrrVal {
            v0=0x00000000,     ///<Reads to the Control Register are ignored.
            v1=0x00000001,     ///<Reads to the Control Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,CrrVal> crr{}; 
        namespace CrrValC{
            constexpr Register::FieldValue<decltype(crr)::Type,CrrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(crr)::Type,CrrVal::v1> v1{};
        }
        ///Status Register Read
        enum class SrrVal {
            v0=0x00000000,     ///<Reads to the Status Register are ignored.
            v1=0x00000001,     ///<Reads to the Status Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,SrrVal> srr{}; 
        namespace SrrValC{
            constexpr Register::FieldValue<decltype(srr)::Type,SrrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(srr)::Type,SrrVal::v1> v1{};
        }
        ///Lock Register Read
        enum class LrrVal {
            v0=0x00000000,     ///<Reads to the Lock Register are ignored.
            v1=0x00000001,     ///<Reads to the Lock Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,LrrVal> lrr{}; 
        namespace LrrValC{
            constexpr Register::FieldValue<decltype(lrr)::Type,LrrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(lrr)::Type,LrrVal::v1> v1{};
        }
        ///Interrupt Enable Register Read
        enum class IerrVal {
            v0=0x00000000,     ///<Reads to the Interrupt Enable Register are ignored.
            v1=0x00000001,     ///<Reads to the Interrupt Enable Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,IerrVal> ierr{}; 
        namespace IerrValC{
            constexpr Register::FieldValue<decltype(ierr)::Type,IerrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(ierr)::Type,IerrVal::v1> v1{};
        }
        ///Tamper Time Seconds Read
        enum class TtsrVal {
            v0=0x00000000,     ///<Reads to the Tamper Time Seconds Register are ignored.
            v1=0x00000001,     ///<Reads to the Tamper Time Seconds Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(8,8),Register::ReadWriteAccess,TtsrVal> ttsr{}; 
        namespace TtsrValC{
            constexpr Register::FieldValue<decltype(ttsr)::Type,TtsrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(ttsr)::Type,TtsrVal::v1> v1{};
        }
        ///Monotonic Enable Register Read
        enum class MerrVal {
            v0=0x00000000,     ///<Reads to the Monotonic Enable Register are ignored.
            v1=0x00000001,     ///<Reads to the Monotonic Enable Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(9,9),Register::ReadWriteAccess,MerrVal> merr{}; 
        namespace MerrValC{
            constexpr Register::FieldValue<decltype(merr)::Type,MerrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(merr)::Type,MerrVal::v1> v1{};
        }
        ///Monotonic Counter Low Read
        enum class MclrVal {
            v0=0x00000000,     ///<Reads to the Monotonic Counter Low Register are ignored.
            v1=0x00000001,     ///<Reads to the Monotonic Counter Low Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(10,10),Register::ReadWriteAccess,MclrVal> mclr{}; 
        namespace MclrValC{
            constexpr Register::FieldValue<decltype(mclr)::Type,MclrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(mclr)::Type,MclrVal::v1> v1{};
        }
        ///Monotonic Counter High Read
        enum class MchrVal {
            v0=0x00000000,     ///<Reads to the Monotonic Counter High Register are ignored.
            v1=0x00000001,     ///<Reads to the Monotonic Counter High Register complete as normal.
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,11),Register::ReadWriteAccess,MchrVal> mchr{}; 
        namespace MchrValC{
            constexpr Register::FieldValue<decltype(mchr)::Type,MchrVal::v0> v0{};
            constexpr Register::FieldValue<decltype(mchr)::Type,MchrVal::v1> v1{};
        }
    }
}
