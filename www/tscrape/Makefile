# $NetBSD: Makefile,v 1.3 2019/08/18 16:00:12 leot Exp $

DISTNAME=	tscrape-0.3
CATEGORIES=	www
MASTER_SITES=	http://codemadness.org/releases/tscrape/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://codemadness.org/git/tscrape/file/README.html
COMMENT=	Twitter scraper
LICENSE=	isc

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		CC=${CC:Q}

.include "../../mk/bsd.pkg.mk"
