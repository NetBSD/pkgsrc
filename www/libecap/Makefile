# $NetBSD: Makefile,v 1.6 2022/07/25 11:12:29 wiz Exp $

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

PKGCONFIG_OVERRIDE+=	libecap.pc.in

.include "../../mk/bsd.pkg.mk"
