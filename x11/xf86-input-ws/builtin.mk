# $NetBSD: builtin.mk,v 1.1 2021/12/03 12:47:54 nia Exp $

X11_BUILTIN_NAME=	xf86-input-ws
X11_DRV_NAME=		ws_drv

.include "../../meta-pkgs/modular-xorg-drivers/builtin-common.mk"
