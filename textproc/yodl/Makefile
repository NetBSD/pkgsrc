# $NetBSD: Makefile,v 1.6 2001/09/27 23:18:48 jlam Exp $

DISTNAME=	yodl-1.31.18
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.lilypond.org/pub/yodl/development/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~jantien/yodl/
COMMENT=	high-level document preparation system

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

USE_LIBINTL=	YES

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} LDFLAGS="${LDFLAGS}"

.include "../../mk/bsd.pkg.mk"
