from scripts.patches.base import Patch, Context
from scripts.core.patcher import Patcher
import logging

logger = logging.getLogger(__name__)

class SetCalibOffsetPatch(Patch):
    @property
    def name(self) -> str:
        return "Set true calibration flash offset to 0x8E10"

    def apply(self, patcher: Patcher, ctx: Context):
        # 0x1C005396 -> li a0, 0x8E10; ret
        patcher.write_bytes(0x0396, bytes.fromhex("379500001b0505e1678000000100"))
        logger.info("Patched 0x1C005396 -> li a0, 0x8E10; ret")
