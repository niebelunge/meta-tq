# Common definitions for TQ-Group TQMLS102xa modules

require conf/machine/include/soc-family.inc

MACHINEOVERRIDES =. "ls102xa:"

DEFAULTTUNE ?= "cortexa7thf-neon"
require conf/machine/include/tune-cortexa7.inc

# TQ u-boot and kernel
#
PREFERRED_PROVIDER_u-boot_ls102xa ?= "u-boot-tq"
PREFERRED_PROVIDER_virtual/bootloader_ls102xa ?= "u-boot-tq"
PREFERRED_PROVIDER_virtual/kernel_ls102xa ?= "linux-tq"

# Define the default image type
KERNEL_IMAGETYPE ?= "zImage"

UBOOT_ENTRYPOINT_ls102xa = "0x80008000"

# Machine specific options
#

MACHINE_EXTRA_RRECOMMENDS = " kernel-modules kernel-devicetree udev-extraconf"

# provide info about machine's capabilities
MACHINE_FEATURES_append = " alsa pci sata rtc usbhost vfat ext2 ext3 ext4 serial"

# Image Options
#
EXTRA_IMAGEDEPENDS += "u-boot"
IMAGE_FSTYPES ?= "tar.gz ext4 wic ubi"

# needed for Rootfs on QSPI
IMAGE_INSTALL_append = " mtd-utils-jffs2 mtd-utils-ubifs mtd-utils-misc"

# from PTXdist BSP:
# PTXCONF_IMAGE_ROOT_UBIFS_PEB_SIZE="65536"
# PTXCONF_IMAGE_ROOT_UBIFS_MINIMUM_IO_UNIT_SIZE="1"
# PTXCONF_IMAGE_ROOT_UBIFS_SUB_PAGE_SIZE="1"
# PTXCONF_IMAGE_ROOT_UBIFS_VID_HEADER_OFFSET="64"
# PTXCONF_IMAGE_ROOT_UBIFS_LEB_SIZE="65408"

MKUBIFS_ARGS = " -m 1 -e 65408 -c 896 "
UBINIZE_ARGS = " -p 65536 -m 1 -s 1 "
# needs to be set to have it consistent for kernel command line
UBI_VOLNAME = "root"

WKS_FILE ?= "tqmls102xa-sdimg.wks"

do_image_wic[depends] += "\
	mtools-native:do_populate_sysroot \
	dosfstools-native:do_populate_sysroot \
	parted-native:do_populate_sysroot \
	virtual/kernel:do_deploy \
	u-boot:do_deploy \
	"
