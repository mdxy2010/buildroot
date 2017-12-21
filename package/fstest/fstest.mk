################################################################################
#
# fstest
#
################################################################################

#FSTEST_VERSION = fstest-2.7
FSTEST_SITE = $(call qstrip,$(BR2_FSTEST_CUSTOM_LOCAL_PATH))
FSTEST_SITE_METHOD = local

ifeq ($(BR2_PACKAGE_LIBAIO),y)
FSTEST_DEPENDENCIES += libaio
endif

#define FSTEST_CONFIGURE_CMDS
#	(cd $(@D); ./configure --cc="$(TARGET_CC)" --extra-cflags="$(TARGET_CFLAGS)")
#endef

define FSTEST_BUILD_CMDS
	$(MAKE) -C $(@D)
endef

define FSTEST_INSTALL_TARGET_CMDS
	$(INSTALL) -D $(@D)/fstest $(TARGET_DIR)/usr/bin/fstest
endef

$(eval $(generic-package))
