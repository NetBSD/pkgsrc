# $NetBSD: options.mk,v 1.1 2007/09/13 23:24:04 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.snownews
PKG_OPTIONS_REQUIRED_GROUPS=	display
PKG_OPTIONS_GROUP.display=	ncurses ncursesw
PKG_SUGGESTED_OPTIONS=		ncurses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mncurses)
.  include "../../devel/ncurses/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mncursesw)
.  include "../../devel/ncursesw/buildlink3.mk"
CONFIGURE_ARGS+=	--charset=UTF-8
.endif
