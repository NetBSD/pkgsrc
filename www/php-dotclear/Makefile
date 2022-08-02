# $NetBSD: Makefile,v 1.6 2022/08/02 20:09:00 triaxx Exp $

DISTNAME=	dotclear-2.22
PKGREVISION=	1
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://download.dotclear.org/latest/ \
		https://download.dotclear.org/attic/

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://dotclear.org/
COMMENT=	Open-source web publising software
LICENSE=	gnu-gpl-v2

.include "../../lang/php/phpversion.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
.if ${PKG_PHP_MAJOR_VERS} < 8
DEPENDS+=	${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}:../../textproc/php-json
.endif
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=${PHP_BASE_VERS}:../../archivers/php-zlib

NO_BUILD=	yes
USE_TOOLS+=	find pax sed
WRKSRC=		${WRKDIR}/dotclear
BUILD_DEFS+=	PKG_SYSCONFBASE VARBASE

.include "options.mk"

PHP_VERSIONS_ACCEPTED=	81 80 74

PKG_SYSCONFSUBDIR=	dotclear

DOTCLEAR_USER?=		dotclear
DOTCLEAR_GROUP?=	dotclear
DOTCLEAR_SHAREDIR?=	${PREFIX}/share/dotclear
DOTCLEAR_CACHEDIR?=	${VARBASE}/cache/dotclear
DOTCLEAR_DBDIR?=	${VARBASE}/db/dotclear
DOTCLEAR_LOGDIR?=	${VARBASE}/log/dotclear
DOTCLEAR_PUBDIR?=	${DOTCLEAR_DBDIR}/public
DOTCLEAR_PLUGDIR?=	${DOTCLEAR_DBDIR}/plugins

REQD_FILES_PERMS+=	${EGDIR}/config.php.in ${PKG_SYSCONFDIR}/config.php.in \
			${DOTCLEAR_USER} ${DOTCLEAR_GROUP} 644
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${DOTCLEAR_USER} ${DOTCLEAR_GROUP} 770
OWN_DIRS_PERMS+=	${DOTCLEAR_CACHEDIR} ${DOTCLEAR_USER} ${DOTCLEAR_GROUP} 775
OWN_DIRS_PERMS+=	${DOTCLEAR_DBDIR} ${DOTCLEAR_USER} ${DOTCLEAR_GROUP} 775
OWN_DIRS_PERMS+=	${DOTCLEAR_PUBDIR} ${DOTCLEAR_USER} ${DOTCLEAR_GROUP} 775
OWN_DIRS_PERMS+=	${DOTCLEAR_PLUGDIR} ${DOTCLEAR_USER} ${DOTCLEAR_GROUP} 775
OWN_DIRS_PERMS+=	${DOTCLEAR_LOGDIR} ${DOTCLEAR_USER} ${DOTCLEAR_GROUP} 775

PKG_GROUPS+=			${DOTCLEAR_GROUP}
PKG_USERS+=			${DOTCLEAR_USER}:${DOTCLEAR_GROUP}
PKG_GECOS.${DOTCLEAR_USER}=	Dotclear user

EGDIR=		${PREFIX}/share/examples/dotclear

INSTALLATION_DIRS=	${DOTCLEAR_SHAREDIR} ${EGDIR}

SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	do-configure
SUBST_MESSAGE.cfg=	Adapting files to use pkgsrc directories.
SUBST_FILES.cfg=	admin/install/index.php admin/install/wizard.php
SUBST_FILES.cfg+=	inc/config.php.in inc/core/class.dc.core.php
SUBST_FILES.cfg+=	inc/load_plugin_file.php inc/prepend.php
SUBST_VARS.cfg=		PKG_SYSCONFDIR DOTCLEAR_SHAREDIR DOTCLEAR_CACHEDIR DOTCLEAR_DBDIR
SUBST_VARS.cfg+=	DOTCLEAR_PUBDIR DOTCLEAR_PLUGDIR DOTCLEAR_LOGDIR

pre-configure:
	${SED} -e 's|@DOTCLEAR_SHAREDIR@|${DOTCLEAR_SHAREDIR}|g' \
	       -e 's|@DOTCLEAR_PUBDIR@|${DOTCLEAR_PUBDIR}|g' ${FILESDIR}/apache24.conf > ${WRKSRC}/apache24.conf
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/initdb-mysql.sh > ${WRKSRC}/initdb-mysql.sh
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/initdb-pgsql.sh > ${WRKSRC}/initdb-pgsql.sh
	${SED} -e 's|@DOTCLEAR_SHAREDIR@|${DOTCLEAR_SHAREDIR}|g' \
	       -e 's|@DOTCLEAR_PUBDIR@|${DOTCLEAR_PUBDIR}|g' \
	       -e 's|@VARBASE@|${VARBASE}|g' ${FILESDIR}/lighttpd.conf > ${WRKSRC}/lighttpd.conf
	${SED} -e 's|@DOTCLEAR_SHAREDIR@|${DOTCLEAR_SHAREDIR}|g' \
	       -e 's|@DOTCLEAR_PUBDIR@|${DOTCLEAR_PUBDIR}|g' \
	       -e 's|@VARBASE@|${VARBASE}|g' ${FILESDIR}/nginx.conf > ${WRKSRC}/nginx.conf
	${SED} -e 's|@VARBASE@|${VARBASE}|g' ${FILESDIR}/php-fpm.conf > ${WRKSRC}/php-fpm.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/index.php ${DESTDIR}${DOTCLEAR_SHAREDIR}/index.php
.for d in admin inc locales plugins themes
	${INSTALL_DATA_DIR} ${DESTDIR}${DOTCLEAR_SHAREDIR}/${d}
	cd ${WRKSRC}/${d} && ${FIND} . -type f \! -name '*.orig' -print | \
		${PAX} -rw ${DESTDIR}${DOTCLEAR_SHAREDIR}/${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/inc/config.php.in ${DESTDIR}${EGDIR}/config.php.in
	${RM} -f ${DESTDIR}${DOTCLEAR_SHAREDIR}/inc/config.php.in
	${INSTALL_DATA} ${WRKSRC}/apache24.conf ${DESTDIR}${EGDIR}/apache24.conf
	${INSTALL_DATA} ${WRKSRC}/initdb-mysql.sh ${DESTDIR}${EGDIR}/initdb-mysql.sh
	${INSTALL_DATA} ${WRKSRC}/initdb-pgsql.sh ${DESTDIR}${EGDIR}/initdb-pgsql.sh
	${INSTALL_DATA} ${WRKSRC}/lighttpd.conf ${DESTDIR}${EGDIR}/lighttpd.conf
	${INSTALL_DATA} ${WRKSRC}/nginx.conf ${DESTDIR}${EGDIR}/nginx.conf
	${INSTALL_DATA} ${WRKSRC}/php-fpm.conf ${DESTDIR}${EGDIR}/php-fpm.conf

.include "../../mk/bsd.pkg.mk"
