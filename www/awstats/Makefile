# $NetBSD: Makefile,v 1.1.1.1 2003/07/31 03:18:20 jschauma Exp $
#

DISTNAME=	awstats-5.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=awstats/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://awstats.sourceforge.net/
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

USE_BUILDLINK2=	YES
NO_BUILD=	YES
USE_PERL5=	run

REPLACE_PERL =						\
	${WRKSRC}/tools/awstats_buildstaticpages.pl	\
	${WRKSRC}/tools/awstats_updateall.pl		\
	${WRKSRC}/tools/logresolvemerge.pl		\
	${WRKSRC}/wwwroot/cgi-bin/awstats.pl

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
	cd ${WRKSRC}/wwwroot && ${PAX} -rwp e . ${PREFIX}/awstats/
	cd ${WRKSRC}/docs && ${PAX} -rwp e . ${PREFIX}/share/doc/html/awstats/

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
