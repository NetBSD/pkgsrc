# $NetBSD: builtin.mk,v 1.1 2021/12/02 18:14:35 nia Exp $

X11_BUILTIN_NAME=	xf86-video-dummy
X11_DRV_NAME=		dummy_drv

.include "../../meta-pkgs/modular-xorg-drivers/builtin-common.mk"
