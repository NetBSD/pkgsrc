# $NetBSD: Makefile,v 1.1.1.1 2003/01/14 09:16:36 jlam Exp $

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

.include "../../mk/bsd.pkg.mk"
