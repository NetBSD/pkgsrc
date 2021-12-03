# $NetBSD: builtin.mk,v 1.1 2021/12/03 12:47:54 nia Exp $

X11_BUILTIN_NAME=	xf86-input-mouse
X11_DRV_NAME=		mouse_drv

.include "../../meta-pkgs/modular-xorg-drivers/builtin-common.mk"
