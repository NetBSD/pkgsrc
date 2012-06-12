# $NetBSD: options.mk,v 1.3 2012/06/12 15:46:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-applets
PKG_SUPPORTED_OPTIONS=	hal inet6
PKG_SUGGESTED_OPTIONS+=	hal inet6

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
