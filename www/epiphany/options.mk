# $NetBSD: options.mk,v 1.8 2010/01/19 20:28:34 drochner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.epiphany
PKG_SUPPORTED_OPTIONS=		avahi
# browser crashes with enchant

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
