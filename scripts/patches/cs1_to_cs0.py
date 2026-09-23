from scripts.patches.base import Patch, Context
from scripts.core.patcher import Patcher
import logging

logger = logging.getLogger(__name__)

class CS1ToCS0Patch(Patch):
    @property
    def name(self) -> str:
        return "Redirect CS1 PHY registers to CS0"

    def apply(self, patcher: Patcher, ctx: Context):
        for off in (0x3F92, 0x3FA2, 0x40EA, 0x40FE, 0x424C, 0x425C):
            b = patcher.read_bytes(off + 2, 1)[0]
            if b != 0x04:
                raise ValueError(f"Offset {off:#x} byte+2 is {b:#x}, expected 0x04")
            patcher.write_bytes(off + 2, b'\x00')
            
        logger.info("Redirected CS1 PHY registers to CS0 (6 instructions)")
