# $NetBSD: options.mk,v 1.7 2009/08/06 11:03:49 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.epiphany
PKG_SUPPORTED_OPTIONS=		avahi
# browser crashes with enchant
PKG_SUGGESTED_OPTIONS=		avahi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--enable-zeroconf
.include "../../net/avahi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-zeroconf
.endif

.if !empty(PKG_OPTIONS:Menchant)
CONFIGURE_ARGS+=	--enable-spell-checker
.include "../../textproc/enchant/buildlink3.mk"
.endif
