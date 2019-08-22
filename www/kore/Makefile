# $NetBSD: Makefile,v 1.1 2019/08/22 13:30:31 fcambus Exp $

DISTNAME=	kore-3.3.1
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

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
