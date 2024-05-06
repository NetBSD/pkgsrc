# $NetBSD: options.mk,v 1.1 2024/05/06 10:24:34 cheusov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wdiff

PKG_SUPPORTED_OPTIONS=		nls
PKG_SUGGESTED_OPTIONS=		nls

PLIST_VARS+=	nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=	yes
.else
CONFIGURE_ARGS+= --disable-nls
.endif
