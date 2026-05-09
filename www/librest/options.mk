# $NetBSD: options.mk,v 1.1 2026/05/09 13:03:11 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.librest
PKG_SUPPORTED_OPTIONS=	doc vapi
PKG_SUGGESTED_OPTIONS=	vapi

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc vapi

#
# Build documentation
#
.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Dgtk_doc=true
.  include "../../devel/py-gi-docgen/buildlink3.mk"
PLIST.doc=	yes
.else
MESON_ARGS+=	-Dgtk_doc=false
.endif

#
# Generate Vala API file
#
.if !empty(PKG_OPTIONS:Mvapi)
MESON_ARGS+=    -Dvapi=true
.  include "../../lang/vala/buildlink3.mk"
PLIST.vapi=              yes
.else
MESON_ARGS+=    -Dvapi=false
.endif
