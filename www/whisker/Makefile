# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 12:29:40 hubertf Exp $

DISTNAME=	whisker-2.1
CATEGORIES=	security www
MASTER_SITES=	http://www.wiretrip.net/rfp/bins/whisker/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.wiretrip.net/rfp/
COMMENT=	URL scanner used to search for known vulnerable CGIs on websites

DEPENDS+=	p5-Net-SSLeay>=1.20:../../security/p5-Net-SSLeay

USE_PERL5=      YES
REPLACE_PERL=	whisker.pl

do-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/whisker.pl > ${WRKSRC}/whisker

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/whisker
	${INSTALL_DATA_DIR} ${PREFIX}/share/whisker
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/whisker
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/whisker
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/whisker
	${INSTALL_SCRIPT} ${WRKSRC}/whisker ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/LW.pm ${PREFIX}/share/whisker
	${INSTALL_DATA} ${WRKSRC}/html.plugin ${PREFIX}/share/whisker
	${INSTALL_DATA} ${WRKSRC}/main.test ${PREFIX}/share/whisker
	${INSTALL_DATA} ${WRKSRC}/newbie.help ${PREFIX}/share/whisker

.include "../../mk/bsd.pkg.mk"
