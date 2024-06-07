# $NetBSD: options.mk,v 1.2 2024/06/07 04:16:15 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.icewm
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nls

.if !${PKG_OPTIONS:Mnls}
CONFIGURE_ARGS+=	--disable-nls
.else
PLIST.nls=		yes
.endif
