# $NetBSD: options.mk,v 1.1 2024/06/06 14:16:23 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.icewm3
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nls

.if !${PKG_OPTIONS:Mnls}
CONFIGURE_ARGS+=	--disable-nls
.else
PLIST.nls=		yes
.endif
