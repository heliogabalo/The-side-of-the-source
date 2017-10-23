#!/bin/sh
## option deactivate tinyconfig

make  xenconfig \
	modules_install INSTALL_MOD_PATH=/usr \
	firmware_install INSTALL_FW_PATH=/usr \
	headers_install INSTALL_HDR_PATH=/usr
