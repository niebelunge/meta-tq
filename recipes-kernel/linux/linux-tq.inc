FILESEXTRAPATHS_prepend := "${THISDIR}/linux-tq-common:"

SRC_URI_append = " \
  file://0001-perf-Make-perf-able-to-build-with-latest-libbfd.patch \
"
