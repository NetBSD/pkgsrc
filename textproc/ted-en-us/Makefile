# $NetBSD: Makefile,v 1.4 2000/04/22 11:08:45 dmcmahill Exp $

DISTNAME=	ted-2.8.src
PKGNAME=	ted-en-us-2.8
WRKSRC=		${WRKDIR}/Ted-2.8
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/

DEPENDS+=       ted>=2.6:../../textproc/ted

USE_X11BASE=	YES
NO_BUILD=	YES

post-extract:
	@cd ${WRKSRC} ; ${GTAR} xf tedPackage/TedBindist.tar

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/US_English.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
