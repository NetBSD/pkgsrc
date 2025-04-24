# $NetBSD: Makefile,v 1.22 2025/04/24 14:16:06 wiz Exp $

DISTNAME=	swiggle-0.4
PKGREVISION=	4
CATEGORIES=	www graphics
MASTER_SITES=	http://homepage.univie.ac.at/l.ertl/swiggle/files/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://homepage.univie.ac.at/l.ertl/swiggle/
COMMENT=	Lightweight image gallery generator

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swiggle ${DESTDIR}${PREFIX}/bin/

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
