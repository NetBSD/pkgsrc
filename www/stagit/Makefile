# $NetBSD: Makefile,v 1.11 2022/09/15 19:22:11 leot Exp $

DISTNAME=	stagit-1.2
CATEGORIES=	www
MASTER_SITES=	https://codemadness.org/releases/stagit/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
