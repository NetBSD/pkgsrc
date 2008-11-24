# $NetBSD: options.mk,v 1.2 2008/11/24 15:02:18 jmcneill Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-applets
PKG_SUPPORTED_OPTIONS=	inet6 hal
PKG_SUGGESTED_OPTIONS+=	hal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../security/policykit-gnome/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-polkit
CONFIGURE_ARGS+=	--without-hal
.endif
