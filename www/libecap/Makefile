# $NetBSD: Makefile,v 1.7 2025/07/23 16:16:12 prlw1 Exp $

DISTNAME=	libecap-1.0.1
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://www.e-cap.org/archive/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.e-cap.org/
COMMENT=	C++ implementation of eCAP API
LICENSE=	2-clause-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11

PKGCONFIG_OVERRIDE+=	libecap.pc.in

.include "../../mk/bsd.pkg.mk"
