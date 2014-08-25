# $NetBSD: options.mk,v 1.1 2014/08/25 13:58:21 szptvlfn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmonad-contrib
PKG_SUPPORTED_OPTIONS= xft2
PKG_SUGGESTED_OPTIONS= xft2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxft2)
.include "../../x11/hs-X11-xft/buildlink3.mk"
.else
SUBST_CLASSES+=	1
SUBST_STAGE.1=	pre-patch
SUBST_FILES.1=	xmonad-contrib.cabal
SUBST_SED.1=	-e "s|render text|render text+  default: False|"

SUBST_CLASSES+=	2
SUBST_STAGE.2=	post-patch
SUBST_FILES.2=	xmonad-contrib.cabal
SUBST_FILTER_CMD.2=	${TR} '+' \\n
.endif
