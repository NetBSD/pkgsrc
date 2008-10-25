# $NetBSD: options.mk,v 1.2 2008/10/25 11:15:16 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.epiphany
PKG_SUPPORTED_OPTIONS=	enchant # avahi
PKG_SUGGESTED_OPTIONS=	enchant

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menchant)
CONFIGURE_ARGS+=	--enable-spell-checker
.include "../../textproc/enchant/buildlink3.mk"
.endif
