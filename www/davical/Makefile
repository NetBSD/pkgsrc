# $NetBSD: Makefile,v 1.35 2018/08/22 09:47:24 wiz Exp $

DISTNAME=	davical-${DAVICAL_VERSION}
PKGNAME=	${PHP_PKG_PREFIX}-davical-${DAVICAL_VERSION}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	-https://gitlab.com/davical-project/davical/repository/archive.tar.gz?ref=${GITLAB_TAG}

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	https://www.davical.org/
COMMENT=	Simple CalDAV server using a PostgreSQL backend
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

DAVICAL_VERSION=1.1.7
GITLAB_TAG=	r${DAVICAL_VERSION}
GITLAB_REV=	05397d635c3f218b850775223aa5dd705da9f91c

DAVICALDIR=	${PREFIX}/share/davical
EGDIR=		${PREFIX}/share/examples/davical
DOCDIR=		${PREFIX}/share/doc/davical

BUILD_DEFS=	APACHE_USER APACHE_GROUP PGUSER PGGROUP

# davical_dba account
DAVICAL_USER?=	${PGUSER}
DAVICAL_GROUP?=	${PGGROUP}

USE_TOOLS=	gmake pax msgfmt perl

PAXDIRS=	htdocs inc dba po scripts

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}/config

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.2:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=4.3.1:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql>=${PHP_BASE_VERS}:../../databases/php-pdo_pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-libawl>=0.56:../../devel/php-libawl
DEPENDS+=	${PHP_PKG_PREFIX}-calendar>=5.3.18:../../time/php-calendar
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.3.18:../../www/php-curl
DEPENDS+=	p5-DBI>=1.631:../../databases/p5-DBI
DEPENDS+=	p5-DBD-postgresql>=3.5:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-YAML>=0.71:../../textproc/p5-YAML
DEPENDS+=	pwgen>=2.06:../../sysutils/pwgen
DEPENDS+=	postgresql${PGSQL_VERSION}-client-[0-9]*:../../databases/postgresql${PGSQL_VERSION}-client

PKG_SYSCONFSUBDIR=	davical

MESSAGE_SUBST+=		DAVICALDIR=${DAVICALDIR:Q} DOCDIR=${DOCDIR:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}

CONF_FILES=		${EGDIR}/davical.conf	\
			${PKG_SYSCONFDIR}/davical.conf

CONF_FILES_PERMS+=	${EGDIR}/config/example-administration.yml	\
			${PKG_SYSCONFDIR}/administration.yml		\
			${DAVICAL_USER} ${DAVICAL_GROUP} 0600

CONF_FILES_PERMS+=	${EGDIR}/config/example-config.php	\
			${PKG_SYSCONFDIR}/config.php		\
			${APACHE_USER} ${APACHE_GROUP} 0640

REPLACE_PERL=		dba/update-davical-database scripts/davical-cli

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	scripts/archive-old-events.php
REPLACE_FILES.php+=	scripts/cron-sync-ldap.php
REPLACE_FILES.php+=	scripts/export_calendar.php
REPLACE_FILES.php+=	scripts/load_calendar.php
REPLACE_FILES.php+=	scripts/refresh-alarms.php
REPLACE_FILES.php+=	scripts/sync-remote-caldav.php
REPLACE_FILES.php+=	scripts/tz-update.php

SUBST_CLASSES+=		conf-path
SUBST_STAGE.conf-path=	pre-configure
SUBST_FILES.conf-path=	inc/always.php.in dba/update-davical-database
SUBST_FILES.conf-path+=	inc/davical_configuration_missing.php
SUBST_SED.conf-path+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.conf-path=Fixing configuration path.

# See ../../devel/php-libawl/Makefile.common for the LIBAWLDIR value
SUBST_CLASSES+=		inc-path
SUBST_STAGE.inc-path=	pre-configure
SUBST_FILES.inc-path=	davical.conf inc/always.php.in
SUBST_FILES.inc-path+=	scripts/po/rebuild-translations.sh
SUBST_FILES.inc-path+=	dba/create-database.sh
SUBST_SED.inc-path+=	-e "s|@LIBAWLPATH@|${PREFIX}/${LIBAWLDIR}|g"
SUBST_SED.inc-path+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.inc-path=	Fixing AWL include path.

SUBST_CLASSES+=		examples
SUBST_STAGE.examples=	pre-configure
SUBST_FILES.examples=	dba/create-database.sh
SUBST_SED.examples+=	-e "s|@EGDIRCONFIG@|${EGDIR}/config|g"
SUBST_MESSAGE.examples=	Fixing config examples path.

SUBST_CLASSES+=		files
SUBST_STAGE.files=	pre-configure
SUBST_FILES.files=	davical.conf
SUBST_SED.files+=	-e "s|@DAVICALDIR@|${DAVICALDIR}|g"
SUBST_MESSAGE.files=	Fixing DAViCal configuration file for Apache.

pre-patch:
	${MV} ${WRKDIR}/davical-${GITLAB_TAG}-${GITLAB_REV} ${WRKSRC}
	${CP} ${FILESDIR}/davical.conf ${WRKSRC}/davical.conf

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f
	${FIND} ${WRKSRC} -name ".gitignore" -print | ${XARGS} ${RM} -f
	${FIND} ${WRKSRC}/po -name "*~" -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA} ${WRKSRC}/davical.conf	\
		${DESTDIR}${EGDIR}/davical.conf

	cd ${WRKSRC}/docs && pax -rwpam . ${DESTDIR}${DOCDIR}

.	for f in COPYING CREDITS ChangeLog INSTALL README TODO VERSION
		cd ${WRKSRC} && \
		${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.	endfor

.	for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${DESTDIR}${DAVICALDIR}/${d}
		cd ${WRKSRC}/${d} && pax -rwpam . ${DESTDIR}${DAVICALDIR}/${d}
.	endfor

	cd ${WRKSRC}/config && for f in *; do				\
		${INSTALL_DATA} $$f ${DESTDIR}${EGDIR}/config/$$f;	\
	done

.include "../../mk/pgsql.buildlink3.mk"
.include "../../devel/php-libawl/Makefile.common"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
