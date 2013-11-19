# $NetBSD: Makefile,v 1.13 2013/11/19 14:19:58 taca Exp $
#

DISTNAME=	${CT_VERSION}
PKGNAME=	contao${CT_VER}-${CT_PKGVER}
CATEGORIES=	www
MASTER_SITES=	${CT_MASTER_SITE}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.contao.org/
COMMENT=	Contao Open Source CMS ${CT_VERBASE}
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.2.0:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.2.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.2.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-{mysql,mysqli}>=5.2.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.2.0:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=5.2.0:../../net/php-soap

CT_VERS=	211
USE_TOOLS=	pax
NO_BUILD=	yes

EG_CONFIG=	agents.php codeMirror.php countries.php \
		languages.php tcpdf.php timezones.php tinyFlash.php \
		tinyMCE.php tinyNews.php
EG_DATA=	${WWW_EG_FILES} system/config tl_files
EG_TEMPLATES=	tinymce.css tiny_templates/index.html
WWW_EG_FILES=	robots.txt
RESTRICT_DIRS=	system/html system/logs system/scripts system/tmp \
		templates tl_files

CONF_FILES+=	${CT_EGDIR}/contao.conf ${PKG_SYSCONFDIR}/contao.conf

.for f in ${EG_CONFIG}
CONF_FILES+=	${CT_EGDIR}/system/config/${f} ${CT_WEBDIR}/system/config/${f}
.endfor

MAKE_DIRS+=	${CT_WEBDIR}/tl_files/tiny_templates

.for f in ${EG_TEMPLATES}
REQD_FILES+=	${CT_EGDIR}/tl_files/${f} ${CT_WEBDIR}/tl_files/${f}
.endfor

.for f in ${WWW_EG_FILES}
REQD_FILES+=	${CT_EGDIR}/${f} ${CT_WEBDIR}/${f}
.endfor

.for d in ${RESTRICT_DIRS}
OWN_DIRS_PERMS+=	${CT_WEBDIR}/${d} ${APACHE_USER} ${APACHE_GROUP} 0770
.endfor

SUBST_CLASSES+=		conf
SUBST_FILES.conf+=	${WRKDIR}/contao.conf
SUBST_SED.conf+=        -e 's|@PREFIX@|${PREFIX:Q}|g'
SUBST_SED.conf+=        -e 's|@CT_WEBDIR@|${CT_WEBDIR:Q}|g'
SUBST_STAGE.conf=	post-configure

WWW_FILES=	.htaccess.default CHANGELOG.md GPL.txt LGPL.txt README.md \
		contao cron.php index.php plugins share.php templates \
		typolight
WWW_SYSFILES=	config/.htaccess config/config.php constants.php contao.css \
		drivers functions.php html initialize.php interface.php \
		libraries logs/.htaccess mbstring.php modules \
		scripts/index.html themes tmp/.htaccess utf8_lookup.php

INSTALLATION_DIRS+=	${CT_DOCDIR} ${CT_EGDIR} ${CT_WEBDIR}/system/config

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

pre-configure:
	${RM} -f ${WRKSRC}/.gitignore ${WRKSRC}/system/tmp/*.txt
	${CP} ${FILESDIR}/contao.conf ${WRKDIR}

pre-install:
	cd ${WRKSRC}; ${RM} -rf music_academy.css \
		templates/music_academy.sql tl_files/music_academy
	${FIND} ${WRKSRC} -name "*.orig*" -exec ${RM} -f {} \;
	${FIND} ${WRKSRC}/plugins/tinyMCE -type f -exec ${CHMOD} -x {} \;

do-install:
	cd ${WRKSRC}; pax -rw ${WWW_FILES} ${DESTDIR}${PREFIX}/${CT_WEBDIR}
	cd ${WRKSRC}/system; \
		pax -rw ${WWW_SYSFILES} \
			${DESTDIR}${PREFIX}/${CT_WEBDIR}/system
	${INSTALL_DATA} ${WRKSRC}/templates/.htaccess \
		${DESTDIR}${PREFIX}/${CT_WEBDIR}/templates
	cd ${WRKSRC}; pax -rw ${EG_DATA} ${DESTDIR}${PREFIX}/${CT_EGDIR}
	rm -f ${DESTDIR}${PREFIX}/${CT_EGDIR}/system/config/.htaccess
	${INSTALL_DATA} ${WRKDIR}/contao.conf ${DESTDIR}${PREFIX}/${CT_EGDIR}
	${INSTALL_DATA} ${FILESDIR}/README \
		${DESTDIR}${PREFIX}/${CT_DOCDIR}

.include "../../www/contao/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
