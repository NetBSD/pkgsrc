# $NetBSD: Makefile,v 1.14 2004/02/16 02:36:44 minskim Exp $

DISTNAME=	yodl-1.31.18
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.lilypond.org/pub/yodl/development/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xs4all.nl/~jantien/yodl/
COMMENT=	High-level document preparation system

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
MAKEFILE=	GNUmakefile

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} LDFLAGS="${LDFLAGS}"

.include "../../lang/python/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
