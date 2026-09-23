from abc import ABC, abstractmethod
from typing import Any

class Context:
    def __init__(self, variant: int, vnum: int, defs: list[str]):
        self.variant = variant
        self.vnum = vnum
        self.defs = defs
        # Build artifacts
        self.dbg_code = b''
        self.normini_code = b''
        self.ddrload_code = b''
        # Key variables shared between patches
        self.LOAD_ADDR = 0x1c005000
        self.DBG_OFF = 0x7DAC
        self.DBG_VMA = self.LOAD_ADDR + self.DBG_OFF
        
        self.M_SKIP = 0
        self.M_B = 0
        self.M_N = 0
        self.M_D = 0
        self.M_P = 0
        
        self.NOR_READ_EMUL = 0
        self.DDR_LOAD2 = 0
        self.NOR_READ_VMA = self.LOAD_ADDR + 0xd08
        self.symbols: dict[str, int] = {}

class Patch(ABC):
    @property
    @abstractmethod
    def name(self) -> str:
        pass

    @abstractmethod
    def apply(self, patcher: 'Patcher', ctx: Context):
        pass
