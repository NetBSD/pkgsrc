# $NetBSD: Makefile,v 1.12 2021/04/21 13:25:29 adam Exp $

DISTNAME=	kore-4.1.0
REVISION=	1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://kore.io/releases/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://kore.io/
COMMENT=	Web application framework for writing scalable web APIs in C
LICENSE=	isc

USE_LANGUAGES=	c99 c++
USE_TOOLS+=	gmake

MAKE_FLAGS+=	MAN_DIR="${PREFIX}/${PKGMANDIR}"
MAKE_FLAGS+=	TASKS=1

pre-build:
	${MKDIR} ${WRKSRC}/obj

post-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} tools-build

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kore-serve ${DESTDIR}${PREFIX}/bin

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
