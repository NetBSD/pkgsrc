# $NetBSD: Makefile,v 1.6 2003/07/30 15:15:43 grant Exp $

DISTNAME=	fcpackage.2_1
PKGNAME=	Xrender-${XRENDER_VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}/Xrender
CATEGORIES=	x11
MASTER_SITES=	http://fontconfig.org/release/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Client library for the X Rendering Extension protocol

# This value is RENDER_MAJOR.RENDOR_MINOR from ${WRKSRC}/render.h.
XRENDER_VERSION=	0.7

USE_BUILDLINK2=		YES
USE_IMAKE=		YES
EXTRACT_ELEMENTS=	${DISTNAME}/Xrender

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=		NOT_SUNOS="@comment "
.else
PLIST_SUBST+=		NOT_SUNOS=""
.endif

PLIST_SUBST+=
_RENDER_H=		${X11BASE}/include/X11/extensions/render.h
_X11_TMPL=		${X11BASE}/lib/X11/config/X11.tmpl
.if exists(${_RENDER_H}) && exists(${_X11_TMPL})
_IS_BUILTIN_XRENDER!=	${GREP} -c BuildRenderLibrary ${_X11_TMPL} || ${TRUE}
.else
_IS_BUILTIN_XRENDER=	0
.endif

.if ${X11PREFIX} == ${X11BASE} && ${_IS_BUILTIN_XRENDER} != "0"
PKG_SKIP_REASON= "${PKGNAME} is part of your X11 distribution"
.endif

.include "../../mk/bsd.pkg.mk"
