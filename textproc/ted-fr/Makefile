# $NetBSD: Makefile,v 1.3 2000/03/02 16:40:35 dmcmahill Exp $

DISTNAME=	Ted_F
PKGNAME=	ted-fr-2.6
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/

DEPENDS+=       ted>=2.6:../../textproc/ted

USE_X11BASE=	YES

NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/French.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
