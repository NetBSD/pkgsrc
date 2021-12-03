# $NetBSD: builtin.mk,v 1.1 2021/12/03 12:47:53 nia Exp $

X11_BUILTIN_NAME=	xf86-input-joystick
X11_DRV_NAME=		joystick_drv

.include "../../meta-pkgs/modular-xorg-drivers/builtin-common.mk"
