from typing import Type
from scripts.patches.base import Patch
from scripts.patches import link_stubs, cs1_to_cs0, set_calib_offset

# Dynamically import or explicitly register patches
VARIANTS = {
    143: {
        "name": "157v1",
        "patches": [
            link_stubs.LinkStubsPatch(),
            cs1_to_cs0.CS1ToCS0Patch(),
            set_calib_offset.SetCalibOffsetPatch(),
        ]
    },
    144: {
        "name": "157v2",
        "patches": [
            link_stubs.LinkStubsPatch(),
            cs1_to_cs0.CS1ToCS0Patch(),
            set_calib_offset.SetCalibOffsetPatch(),
        ]
    },
    145: {
        "name": "157v3",
        "patches": [
            link_stubs.LinkStubsPatch(),
            cs1_to_cs0.CS1ToCS0Patch(),
            set_calib_offset.SetCalibOffsetPatch(),
        ]
    },
    146: {
        "name": "157v4",
        "patches": [
            link_stubs.LinkStubsPatch(),
            cs1_to_cs0.CS1ToCS0Patch(),
            set_calib_offset.SetCalibOffsetPatch(),
        ]
    },
    147: {
        "name": "157v5",
        "patches": [
            link_stubs.LinkStubsPatch(),
            cs1_to_cs0.CS1ToCS0Patch(),
            set_calib_offset.SetCalibOffsetPatch(),
        ]
    },
    148: {
        "name": "157v6",
        "patches": [
            link_stubs.LinkStubsPatch(),
            cs1_to_cs0.CS1ToCS0Patch(),
            set_calib_offset.SetCalibOffsetPatch(),
        ]
    },
    149: {
        "name": "157v7",
        "patches": [
            link_stubs.LinkStubsPatch(),
            cs1_to_cs0.CS1ToCS0Patch(),
            set_calib_offset.SetCalibOffsetPatch(),
        ]
    }
}
