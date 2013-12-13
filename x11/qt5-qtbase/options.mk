# $NetBSD: options.mk,v 1.1 2013/12/13 14:38:35 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt5
PKG_SUPPORTED_OPTIONS=	cups debug gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	-cups
.else
CONFIGURE_ARGS+=	-no-cups
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.  include "../../devel/glib2/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	-gtkstyle
.else
CONFIGURE_ARGS+=	-no-gtkstyle
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CC+=			-ggdb
CXX+=			-ggdb
CONFIGURE_ARGS+=	-debug
INSTALL_UNSTRIPPED=	yes
.else
CONFIGURE_ARGS+=	-no-debug
.endif
