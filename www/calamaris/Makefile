# $NetBSD: Makefile,v 1.1.1.1 2000/10/16 07:10:11 rh Exp $
#

DISTNAME=	calamaris-2.39
CATEGORIES=	www
MASTER_SITES=	http://cord.de/tools/squid/calamaris/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://cord.de/tools/squid/calamaris/

USE_PERL5=	YES
NO_BUILD=	YES

do-configure:
	cd ${WRKSRC} && ${CP} calamaris calamaris.tmp &&	\
	${SED} -e 's:/usr/bin/perl:${PREFIX}/bin/perl:g'	\
		< calamaris.tmp > calamaris

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/calamaris ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/calamaris.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/calamaris
.for doc in CHANGES COPYRIGHT EXAMPLES README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/calamaris
.endfor

.include "../../mk/bsd.pkg.mk"
