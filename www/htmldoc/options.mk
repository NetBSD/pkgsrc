# $NetBSD: options.mk,v 1.1 2008/04/22 16:24:31 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.htmldoc
PKG_SUPPORTED_OPTIONS=	htmldoc-gui

.include "../../mk/bsd.options.mk"

###
### X11 GUI support
###
.if !empty(PKG_OPTIONS:Mhtmldoc-gui)
.  include "../../x11/fltk/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gui --with-x
.else
CONFIGURE_ARGS+=	--without-gui --without-x
.endif
