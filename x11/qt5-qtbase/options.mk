# $NetBSD: options.mk,v 1.13 2019/07/24 19:44:55 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt5
PKG_SUPPORTED_OPTIONS+=	cups eglfs gtk3

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/cups-base/buildlink3.mk"
CONFIGURE_ARGS+=	-cups
PLIST.cups=		yes
.else
CONFIGURE_ARGS+=	-no-cups
.endif

#.if !empty(PKG_OPTIONS:Megl)
#CONFIGURE_ARGS+=	-no-eglfs
#.else
#CONFIGURE_ARGS+=	-no-eglfs
#.endif

PLIST_VARS+=		gtk3
.if !empty(PKG_OPTIONS:Mgtk3)
.  include "../../x11/gtk3/buildlink3.mk"
CONFIGURE_ARGS+=	-gtk
PLIST.gtk3=		yes
.else
CONFIGURE_ARGS+=	-no-gtk
.endif
