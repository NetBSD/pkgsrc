# $NetBSD: options.mk,v 1.1 2020/09/30 03:07:25 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.blackbox70
PKG_SUPPORTED_OPTIONS=	nls xft2
PKG_SUGGESTED_OPTIONS=	nls xft2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	nls

# The nls option also controls whether the fr/ja/nl/sl man pages are
# installed.
.if !empty(PKG_OPTIONS:Mnls)
BROKEN_GETTEXT_DETECTION=	yes
CONFIGURE_ARGS+=	--enable-nls
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=	yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--enable-xft
.include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xft
.endif
