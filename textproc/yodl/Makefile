# $NetBSD: Makefile,v 1.3 2001/03/29 22:37:45 jtb Exp $

DISTNAME=	yodl-1.31.18
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.lilypond.org/pub/yodl/development/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~jantien/yodl/
COMMENT=	high-level document preparation system

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

USE_LIBINTL=	YES

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} LDFLAGS="${LDFLAGS}"

.include "../../mk/bsd.pkg.mk"
