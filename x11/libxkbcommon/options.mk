# $NetBSD: options.mk,v 1.6 2025/06/19 07:40:50 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libxkbcommon
PKG_SUPPORTED_OPTIONS=	doc

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen>=1.14:../../devel/doxygen
PLIST.doc=		yes
MESON_ARGS+=		-Denable-docs=true
.else
MESON_ARGS+=		-Denable-docs=false
.endif
