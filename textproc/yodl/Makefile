# $NetBSD: Makefile,v 1.11 2003/07/17 22:54:57 grant Exp $

DISTNAME=	yodl-1.31.18
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.lilypond.org/pub/yodl/development/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xs4all.nl/~jantien/yodl/
COMMENT=	high-level document preparation system

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} LDFLAGS="${LDFLAGS}"

.include "../../lang/python/application.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
