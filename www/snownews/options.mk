# $NetBSD: options.mk,v 1.7 2017/01/04 16:08:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.snownews

PKG_OPTIONS_REQUIRED_GROUPS=	screen
PKG_OPTIONS_GROUP.screen=	curses wide-curses
PKG_OPTIONS_LEGACY_OPTS+=	ncurses:curses ncursesw:wide-curses

PKG_SUGGESTED_OPTIONS=	curses

.include "../../mk/bsd.options.mk"
.include "../../mk/curses.buildlink3.mk"
