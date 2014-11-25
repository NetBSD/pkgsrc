# $NetBSD: options.mk,v 1.6 2014/11/25 09:59:11 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.eekboard
PKG_SUPPORTED_OPTIONS=	introspection vala xtest libcanberra
PKG_SUGGESTED_OPTIONS=	introspection vala xtest

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection vala

.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif

.if !empty(PKG_OPTIONS:Mvala)
PLIST.vala=	yes
.include "../../lang/vala/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vala=yes
.else
CONFIGURE_ARGS+=	--enable-vala=no
.endif

.if !empty(PKG_OPTIONS:Mxtest)
.include "../../x11/libXtst/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xtest=yes
.else
CONFIGURE_ARGS+=	--enable-xtest=no
.endif

.if !empty(PKG_OPTIONS:Mlibcanberra)
.include "../../audio/libcanberra/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libcanberra=yes
.else
CONFIGURE_ARGS+=	--enable-libcanberra=no
.endif
