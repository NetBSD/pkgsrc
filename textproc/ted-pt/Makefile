# $NetBSD: Makefile,v 1.4 2001/02/17 17:37:52 wiz Exp $

DISTNAME=	Ted_P
PKGNAME=	ted-pt-2.6
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Portuguese spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../textproc/ted

USE_X11BASE=	YES

NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Portuguese.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
