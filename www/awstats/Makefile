# $NetBSD: Makefile,v 1.13 2005/01/26 15:55:41 minskim Exp $
#

DISTNAME=	awstats-6.3
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://awstats.sourceforge.net/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://awstats.sourceforge.net/
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

DIST_SUBDIR=	${PKGNAME}
USE_BUILDLINK3=	YES
NO_BUILD=	YES
USE_PERL5=	run

REPLACE_PERL=	tools/*.pl		\
		wwwroot/cgi-bin/*.pl

.include "../../lang/perl5/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/awstats
	${INSTALL_SCRIPT_DIR} ${PREFIX}/awstats/bin
	${INSTALL_SCRIPT_DIR} ${PREFIX}/awstats/cgi-bin
	${INSTALL_DATA_DIR} ${PREFIX}/awstats/cgi-bin/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/awstats
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/awstats
	${INSTALL_SCRIPT} ${WRKSRC}/tools/*.pl ${PREFIX}/awstats/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/*.pl		\
		${PREFIX}/awstats/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/awstats.model.conf	\
		${PREFIX}/share/examples/awstats/awstats.conf
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/example/example.pm \
		${PREFIX}/share/examples/awstats/example.pm
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/*.pm		\
		${PREFIX}/awstats/cgi-bin/plugins
.for d in lang lib
	cd ${WRKSRC}/wwwroot/cgi-bin					\
		&& ${PAX} -rwpppm $d ${PREFIX}/awstats/cgi-bin/
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/awstats/cgi-bin/$d
	${FIND} ${PREFIX}/awstats/cgi-bin/$d -type d -print	\
		| ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${PREFIX}/awstats/cgi-bin/$d -type f -print	\
		| ${XARGS} ${CHMOD} ${SHAREMODE}
.endfor
.for d in classes css icon js
	cd ${WRKSRC}/wwwroot && ${PAX} -rwpppm $d ${PREFIX}/awstats/
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/awstats/$d
	${FIND} ${PREFIX}/awstats/$d -type d -print	\
		| ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${PREFIX}/awstats/$d -type f -print	\
		| ${XARGS} ${CHMOD} ${SHAREMODE}
.endfor
	cd ${WRKSRC}/docs && ${PAX} -rwpppm . ${PREFIX}/share/doc/html/awstats/
	${CHOWN} -R ${DOCOWN}:${DOCGRP} ${PREFIX}/share/doc/html/awstats/
	${FIND} ${PREFIX}/share/doc/html/awstats/ -type d -print	\
		| ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${PREFIX}/share/doc/html/awstats/ -type f -print	\
		| ${XARGS} ${CHMOD} ${DOCMODE}

.include "../../mk/bsd.pkg.mk"
