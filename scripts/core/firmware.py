import logging

logger = logging.getLogger(__name__)

class FirmwareImage:
    def __init__(self, fbl_data: bytearray, uboot_data: bytes):
        self.fbl_data = fbl_data
        self.uboot_data = uboot_data
        self.nor_size = 16 * 1024 * 1024
        self.uboot_offset = 0x40000

    def generate_nor_image(self) -> bytearray:
        img = bytearray(self.fbl_data)
        
        # Pad FBL to uboot offset
        if len(img) < self.uboot_offset:
            img += bytearray([0xFF] * (self.uboot_offset - len(img)))
        elif len(img) > self.uboot_offset:
            raise ValueError(f"FBL size {len(img):#x} exceeds u-boot offset {self.uboot_offset:#x}")
            
        # Append u-boot
        img += self.uboot_data
        
        # Pad to full NOR size
        if len(img) < self.nor_size:
            img += bytearray([0xFF] * (self.nor_size - len(img)))
        elif len(img) > self.nor_size:
            raise ValueError(f"Total image size {len(img):#x} exceeds NOR size {self.nor_size:#x}")
            
        return img
