# $NetBSD: Makefile,v 1.17 2022/08/16 13:52:48 hauke Exp $

DISTNAME=	glpi-${GLPI_VERSION}
GLPI_VERSION=	10.0.2
CATEGORIES=	www

MASTER_SITES=	${MASTER_SITE_GITHUB:=glpi-project/}glpi/releases/download/${GLPI_VERSION}/
#MASTER_SITES=	https://github.com/glpi-project/glpi/releases/download/${GLPI_VERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://glpi-project.org/
COMMENT=	IT inventory management software
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-bz2>=7.4:../../archivers/php-bz2
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=7.4:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=7.4:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=7.4:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=7.4:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=7.4:../../mail/php-imap
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=7.4:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=7.4:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=7.4:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=7.4:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-opcache>=7.4:../../devel/php-opcache
DEPENDS+=	${PHP_PKG_PREFIX}-sodium>=7.4:../../security/php-sodium
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=7.4:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=7.4:../../archivers/php-zlib

DEPENDS+=	freefont-ttf-[0-9]*:../../fonts/freefont-ttf

.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} == 74
DEPENDS+=	${PHP_PKG_PREFIX}-json>=7.4:../../textproc/php-json
.endif

NO_BUILD=	yes
USE_LANGUAGES=	# none

USE_TOOLS+=	chmod find pax

BUILD_DEFS+=	APACHE_USER APACHE_GROUP VARBASE

MESSAGE_SUBST+=	APACHE_USER="${APACHE_USER}"

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/glpi

# Config dir managed through web interface (move under {VARBASE}/glpi?)
PKG_SYSCONFSUBDIR=	glpi
PKG_SYSCONFDIR_PERMS=	${APACHE_USER} ${APACHE_GROUP} 0700

EGDIR=		share/examples/glpi
GLPI_DIR=	share/glpi

.for ddd in local_define.php
CONF_FILES+=	${EGDIR}/${ddd} ${PKG_SYSCONFDIR}/${ddd}
.endfor
CONF_FILES+=	${EGDIR}/var_glpi.htaccess ${VARBASE}/glpi/.htaccess

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

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	vendor/tecnickcom/tcpdf/tools/tcpdf_addfont.php
REPLACE_FILES.php+=	bin/console
.for ddd in  bench.php fetch_windows_zones.php generate_vcards \
	     generateicalendardata.php vobject
REPLACE_FILES.php+=	vendor/sabre/vobject/bin/${ddd}
.endfor

OWN_DIRS_PERMS+=	${GLPI_DIR}/marketplace ${APACHE_USER} \
				${APACHE_GROUP} 0750

INSTALLATION_DIRS+=	${EGDIR} ${GLPI_DIR} ${GLPI_DIR}/marketplace

post-extract:
	for ddd in local_define.php crontab.sample httpd-glpi.conf ; do \
		${CP} ${FILESDIR}/$${ddd} ${WRKSRC}/config ; \
	done
	${CP} ${FILESDIR}/downstream.php ${WRKSRC}/inc
	for ddd in ajax css front inc lib locales pics vendor ; do \
		find ${WRKSRC}/$${ddd} -type f -exec ${CHMOD} ugo-x \{\} \; ; \
	done
	cd ${WRKSRC}/install && ${MV} install.php install.php.disabled

do-install:
	cd ${WRKSRC}/config && ${PAX} -rw * ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/files/.htaccess \
		${DESTDIR}${PREFIX}/${EGDIR}/var_glpi.htaccess
	# Sub-tree will be re-created in VARBASE/glpi
	cd ${WRKSRC} && rm -r files
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/${GLPI_DIR}

.include "../../mk/apache.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
