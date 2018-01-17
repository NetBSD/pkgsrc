# $NetBSD: options.mk,v 1.10 2018/01/17 19:30:46 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt5
PKG_SUPPORTED_OPTIONS=	cups eglfs gtk3
#PKG_SUGGESTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups gtk3

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

.if !empty(PKG_OPTIONS:Mgtk3)
.  include "../../x11/gtk3/buildlink3.mk"
CONFIGURE_ARGS+=	-gtk
PLIST.gtk2=		yes
.else
CONFIGURE_ARGS+=	-no-gtk
.endif
