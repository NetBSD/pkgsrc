# $NetBSD: Makefile,v 1.11 2005/01/18 13:37:26 minskim Exp $
#

DISTNAME=	awstats-6.3
CATEGORIES=	www
MASTER_SITES=	http://awstats.sourceforge.net/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://awstats.sourceforge.net/
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

USE_BUILDLINK3=	YES
NO_BUILD=	YES
USE_PERL5=	run

REPLACE_PERL=	tools/*.pl		\
		wwwroot/cgi-bin/*.pl

.include "../../lang/perl5/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/awstats
	${INSTALL_SCRIPT_DIR} ${PREFIX}/awstats/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/awstats
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/awstats
	${INSTALL_SCRIPT} ${WRKSRC}/tools/*.pl ${PREFIX}/awstats/bin
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/awstats.model.conf	\
		${PREFIX}/share/examples/awstats/awstats.conf
	${RM} ${WRKSRC}/wwwroot/cgi-bin/awstats.model.conf
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/example/example.pm \
		${PREFIX}/share/examples/awstats/example.pm
	${RM} -fr ${WRKSRC}/wwwroot/cgi-bin/plugins/example
	cd ${WRKSRC}/wwwroot && ${PAX} -rwpppm . ${PREFIX}/awstats/
	cd ${WRKSRC}/docs && ${PAX} -rwpppm . ${PREFIX}/share/doc/html/awstats/

.include "../../mk/bsd.pkg.mk"
