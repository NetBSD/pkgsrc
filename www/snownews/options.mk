# $NetBSD: options.mk,v 1.5 2014/09/18 14:54:55 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.snownews

PKG_OPTIONS_REQUIRED_GROUPS=	screen
PKG_OPTIONS_GROUP.screen=	ncurses ncursesw

PKG_SUGGESTED_OPTIONS=	ncurses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mncurses)
USE_NCURSES=		YES
.  include "../../devel/ncurses/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mncursesw)
LIBS+=			-lncursesw
SUBST_CLASSES+=		configure
SUBST_MESSAGE.configure= Fixing LDFLAGS for ncursesw
SUBST_STAGE.configure=	pre-configure
SUBST_FILES.configure=	configure
SUBST_SED.configure=	-e 's,-lncurses,-lncursesw,'
.  include "../../devel/ncursesw/buildlink3.mk"
.endif
