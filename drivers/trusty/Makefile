#
# Makefile for trusty components
#
subdir-ccflags-y += -Werror

obj-$(CONFIG_TRUSTY)		+= trusty.o
obj-$(CONFIG_TRUSTY_SMC_ARM)	+= trusty-smc-arm.o
obj-$(CONFIG_TRUSTY_SMC_ARM64)	+= trusty-smc-arm64.o
obj-$(CONFIG_TRUSTY)		+= trusty-irq.o
obj-$(CONFIG_TRUSTY_FIQ)	+= trusty-fiq.o
obj-$(CONFIG_TRUSTY_FIQ_ARM)	+= trusty-fiq-arm.o
obj-$(CONFIG_TRUSTY_FIQ_ARM64)	+= trusty-fiq-arm64.o trusty-fiq-arm64-glue.o
obj-$(CONFIG_TRUSTY_LOG)	+= trusty-log.o
obj-$(CONFIG_TRUSTY)		+= trusty-mem.o
obj-$(CONFIG_TRUSTY_VIRTIO)	+= trusty-virtio.o
obj-$(CONFIG_TRUSTY_VIRTIO_IPC)	+= trusty-ipc.o
obj-$(CONFIG_TRUSTY)		+= trusty-ote.o
obj-$(CONFIG_TRUSTY)		+= trusty-otf-iface.o
