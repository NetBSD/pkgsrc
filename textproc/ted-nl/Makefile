# $NetBSD: Makefile,v 1.1.1.1 1999/09/19 11:30:46 dmcmahill Exp $

DISTNAME=	Ted_NL
PKGNAME=	ted-nl-2.5
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/

DEPENDS+=       ted-2.5:../../textproc/ted

USE_X11BASE=	YES

NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Dutch.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
