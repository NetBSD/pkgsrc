# $NetBSD: Makefile,v 1.1.1.1 1999/09/19 11:27:19 dmcmahill Exp $

DISTNAME=	ted-2.5.src
PKGNAME=	ted-en-us-2.5
WRKSRC=		${WRKDIR}/Ted-2.5
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/

DEPENDS+=       ted-2.5:../../textproc/ted

USE_X11BASE=	YES
NO_BUILD=	YES

post-extract:
	@cd ${WRKSRC} ; tar xf tedPackage/TedBindist.tar

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/US_English.ind ${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
