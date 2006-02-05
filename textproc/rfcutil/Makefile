# $NetBSD: Makefile,v 1.15 2006/02/05 23:11:07 joerg Exp $
#

DISTNAME=	rfc-3.2
PKGNAME=	rfcutil-3.2
PKGREVISION=	3
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
USE_TOOLS+=	perl:run
REPLACE_PERL=	rfc

INSTALLATION_DIRS=	bin

do-extract:
	${SED} \
		-e 's,/usr/local,${PREFIX},' \
		<${DISTDIR}/${DISTNAME} >${WRKSRC}/rfc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rfc ${PREFIX}/bin/rfc

.include "../../mk/bsd.pkg.mk"
