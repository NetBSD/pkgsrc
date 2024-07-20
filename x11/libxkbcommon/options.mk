# $NetBSD: options.mk,v 1.5 2024/07/20 06:20:24 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libxkbcommon
PKG_SUPPORTED_OPTIONS=	doc

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
MESON_ARGS+=		-Denable-docs=true
.else
MESON_ARGS+=		-Denable-docs=false
.endif
