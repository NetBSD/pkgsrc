# $NetBSD: Makefile,v 1.10 2011/01/06 13:19:08 taca Exp $
#

DISTNAME=	contao-${CT_VERSION}
PKGNAME=	contao${CT_VER}-${CT_PKGVER}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=typolight/}
DIST_SUBDIR=	${PKGBASE}-20101203

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.contao.org/
COMMENT=	Contao Open Source CMS
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.2.0:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.2.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.2.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.2.0:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=5.2.0:../../net/php-soap

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS=	pax
NO_BUILD=	yes

EG_DATA=	${WWW_EG_FILES} system/config tl_files
EG_FILES=	system/config/config.php system/config/countries.php \
		system/config/dcaconfig.php system/config/editArea.php \
		system/config/fancyUpload.php system/config/initconfig.php \
		system/config/langconfig.php system/config/languages.php \
		system/config/tcpdf.php system/config/timezones.php \
		system/config/tinyFlash.php system/config/tinyMCE.php \
		system/config/tinyNews.php
TMPL_FILES=	tl_files/tinymce.css tl_files/tiny_templates/index.html
WWW_EG_FILES=	basic.css print.css robots.txt

CONF_FILES_PERMS+=	${CT_EGDIR}/system/config/localconfig.php \
			${CT_WEBDIR}/system/config/localconfig.php \
			${APACHE_USER} ${APACHE_GROUP} 0600

CONF_FILES+=		${CT_EGDIR}/contao.conf ${PKG_SYSCONFDIR}/contao.conf

.for f in ${EG_FILES}
CONF_FILES+=		${CT_EGDIR}/${f} ${CT_WEBDIR}/${f}
.endfor

.for f in ${TMPL_FILES}
REQD_FILES+=		${CT_EGDIR}/${f} ${CT_WEBDIR}/${f}
.endfor

.for f in ${WWW_EG_FILES}
CONF_FILES_PERMS+=	${CT_EGDIR}/${f} ${CT_WEBDIR}/${f} \
			${APACHE_USER} ${APACHE_GROUP} 0644
.endfor

SUBST_CLASSES+=		conf
SUBST_FILES.conf+=	${WRKDIR}/contao.conf
SUBST_SED.conf+=        -e 's|@PREFIX@|${PREFIX:Q}|g'
SUBST_SED.conf+=        -e 's|@CT_WEBDIR@|${CT_WEBDIR:Q}|g'
SUBST_STAGE.conf=	post-configure

WWW_FILES=	CHANGELOG.txt GPL.txt INSTALL.txt LGPL.txt \
		contao cron.php index.php plugins share.php templates \
		typolight
WWW_SYSFILES=	config/.htaccess constants.php contao.css drivers \
		functions.php html iefixes.css initialize.php interface.php \
		libraries logs/.htaccess mbstring.php modules themes \
		tmp/.htaccess utf8_lookup.php

INSTALLATION_DIRS+=	${CT_DOCDIR} ${CT_EGDIR} ${CT_WEBDIR}/system/config
OWN_DIRS_PERMS+= \
	${CT_WEBDIR} ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${CT_WEBDIR}/plugins ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${CT_WEBDIR}/plugins/tcpdf/cache \
		${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${CT_WEBDIR}/system ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${CT_WEBDIR}/system/drivers ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${CT_WEBDIR}/system/html ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
	${CT_WEBDIR}/system/libraries ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${CT_WEBDIR}/system/logs ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
	${CT_WEBDIR}/system/modules ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${CT_WEBDIR}/system/themes ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${CT_WEBDIR}/system/tmp ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
	${CT_WEBDIR}/templates ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
	${CT_WEBDIR}/tl_files ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
	${CT_WEBDIR}/tl_files/tiny_templates \
		${REAL_ROOT_USER} ${APACHE_GROUP} 0770

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

.include "../../www/contao/options.mk"

pre-configure:
	${CP} ${FILESDIR}/contao.conf ${WRKDIR}

pre-install:
	cd ${WRKSRC}; ${RM} -rf music_academy.css \
		templates/music_academy.sql tl_files/music_academy
	${FIND} ${WRKSRC} -name "*.orig*" -exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC}; pax -rw ${WWW_FILES} ${DESTDIR}${PREFIX}/${CT_WEBDIR}
	cd ${WRKSRC}/system; \
		pax -rw ${WWW_SYSFILES} \
			${DESTDIR}${PREFIX}/${CT_WEBDIR}/system; \
		${INSTALL_DATA} config/.htaccess \
			${DESTDIR}${PREFIX}/${CT_WEBDIR}/system/config
	${INSTALL_DATA} ${WRKSRC}/templates/.htaccess \
		${DESTDIR}${PREFIX}/${CT_WEBDIR}/templates
	cd ${WRKSRC}; pax -rw ${EG_DATA} ${DESTDIR}${PREFIX}/${CT_EGDIR}
	rm -f ${DESTDIR}${PREFIX}/${CT_EGDIR}/system/config/.htaccess
	${INSTALL_DATA} ${WRKSRC}/.htaccess.default \
		${DESTDIR}${PREFIX}/${CT_EGDIR}/htaccess.default
	${INSTALL_DATA} ${WRKDIR}/contao.conf ${DESTDIR}${PREFIX}/${CT_EGDIR}
	${INSTALL_DATA} ${FILESDIR}/README \
		${DESTDIR}${PREFIX}/${CT_DOCDIR}

.include "Makefile.version"
.include "../../www/contao/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
