# $NetBSD: Makefile,v 1.3 2016/06/23 15:05:38 prlw1 Exp $

DISTNAME=	libecap-1.0.1
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.measurement-factory.com/tmp/ecap/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.e-cap.org/
COMMENT=	C++ implementation of eCAP API
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CXXFLAGS+=	-std=c++11

PKGCONFIG_OVERRIDE+=	libecap.pc.in

.include "../../mk/bsd.pkg.mk"
