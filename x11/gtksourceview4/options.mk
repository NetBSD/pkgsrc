# $NetBSD: options.mk,v 1.2 2020/10/01 13:40:33 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtksourceview4
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	introspection
PLIST_VARS+=		introspection

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.42.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
MESON_ARGS+=	-Dgir=false
.endif
