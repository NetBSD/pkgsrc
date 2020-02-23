# $NetBSD: Makefile,v 1.2 2020/02/23 21:38:49 fcambus Exp $

DISTNAME=	stagit-0.9.3
CATEGORIES=	www
MASTER_SITES=	https://codemadness.org/releases/stagit/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/stagit/file/README.html
COMMENT=	Static git page generator
LICENSE=	mit

USE_LANGUAGES=	c99

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	LIBGIT_INC=
MAKE_FLAGS+=	LIBGIT_LIB=-lgit2

.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
