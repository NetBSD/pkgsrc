# $NetBSD: Makefile,v 1.2 2003/01/14 09:26:34 jlam Exp $

DISTNAME=	fcpackage.2_1
PKGNAME=	Xrender-${XRENDER_VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://fontconfig.org/release/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	client library for the X Rendering Extension protocol

# This value is RENDER_MAJOR.RENDOR_MINOR from ${WRKSRC}/render.h.
XRENDER_VERSION=	0.7

USE_BUILDLINK2=		YES
USE_IMAKE=		YES
WRKSRC=			${WRKDIR}/${DISTNAME}/Xrender
EXTRACT_ELEMENTS=	${DISTNAME}/Xrender

.include "../../mk/bsd.prefs.mk"

_RENDER_H=		${X11BASE}/include/X11/extensions/render.h
_X11_TMPL=		${X11BASE}/lib/X11/config/X11.tmpl
.if exists(${_RENDER_H}) && exists(${_X11_TMPL})
_IS_BUILTIN_XRENDER!=	${GREP} -c BuildRenderLibrary ${_X11_TMPL} || ${TRUE}
.else
_IS_BUILTIN_XRENDER=	0
.endif

.if (${X11PREFIX} == ${X11BASE}) && (${_IS_BUILTIN_XRENDER} != "0")
PKG_SKIP_REASON= "${PKGNAME} is part of your X11 distribution"
.endif

.include "../../mk/bsd.pkg.mk"
