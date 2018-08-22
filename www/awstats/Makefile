# $NetBSD: Makefile,v 1.61 2018/08/22 09:47:23 wiz Exp $

DISTNAME=	awstats-7.6
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.awstats.org/files/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.awstats.org/
COMMENT=	Free real-time logfile analyzer to get advanced web statistics
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-Geo-IPfree-[0-9]*:../../net/p5-Geo-IPfree
DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	p5-Net-XWhois-[0-9]*:../../net/p5-Net-XWhois
DEPENDS+=	p5-Time-Local-[0-9]*:../../time/p5-Time-Local

NO_BUILD=		yes
USE_TOOLS+=		perl:run pax
REPLACE_PERL+=		tools/*.pl
REPLACE_PERL+=		wwwroot/cgi-bin/*.pl
REPLACE_PERL+=		wwwroot/cgi-bin/plugins/*.pm
REPLACE_PERL+=		wwwroot/classes/src/*.pl

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS=		APACHE_USER
BUILD_DEFS+=		VARBASE

#OWN_DIRS=		${VARBASE}/awstats
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

INSTALLATION_DIRS+=	awstats
INSTALLATION_DIRS+=	awstats/bin
INSTALLATION_DIRS+=	awstats/cgi-bin
INSTALLATION_DIRS+=	awstats/cgi-bin/plugins
INSTALLATION_DIRS+=	share/doc/awstats
INSTALLATION_DIRS+=	share/examples/awstats

post-extract:
	find ${WRKSRC} -name .cvsignore -exec rm {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/*.pl ${DESTDIR}${PREFIX}/awstats/bin
	${FIND} ${WRKSRC}/wwwroot/cgi-bin -name \*.orig -exec ${RM} {} \;
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/*.pl		\
	    ${DESTDIR}${PREFIX}/awstats/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/awstats.model.conf	\
	    ${DESTDIR}${PREFIX}/share/examples/awstats/awstats.conf
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/example/example.pm \
	    ${DESTDIR}${PREFIX}/share/examples/awstats/example.pm
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/plugins/*.pm		\
	    ${DESTDIR}${PREFIX}/awstats/cgi-bin/plugins
.for d in lang lib
	cd ${WRKSRC}/wwwroot/cgi-bin					\
		&& pax -rwpppm ${d} ${DESTDIR}${PREFIX}/awstats/cgi-bin/
	chown -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/awstats/cgi-bin/${d}
	find ${DESTDIR}${PREFIX}/awstats/cgi-bin/${d} -type d -print	\
		| xargs chmod ${PKGDIRMODE}
	find ${DESTDIR}${PREFIX}/awstats/cgi-bin/${d} -type f -print	\
		| xargs chmod ${SHAREMODE}
.endfor
.for d in classes css icon js
	cd ${WRKSRC}/wwwroot && pax -rwpppm ${d} ${DESTDIR}${PREFIX}/awstats/
	chown -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/awstats/${d}
	find ${DESTDIR}${PREFIX}/awstats/${d} -type d -print	\
		| xargs chmod ${PKGDIRMODE}
	find ${DESTDIR}${PREFIX}/awstats/${d} -type f -print	\
		| xargs chmod ${SHAREMODE}
.endfor
	cd ${WRKSRC}/docs && pax -rwpppm . ${DESTDIR}${PREFIX}/share/doc/awstats/
	chown -R ${DOCOWN}:${DOCGRP} ${DESTDIR}${PREFIX}/share/doc/awstats/
	find ${DESTDIR}${PREFIX}/share/doc/awstats/ -type d -print	\
		| xargs chmod ${PKGDIRMODE}
	find ${DESTDIR}${PREFIX}/share/doc/awstats/ -type f -print	\
		| xargs chmod ${DOCMODE}

.include "../../mk/bsd.pkg.mk"
