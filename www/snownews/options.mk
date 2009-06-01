# $NetBSD: options.mk,v 1.3 2009/06/01 11:56:43 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.snownews
PKG_SUPPORTED_OPTIONS=	wide-curses
PKG_OPTIONS_LEGACY_OPTS+=	ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

###
### Wide curses support; otherwise, default to using narrow curses.
###
INCOMPAT_CURSES=	NetBSD-[0-4].*-*	#WA_BOLD, WA_REVERSE, KEY_RESIZE

.if !empty(PKG_OPTIONS:Mwide-curses)
.  include "../../devel/ncursesw/buildlink3.mk"
.else
.  include "../../devel/ncurses/buildlink3.mk"
.endif
