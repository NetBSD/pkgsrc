# $NetBSD: Makefile,v 1.34 2008/01/03 12:37:06 adrianp Exp $
#

DISTNAME=	awstats-6.6
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://awstats.sourceforge.net/files/
# awstats are in the habit of updating the tarball but not incrementing
# the version or name of the tarball. DIST_SUBDIR must be set like this
# to avoid checksum errors.
#
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://awstats.sourceforge.net/
COMMENT=	Free real-time logfile analyzer to get advanced web statistics

NO_BUILD=	YES

USE_TOOLS+=	perl:run
REPLACE_PERL+=	tools/*.pl		\
		wwwroot/cgi-bin/*.pl

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS+=		VARBASE

# OWN_DIRS=		${VARBASE}/awstats
OWN_DIRS_PERMS+=	${VARBASE}/awstats ${APACHE_USER} ${APACHE_GROUP} 0700
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
		&& pax -rwpppm ${d} ${PREFIX}/awstats/cgi-bin/
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/awstats/cgi-bin/${d}
	find ${PREFIX}/awstats/cgi-bin/${d} -type d -print	\
		| xargs chmod ${PKGDIRMODE}
	find ${PREFIX}/awstats/cgi-bin/${d} -type f -print	\
		| xargs chmod ${SHAREMODE}
.endfor
.for d in classes css icon js
	cd ${WRKSRC}/wwwroot && pax -rwpppm ${d} ${PREFIX}/awstats/
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/awstats/${d}
	find ${PREFIX}/awstats/${d} -type d -print	\
		| xargs chmod ${PKGDIRMODE}
	find ${PREFIX}/awstats/${d} -type f -print	\
		| xargs chmod ${SHAREMODE}
.endfor
	cd ${WRKSRC}/docs && pax -rwpppm . ${PREFIX}/share/doc/awstats/
	chown -R ${DOCOWN}:${DOCGRP} ${PREFIX}/share/doc/awstats/
	find ${PREFIX}/share/doc/awstats/ -type d -print	\
		| xargs chmod ${PKGDIRMODE}
	find ${PREFIX}/share/doc/awstats/ -type f -print	\
		| xargs chmod ${DOCMODE}

.include "../../mk/bsd.pkg.mk"
