# $NetBSD: options.mk,v 1.1.1.1 2009/11/02 04:15:51 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.echinus
PKG_SUPPORTED_OPTIONS=	xrandr
PKG_SUGGESTED_OPTIONS=	xrandr

.include "../../mk/bsd.options.mk"

#
# Xinerama support
#
# If we don't want the Xinerama support we delete XINERAMALIBS and
# XINERAMAFLAGS lines, otherwise the Xinerama support is the default.
#
.if !empty(PKG_OPTIONS:Mxrandr)
.  include "../../x11/libXrandr/buildlink3.mk"
.else
SUBST_CLASSES+=		options
SUBST_STAGE.options=	pre-build
SUBST_MESSAGE.options=	Toggle Xrandr support
SUBST_FILES.options=	config.mk
SUBST_SED.options+=	-e '/XRANDR/ d;/Xrandr/ d'
.  include "../../x11/libX11/buildlink3.mk"
.endif
