# $NetBSD: Makefile,v 1.5 2020/01/26 17:32:21 rillig Exp $

DISTNAME=	libecap-1.0.1
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.measurement-factory.com/tmp/ecap/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.e-cap.org/
COMMENT=	C++ implementation of eCAP API
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libecap.pc.in

.include "../../mk/bsd.pkg.mk"
