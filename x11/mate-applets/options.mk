# $NetBSD: options.mk,v 1.1 2016/05/21 18:49:33 youri Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-applets
PKG_SUPPORTED_OPTIONS=	hal inet6 polkit upower
PKG_SUGGESTED_OPTIONS+=	hal inet6 polkit upower

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
CONFIGURE_ARGS+=	--with-hal
.else
CONFIGURE_ARGS+=	--without-hal
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
