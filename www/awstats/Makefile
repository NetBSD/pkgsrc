# $NetBSD: Makefile,v 1.5 2004/01/12 23:58:43 xtraeme Exp $
#

DISTNAME=	awstats-5.9
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=awstats/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://awstats.sourceforge.net/
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

USE_BUILDLINK2=	YES
NO_BUILD=	YES
USE_PERL5=	run

REPLACE_PERL=	tools/*.pl		\
		wwwroot/cgi-bin/*.pl

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/awstats
	${INSTALL_DATA_DIR} ${PREFIX}/awstats/bin
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

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
