subdir-ccflags-y += -Werror

obj-$(CONFIG_SAF775x_HWDEP) += saf775x-hwdep.o

saf775x-hwdep-objs := \
	saf775x_stub.o \
	saf775x_ioctl.o
ifdef CONFIG_COMPAT
	saf775x-hwdep-objs += compat_saf775x_ioctl.o
endif
