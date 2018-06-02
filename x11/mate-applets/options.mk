# $NetBSD: options.mk,v 1.2 2018/06/02 16:40:20 jmcneill Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-applets
PKG_SUPPORTED_OPTIONS=	inet6 polkit upower
PKG_SUGGESTED_OPTIONS+=	inet6 polkit upower

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/polkit/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-polkit
.else
CONFIGURE_ARGS+=	--disable-polkit
.endif

.if !empty(PKG_OPTIONS:Mupower)
.include "../../sysutils/upower/buildlink3.mk"
CONFIGURE_ARGS+=	--with-upower
.else
CONFIGURE_ARGS+=	--without-upower
.endif
