# $NetBSD: options.mk,v 1.3 2019/11/06 12:51:55 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libxkbcommon
PKG_SUPPORTED_OPTIONS=	doc

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
.else
MESON_ARGS+=		-Denable-docs=false
.endif
