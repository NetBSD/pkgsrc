# $NetBSD: Makefile,v 1.10 2021/01/23 15:35:43 fcambus Exp $

DISTNAME=	kore-4.1.0
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
