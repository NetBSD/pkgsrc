# $NetBSD: Makefile,v 1.21 2025/02/08 04:04:40 taca Exp $

DISTNAME=	glpi-${GLPI_VERSION}
PKGREVISION=	2
GLPI_VERSION=	10.0.12
CATEGORIES=	www

MASTER_SITES=	${MASTER_SITE_GITHUB:=glpi-project/}glpi/releases/download/${GLPI_VERSION}/
#MASTER_SITES=	https://github.com/glpi-project/glpi/releases/download/${GLPI_VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://glpi-project.org/
COMMENT=	IT inventory management software
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-bz2>=${PHP_BASE_VERS}:../../archivers/php-bz2
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=${PHP_BASE_VERS}:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=${PHP_BASE_VERS}:../../mail/php-imap
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=${PHP_BASE_VERS}:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=${PHP_BASE_VERS}:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-opcache>=${PHP_BASE_VERS}:../../devel/php-opcache
DEPENDS+=	${PHP_PKG_PREFIX}-sodium>=${PHP_BASE_VERS}:../../security/php-sodium
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=${PHP_BASE_VERS}:../../archivers/php-zlib

DEPENDS+=	freefont-ttf-[0-9]*:../../fonts/freefont-ttf

NO_BUILD=	yes
USE_LANGUAGES=	# none

USE_TOOLS+=	chmod find pax

BUILD_DEFS+=	APACHE_USER APACHE_GROUP VARBASE

MESSAGE_SUBST+=	APACHE_USER="${APACHE_USER}"

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/glpi

# Config dir managed through web interface (move under {VARBASE}/glpi?)
PKG_SYSCONFSUBDIR=	glpi
PKG_SYSCONFDIR_PERMS=	${APACHE_USER} ${APACHE_GROUP} 0700

EGDIR=			share/examples/glpi
GLPI_DIR=		share/glpi

.for ddd in local_define.php
CONF_FILES+=		${EGDIR}/${ddd} ${PKG_SYSCONFDIR}/${ddd}
.endfor
CONF_FILES+=		${EGDIR}/var_glpi.htaccess ${VARBASE}/glpi/.htaccess

MAKE_DIRS_PERMS+=	${VARBASE}/glpi ${APACHE_USER} ${APACHE_GROUP} 0700
.for ddd in _cache _cron _dumps _graphs _lock _log _pictures _plugins \
	 _rss _sessions _tmp _uploads
MAKE_DIRS_PERMS+=	${VARBASE}/glpi/${ddd} \
			${APACHE_USER} ${APACHE_GROUP} 0750
.endfor
MAKE_DIRS_PERMS+=	${VARBASE}/log/glpi \
			${APACHE_USER} ${REAL_ROOT_GROUP} 0750

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_MESSAGE.path=	Fixing paths.
SUBST_VARS.path=	PREFIX VARBASE PKG_SYSCONFDIR APACHE_USER
SUBST_FILES.path=	config/local_define.php
SUBST_FILES.path+=	inc/downstream.php
SUBST_FILES.path+=	config/crontab.sample
SUBST_FILES.path+=	config/httpd-glpi.conf

REPLACE_PHP+=		bin/console

OWN_DIRS_PERMS+=	${GLPI_DIR}/marketplace ${APACHE_USER} \
				${APACHE_GROUP} 0750

INSTALLATION_DIRS+=	${EGDIR} ${GLPI_DIR} ${GLPI_DIR}/marketplace

post-extract:
	for ddd in local_define.php crontab.sample httpd-glpi.conf ; do \
		${CP} ${FILESDIR}/$${ddd} ${WRKSRC}/config ; \
	done
	${CP} ${FILESDIR}/downstream.php ${WRKSRC}/inc
	for ddd in ajax css front inc lib locales src pics vendor ; do \
		find ${WRKSRC}/$${ddd} -type f -exec ${CHMOD} ugo-x \{\} \; ; \
	done
	cd ${WRKSRC}/install && ${MV} install.php install.php.disabled

do-install:
	find ${WRKSRC} -name \*.orig -exec rm {} \;
	cd ${WRKSRC}/config && ${PAX} -rw * ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/files/.htaccess \
		${DESTDIR}${PREFIX}/${EGDIR}/var_glpi.htaccess
	# Sub-tree will be re-created in VARBASE/glpi
	cd ${WRKSRC} && rm -r files
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/${GLPI_DIR}

.include "../../lang/php/json.mk"
.include "../../mk/apache.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
