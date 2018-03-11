# $NetBSD: options.mk,v 1.1 2018/03/11 20:23:23 wiz Exp $

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
CONFIGURE_ARGS+=	--enable-introspection=no
.endif
