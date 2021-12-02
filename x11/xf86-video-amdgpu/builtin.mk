# $NetBSD: builtin.mk,v 1.1 2021/12/02 18:14:34 nia Exp $

X11_BUILTIN_NAME=	xf86-video-amdgpu
X11_DRV_NAME=		amdgpu_drv

.include "../../meta-pkgs/modular-xorg-drivers/builtin-common.mk"
