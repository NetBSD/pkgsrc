# $NetBSD: Makefile,v 1.27 2024/05/29 16:34:51 adam Exp $

DISTNAME=	kore-4.2.3
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	https://kore.io/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kore.io/
COMMENT=	Web application framework for writing scalable web APIs in C
LICENSE=	isc

USE_LANGUAGES=	c99 c++
USE_TOOLS+=	gmake

MAKE_FLAGS+=	OPENSSL_PATH=${SSLBASE}
MAKE_FLAGS+=	MAN_DIR="${PREFIX}/${PKGMANDIR}"
MAKE_FLAGS+=	TASKS=1

pre-build:
	${MKDIR} ${WRKSRC}/obj

post-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} tools-build

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kore-serve ${DESTDIR}${PREFIX}/bin

.include "options.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
