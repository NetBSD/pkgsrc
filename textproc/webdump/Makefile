# $NetBSD: Makefile,v 1.1 2026/10/24 12:13:40 leot Exp $

DISTNAME=	webdump-0.3
CATEGORIES=	textproc
MASTER_SITES=	http://codemadness.org/releases/webdump/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/webdump/file/README.html
COMMENT=	HTML to plain-text converter tool
LICENSE=	isc

USE_CC_FEATURES=	c99

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	CC=${CC:Q}

.include "../../mk/bsd.pkg.mk"
