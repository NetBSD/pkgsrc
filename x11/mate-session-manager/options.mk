# $NetBSD: options.mk,v 1.2 2020/05/31 15:49:15 rillig Exp $

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
.endif
