# $NetBSD: Makefile,v 1.4 2017/05/03 08:38:45 jperkin Exp $

DISTNAME=	libecap-1.0.1
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.measurement-factory.com/tmp/ecap/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.e-cap.org/
COMMENT=	C++ implementation of eCAP API
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libecap.pc.in

.include "../../mk/bsd.pkg.mk"
