# $NetBSD: options.mk,v 1.4 2024/11/05 17:20:04 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sord
PKG_SUPPORTED_OPTIONS=	doc tests

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocs=disabled
.endif

.if !empty(PKG_OPTIONS:Mtests)
MESON_ARGS+=	-Dtests=enabled
.else
MESON_ARGS+=	-Dtests=disabled
.endif
