# $NetBSD: Makefile,v 1.5 2001/04/14 21:43:59 jtb Exp $

DISTNAME=	yodl-1.31.18
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.lilypond.org/pub/yodl/development/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~jantien/yodl/
COMMENT=	high-level document preparation system

BUILD_DEPENDS+=	bison-*:../../devel/bison

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

USE_LIBINTL=	YES

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} LDFLAGS="${LDFLAGS}"

.include "../../mk/bsd.pkg.mk"
