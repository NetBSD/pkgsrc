# $NetBSD: Makefile,v 1.4 2003/07/17 22:55:30 grant Exp $
#

DISTNAME=	calamaris-2.58
CATEGORIES=	www
MASTER_SITES=	http://cord.de/tools/squid/calamaris/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://cord.de/tools/squid/calamaris/
COMMENT=	squid logfile analyzer

USE_PERL5=	YES
REPLACE_PERL=	calamaris
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/calamaris ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/calamaris.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/calamaris
.for doc in CHANGES COPYRIGHT EXAMPLES README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/calamaris
.endfor

.include "../../mk/bsd.pkg.mk"
