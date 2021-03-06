# Common definitions for TQ-Group TQMa6UL modules

MACHINEOVERRIDES =. "mx6ul:"

DEFAULTTUNE ?= "cortexa7thf-neon"
require conf/machine/include/tune-cortexa7.inc

# Machine specific options
#
MACHINE_EXTRA_RRECOMMENDS = " kernel-modules kernel-devicetree"
MACHINE_FEATURES_append = " alsa"

# TQ u-boot and kernel
#
PREFERRED_PROVIDER_virtual/kernel ?= "linux-tq"
KERNEL_IMAGETYPE = "zImage"

PREFERRED_PROVIDER_u-boot = "u-boot-tq"
PREFERRED_PROVIDER_virtual/bootloader ?= "u-boot-tq"

UBOOT_SUFFIX ?= "imx"
UBOOT_MAKE_TARGET ?= "u-boot.imx"

# Image Options
#
EXTRA_IMAGEDEPENDS += "u-boot"
IMAGE_FSTYPES ?= "tar.gz ext4 wic"

do_image_wic[depends] += "\
	mtools-native:do_populate_sysroot \
	dosfstools-native:do_populate_sysroot \
	parted-native:do_populate_sysroot \
	"

# TODO:
#IMAGE_INSTALL_append = " kernel-devicetree kernel-image-zimage"

# source the machine specific features for multimedia etc. from meta-fsl-arm
include conf/machine/include/imx-base.inc
