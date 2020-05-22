# $NetBSD: Makefile,v 1.7 2020/05/22 10:56:45 adam Exp $

DISTNAME=	kore-3.3.1
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	https://kore.io/releases/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://kore.io/
COMMENT=	Web application framework for writing scalable web APIs in C
LICENSE=	isc

USE_LANGUAGES=	c99
USE_TOOLS+=	gmake

MAKE_FLAGS+=	MAN_DIR="${PREFIX}/${PKGMANDIR}"
MAKE_FLAGS+=	TASKS=1

pre-build:
	${MKDIR} ${WRKSRC}/obj

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
