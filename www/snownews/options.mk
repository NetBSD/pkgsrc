# $NetBSD: options.mk,v 1.2 2008/02/21 22:47:28 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.snownews
PKG_SUPPORTED_OPTIONS=	wide-curses
PKG_LEGACY_OPTS+=	ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
USE_NCURSES=		yes	# WA_BOLD, WA_REVERSE, KEY_RESIZE

.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
CONFIGURE_ARGS+=	--charset=UTF-8
.else
.  include "../../devel/ncurses/buildlink3.mk"
.endif
