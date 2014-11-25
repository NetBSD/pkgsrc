# $NetBSD: Makefile,v 1.5.2.1 2014/11/25 15:01:15 tron Exp $
#

DISTNAME=	contao-${CT_PKGVER}
PKGNAME=	contao${CT_VER}-${CT_PKGVER}
CATEGORIES=	www
MASTER_SITES=	${CT_MASTER_SITE}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.contao.org/
COMMENT=	Contao Open Source CMS ${CT_VERSION}
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.3.2:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3.2:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.3.2:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-{mysql,mysqli}>=5.3.2:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.3.2:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=5.3.2:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.3.2:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.2.7:../../archivers/php-zlib
DEPENDS+=	bash>=4.0:../../shells/bash

CT_VERS=	33
USE_TOOLS=	bash pax
NO_BUILD=	yes

EG_CONFIG=	ace.php agents.php constants.php countries.php \
		languages.php tcpdf.php timezones.php \
		tinyFlash.php tinyMCE.php tinyNews.php
EG_DATA=	${WWW_EG_FILES} system/config files
EG_TEMPLATES=	tinymce.css tiny_templates/index.html
WWW_EG_FILES=	robots.txt
RESTRICT_DIRS=	system/cache system/logs system/tmp templates files

CONF_FILES+=	${CT_EGDIR}/contao.conf ${PKG_SYSCONFDIR}/contao.conf

.for f in ${EG_CONFIG}
CONF_FILES+=	${CT_EGDIR}/system/config/${f} ${CT_WEBDIR}/system/config/${f}
.endfor

MAKE_DIRS+=	${CT_WEBDIR}/files/tiny_templates

REPLACE_BASH=	system/bin/minify system/bin/sqldump

.for f in ${EG_TEMPLATES}
REQD_FILES+=	${CT_EGDIR}/files/${f} ${CT_WEBDIR}/files/${f}
.endfor

.for f in ${WWW_EG_FILES}
REQD_FILES+=	${CT_EGDIR}/${f} ${CT_WEBDIR}/${f}
.endfor

.for d in ${RESTRICT_DIRS}
OWN_DIRS_PERMS+=	${CT_WEBDIR}/${d} ${APACHE_USER} ${APACHE_GROUP} 0770
.endfor

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	system/bin/automator system/bin/filesync \
	system/bin/ide_compat system/bin/txpurge system/bin/version \
	vendor/bin/pscss vendor/tecnick.com/tcpdf/tools/tcpdf_addfont.php \
	vendor/leafo/lessphp/lessify vendor/leafo/lessphp/plessc \
	vendor/leafo/scssphp/bin/pscss

SUBST_CLASSES+=		conf
SUBST_FILES.conf+=	${WRKDIR}/contao.conf
SUBST_SED.conf+=        -e 's|@PREFIX@|${PREFIX:Q}|g'
SUBST_SED.conf+=        -e 's|@CT_WEBDIR@|${CT_WEBDIR:Q}|g'
SUBST_STAGE.conf=	post-configure

WWW_FILES=	.htaccess.default README.md assets contao \
		index.php share templates vendor
WWW_SYSFILES=	.htaccess bin config/default.php cron docs helper \
		initialize.php modules themes

INSTALLATION_DIRS+=	${CT_DOCDIR} ${CT_EGDIR} ${CT_WEBDIR}/system/config

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

pre-configure:
	${CP} ${FILESDIR}/contao.conf ${WRKDIR}

pre-install:
	cd ${WRKSRC}; ${RM} -fr files/music_academy templates/music_academy.sql
	${FIND} ${WRKSRC} -name "*.orig*" -exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC}; pax -rw ${WWW_FILES} ${DESTDIR}${PREFIX}/${CT_WEBDIR}
	cd ${WRKSRC}/system; \
		pax -rw ${WWW_SYSFILES} \
			${DESTDIR}${PREFIX}/${CT_WEBDIR}/system
	cd ${WRKSRC}; pax -rw ${EG_DATA} ${DESTDIR}${PREFIX}/${CT_EGDIR}
	${INSTALL_DATA} ${WRKDIR}/contao.conf ${DESTDIR}${PREFIX}/${CT_EGDIR}
	${INSTALL_DATA} ${FILESDIR}/README \
		${DESTDIR}${PREFIX}/${CT_DOCDIR}

.include "../../www/contao/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
