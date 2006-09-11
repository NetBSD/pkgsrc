# $NetBSD: Makefile,v 1.28.2.1 2006/09/11 10:39:17 ghen Exp $
#

DISTNAME=	awstats-6.6
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://awstats.sourceforge.net/files/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://awstats.sourceforge.net/
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

# awstats are in the habit of updating the tarball but not incrementing
# the version or name of the tarball. DIST_SUBDIR must be set like this
# to avoid checksum errors.
#
DIST_SUBDIR=	${PKGNAME}
NO_BUILD=	YES

USE_TOOLS+=	perl:run
REPLACE_PERL+=	tools/*.pl		\
		wwwroot/cgi-bin/*.pl

APACHE_USER?=	www
APACHE_GROUP?=	www

# OWN_DIRS=		${VARBASE}/awstats
OWN_DIRS_PERMS+= 	${VARBASE}/awstats ${APACHE_USER} ${APACHE_GROUP} 0700
PKG_SYSCONFSUBDIR=	awstats

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	tools/awstats_configure.pl \
			tools/awstats_buildstaticpages.pl \
			tools/awstats_updateall.pl \
			wwwroot/cgi-bin/awstats.model.conf \
			wwwroot/cgi-bin/awstats.pl
SUBST_SED.conf=		-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.conf+=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_SED.conf+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_SED.conf+=	-e "s|\"/etc/awstats|\"${PKG_SYSCONFDIR}|g"
SUBST_SED.conf+=	-e "s|\"/usr/local/awstats/wwwroot|\"${PREFIX}/awstats|g"
SUBST_SED.conf+=	-e "s|/var/log/httpd/mylog.log|${VARBASE}/log/httpd/access_log|g"
SUBST_MESSAGE.conf=	Fixing configuration files and scripts.

CONF_FILES+=	${PREFIX}/share/examples/awstats/awstats.conf \
		${PKG_SYSCONFDIR}/awstats.model.conf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/awstats
	${INSTALL_SCRIPT_DIR} ${PREFIX}/awstats/bin
	${INSTALL_SCRIPT_DIR} ${PREFIX}/awstats/cgi-bin
	${INSTALL_DATA_DIR} ${PREFIX}/awstats/cgi-bin/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/awstats
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
		&& ${PAX} -rwpppm ${d} ${PREFIX}/awstats/cgi-bin/
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/awstats/cgi-bin/${d}
	${FIND} ${PREFIX}/awstats/cgi-bin/${d} -type d -print	\
		| ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${PREFIX}/awstats/cgi-bin/${d} -type f -print	\
		| ${XARGS} ${CHMOD} ${SHAREMODE}
.endfor
.for d in classes css icon js
	cd ${WRKSRC}/wwwroot && ${PAX} -rwpppm ${d} ${PREFIX}/awstats/
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/awstats/${d}
	${FIND} ${PREFIX}/awstats/${d} -type d -print	\
		| ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${PREFIX}/awstats/${d} -type f -print	\
		| ${XARGS} ${CHMOD} ${SHAREMODE}
.endfor
	cd ${WRKSRC}/docs && ${PAX} -rwpppm . ${PREFIX}/share/doc/awstats/
	${CHOWN} -R ${DOCOWN}:${DOCGRP} ${PREFIX}/share/doc/awstats/
	${FIND} ${PREFIX}/share/doc/awstats/ -type d -print	\
		| ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${PREFIX}/share/doc/awstats/ -type f -print	\
		| ${XARGS} ${CHMOD} ${DOCMODE}

.include "../../mk/bsd.pkg.mk"
