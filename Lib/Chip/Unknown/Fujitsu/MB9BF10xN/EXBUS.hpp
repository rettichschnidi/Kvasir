#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//External Bus Interface
    namespace ExbusMode0{    ///<Mode Register 0
        using Addr = Register::Address<0x4003f000,0xffffff00,0x00000000,unsigned>;
        ///select to which idle cycle the write data output is extended
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,7),Register::ReadWriteAccess,unsigned> shrtdout{}; 
        ///control the external RDY function
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(6,6),Register::ReadWriteAccess,unsigned> rdy{}; 
        ///NOR Flash memory page access mode 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(5,5),Register::ReadWriteAccess,unsigned> page{}; 
        ///NAND Flash memory mode
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(4,4),Register::ReadWriteAccess,unsigned> nand{}; 
        ///disable the write enable signal (MWEX) operation
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,3),Register::ReadWriteAccess,unsigned> weoff{}; 
        ///Read Byte Mask ON
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> rbmon{}; 
        ///specify Data Width 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,unsigned> wdth{}; 
    }
    namespace ExbusMode1{    ///<Mode Register 1
        using Addr = Register::Address<0x4003f004,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusMode2{    ///<Mode Register 2
        using Addr = Register::Address<0x4003f008,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusMode3{    ///<Mode Register 3
        using Addr = Register::Address<0x4003f00c,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusMode7{    ///<Mode Register 7
        using Addr = Register::Address<0x4003f01c,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim0{    ///<Timing Register 0
        using Addr = Register::Address<0x4003f020,0x00000000,0x00000000,unsigned>;
        ///Write Idle Cycle 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,28),Register::ReadWriteAccess,unsigned> widlc{}; 
        ///Write Enable Cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(27,24),Register::ReadWriteAccess,unsigned> wwec{}; 
        ///Write Address Setup cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(23,20),Register::ReadWriteAccess,unsigned> wadc{}; 
        ///Write Access Cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(19,16),Register::ReadWriteAccess,unsigned> wacc{}; 
        ///Read Idle Cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,12),Register::ReadWriteAccess,unsigned> ridlc{}; 
        ///First Read Address Cycle 
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(11,8),Register::ReadWriteAccess,unsigned> fradc{}; 
        ///Read Address Setup cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,4),Register::ReadWriteAccess,unsigned> radc{}; 
        ///Read Access Cycle
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(3,0),Register::ReadWriteAccess,unsigned> racc{}; 
    }
    namespace ExbusTim1{    ///<Timing Register 1
        using Addr = Register::Address<0x4003f024,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim2{    ///<Timing Register 2
        using Addr = Register::Address<0x4003f028,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim3{    ///<Timing Register 3
        using Addr = Register::Address<0x4003f02c,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusTim7{    ///<Timing Register 7
        using Addr = Register::Address<0x4003f03c,0xffffffff,0x00000000,unsigned>;
    }
    namespace ExbusArea0{    ///<Area Register 0
        using Addr = Register::Address<0x4003f040,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea1{    ///<Area Register 1
        using Addr = Register::Address<0x4003f044,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea2{    ///<Area Register 2
        using Addr = Register::Address<0x4003f048,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea3{    ///<Area Register 3
        using Addr = Register::Address<0x4003f04c,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
    namespace ExbusArea7{    ///<Area Register 7
        using Addr = Register::Address<0x4003f05c,0xff80ff00,0x00000000,unsigned>;
        ///address mask
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(22,16),Register::ReadWriteAccess,unsigned> mask{}; 
        ///Address
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(7,0),Register::ReadWriteAccess,unsigned> addr{}; 
    }
}
