# $NetBSD: options.mk,v 1.8 2019/09/16 11:42:50 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.snownews

PKG_OPTIONS_REQUIRED_GROUPS=	screen
PKG_OPTIONS_GROUP.screen=	curses wide-curses
PKG_OPTIONS_LEGACY_OPTS+=	ncurses:curses ncursesw:wide-curses

PKG_SUGGESTED_OPTIONS=	wide-curses

.include "../../mk/bsd.options.mk"
.include "../../mk/curses.buildlink3.mk"
