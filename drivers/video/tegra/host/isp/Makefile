GCOV_PROFILE := y
ccflags-y += -I$(srctree.nvidia)/drivers/video/tegra/host
ccflags-y += -Idrivers/video/tegra/host
ccflags-y += -Idrivers/video/tegra/camera
ccflags-y += -Werror

nvhost-isp-objs  = \
		isp_isr_v1.o \
		isp.o

obj-$(CONFIG_TEGRA_GRHOST_ISP) += nvhost-isp.o

ifneq ($(filter y,$(CONFIG_ARCH_TEGRA_18x_SOC) $(CONFIG_ARCH_TEGRA_186_SOC)),)
nvhost-isp-t186-objs  = \
		isp_isr_v2.o

obj-$(CONFIG_TEGRA_GRHOST_ISP) += nvhost-isp-t186.o
endif

ccflags-y += -I$(srctree.nvidia)/drivers/media/platform/tegra
ccflags-y += -I$(srctree.nvidia)/include

nvhost-isp5-objs = isp5.o

obj-y += nvhost-isp5.o
