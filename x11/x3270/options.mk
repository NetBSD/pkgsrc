# $NetBSD: options.mk,v 1.3 2021/06/26 13:51:20 rhialto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x3270
PKG_SUPPORTED_OPTIONS=	curses x11 tcl
PKG_SUGGESTED_OPTIONS+=	curses x11
PLIST_VARS=		curses x11 tcl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurses)
.include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-c3270
PLIST.curses=		yes
.else
CONFIGURE_ARGS+=	--disable-c3270
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x3270
CONFIGURE_ARGS+=	--enable-x3270if
PLIST.x11=		yes
REPLACE_BASH+=		x3270/x3270a.in
USE_TOOLS+=	bash:run
.else
CONFIGURE_ARGS+=	--disable-x3270
CONFIGURE_ARGS+=	--disable-x3270if
.endif

.if !empty(PKG_OPTIONS:Mtcl)
.include "../../lang/tcl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tcl3270
PLIST.tcl=		yes
.else
CONFIGURE_ARGS+=	--disable-tcl3270
.endif
