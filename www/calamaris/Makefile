# $NetBSD: Makefile,v 1.12 2013/03/16 18:43:44 shattered Exp $
#

DISTNAME=	calamaris-2.59
CATEGORIES=	www
MASTER_SITES=	http://cord.de/tools/squid/calamaris/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://cord.de/tools/squid/calamaris/
COMMENT=	Squid logfile analyzer

USE_TOOLS+=	perl:run
REPLACE_PERL=	calamaris
NO_BUILD=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/calamaris

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/calamaris ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/calamaris.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for doc in CHANGES COPYRIGHT EXAMPLES README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/calamaris
.endfor

.include "../../mk/bsd.pkg.mk"
