# $NetBSD: Makefile,v 1.12 2005/06/17 03:50:37 jlam Exp $
#

DISTNAME=	rfc-3.2
PKGNAME=	rfcutil-3.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.dewn.com/rfc/
EXTRACT_SUFX=	#

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.dewn.com/rfc/
COMMENT=	Search for RFCs and do ports, services & protocol lookups

DEPENDS+=	w3m-[0-9]*:../../www/w3m

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	#

NO_BUILD=	YES
USE_PERL5=	YES
REPLACE_PERL=	rfc

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/rfc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rfc ${PREFIX}/bin/rfc

.include "../../mk/bsd.pkg.mk"
