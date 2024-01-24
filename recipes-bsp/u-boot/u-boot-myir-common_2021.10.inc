# Adaptation from u-boot-common_${PV}.inc

HOMEPAGE = "http://www.denx.de/wiki/U-Boot/WebHome"
SECTION = "bootloaders"

LICENSE = "GPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=5a7450c57ffe5ae63fd732446b988025"

DEPENDS += "dtc-native bc-native"
DEPENDS += "flex-native bison-native"
DEPENDS += "python3-setuptools-native"

COMPATIBLE_MACHINE = "(stm32mpcommon)"


SRC_URI = "git://git@github.com/SPACE-Yonsei/myir-st-u-boot.git;protocol=ssh;branch=${SRCBRANCH}"
SRCREV  = "${AUTOREV}"
SRCBRANCH = "altair-develop"




U_BOOT_VERSION = "v2021.10"
U_BOOT_SUBVERSION = "stm32mp"
U_BOOT_RELEASE = "r2"

PV = "${U_BOOT_VERSION}-${U_BOOT_SUBVERSION}-${U_BOOT_RELEASE}"

ARCHIVER_ST_BRANCH = "develop-${U_BOOT_VERSION}-${U_BOOT_SUBVERSION}"
ARCHIVER_ST_REVISION = "${PV}"
ARCHIVER_COMMUNITY_BRANCH = "develop-v2021.10-stm32mp"
ARCHIVER_COMMUNITY_REVISION = "${U_BOOT_VERSION}"

S = "${WORKDIR}/git"

# ---------------------------------
# Configure devupstream class usage
# ---------------------------------
BBCLASSEXTEND = "devupstream:target"

SRC_URI:class-devupstream = "git://git@github.com/SPACE-Yonsei/myir-st-u-boot.git;protocol=ssh;branch=${SRCBRANCH}"
SRCREV:class-devupstream = "${AUTOREV}"

# ---------------------------------
# Configure default preference to manage dynamic selection between tarball and github
# ---------------------------------
STM32MP_SOURCE_SELECTION ?= "tarball"

DEFAULT_PREFERENCE = "${@bb.utils.contains('STM32MP_SOURCE_SELECTION', 'github', '-1', '1', d)}"
