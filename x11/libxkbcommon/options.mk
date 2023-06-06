# $NetBSD: options.mk,v 1.4 2023/06/06 12:42:54 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libxkbcommon
PKG_SUPPORTED_OPTIONS=	doc

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
.else
MESON_ARGS+=		-Denable-docs=false
.endif
