# $NetBSD: Makefile,v 1.9 2020/10/09 15:34:22 leot Exp $

DISTNAME=	tscrape-0.6
CATEGORIES=	www
MASTER_SITES=	http://codemadness.org/releases/tscrape/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/tscrape/file/README.html
COMMENT=	Twitter scraper
LICENSE=	isc

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		CC=${CC:Q}

.include "../../mk/bsd.pkg.mk"
