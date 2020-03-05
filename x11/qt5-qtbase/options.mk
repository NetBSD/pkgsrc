# $NetBSD: options.mk,v 1.14 2020/03/05 11:56:19 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt5
PKG_SUPPORTED_OPTIONS+=	cups gtk3

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/cups-base/buildlink3.mk"
CONFIGURE_ARGS+=	-cups
PLIST.cups=		yes
.else
CONFIGURE_ARGS+=	-no-cups
.endif

PLIST_VARS+=		gtk3
.if !empty(PKG_OPTIONS:Mgtk3)
.  include "../../x11/gtk3/buildlink3.mk"
CONFIGURE_ARGS+=	-gtk
PLIST.gtk3=		yes
.else
CONFIGURE_ARGS+=	-no-gtk
.endif
