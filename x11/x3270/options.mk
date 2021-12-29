# $NetBSD: options.mk,v 1.4 2021/12/29 13:25:47 rhialto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x3270
PKG_SUPPORTED_OPTIONS=	curses x11 tcl gtk
PKG_SUGGESTED_OPTIONS+=	curses x11 gtk
PLIST_VARS=		curses x11 tcl gtk

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
USE_TOOLS+=		bash:run

.  if !empty(PKG_OPTIONS:Mgtk)
.    include "../../graphics/hicolor-icon-theme/buildlink3.mk"
ICON_THEMES=		yes
INSTALLATION_DIRS+=	${PREFIX}/share/applications
INSTALLATION_DIRS+=	${PREFIX}/share/icons/hicolor
PLIST.gtk=		yes
.  endif
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
