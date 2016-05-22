# $NetBSD: options.mk,v 1.1 2016/05/22 13:03:21 youri Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-session-manager
PKG_SUPPORTED_OPTIONS=	inet6 upower
PKG_SUGGESTED_OPTIONS=	inet6 upower

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mupower)
.include "../../sysutils/upower/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-upower
.else
CONFIGURE_ARGS+=	--disable-upower
.endif
