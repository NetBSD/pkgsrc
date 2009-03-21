# $NetBSD: Makefile,v 1.7 2009/03/21 20:01:11 adrianp Exp $

DISTNAME=	whisker-2.1
PKGREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.wiretrip.net/rfp/bins/whisker/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.wiretrip.net/rfp/
COMMENT=	URL scanner used to search for known vulnerable CGIs on websites

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Net-SSLeay>=1.20:../../security/p5-Net-SSLeay

USE_TOOLS+=	perl:run
REPLACE_PERL=	whisker.pl

INSTALLATION_DIRS=	bin share/doc/whisker share/whisker

do-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/whisker.pl > ${WRKSRC}/whisker

do-install:
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DESTDIR}${PREFIX}/share/doc/whisker
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${PREFIX}/share/doc/whisker
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/whisker
	${INSTALL_SCRIPT} ${WRKSRC}/whisker ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/LW.pm ${DESTDIR}${PREFIX}/share/whisker
	${INSTALL_DATA} ${WRKSRC}/html.plugin ${DESTDIR}${PREFIX}/share/whisker
	${INSTALL_DATA} ${WRKSRC}/main.test ${DESTDIR}${PREFIX}/share/whisker
	${INSTALL_DATA} ${WRKSRC}/newbie.help ${DESTDIR}${PREFIX}/share/whisker

.include "../../mk/bsd.pkg.mk"
