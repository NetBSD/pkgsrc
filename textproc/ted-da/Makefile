# $NetBSD: Makefile,v 1.4 2001/02/17 17:37:46 wiz Exp $

DISTNAME=	Ted_DK
PKGNAME=	ted-da-2.6
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Danish spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../textproc/ted

USE_X11BASE=	YES

NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Danish.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
