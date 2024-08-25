# $NetBSD: options.mk,v 1.2 2024/08/25 06:19:20 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lxqt-session
PKG_SUPPORTED_OPTIONS=		udev

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mudev)
.  include "../../sysutils/libudev/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_LIBUDEV=OFF
.endif
