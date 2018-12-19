SUMMARY = "Linux kernel for TQ-Group TI AM57 based modules"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

inherit kernel

require recipes-kernel/linux/linux-dtb.inc

SRC_URI = " \
    ${TQ_GIT_BASEURL}/linux-tqmaxx.git;protocol=${TQ_GIT_PROTOCOL};branch=${SRCBRANCH} \
    file://defconfig \
"

# TODO: adopt SRCREV and SRCBRANCH when available on github */
SRCBRANCH = "TQMa57xx-linux-ti-v4.9.77-rt61"
SRCREV = "3598123589fe7d2cbc4e1b3ab4fa4ce8c0ed0419"

KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_ENTRYPOINT}"

COMPATIBLE_MACHINE = "(tqma572x-mba57xx)"

S = "${WORKDIR}/git"
