# $NetBSD: Makefile,v 1.1.1.1 2008/09/15 09:57:48 taca Exp $
#

DISTNAME=	typolight-${TL_VERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=typolight/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.typolight.org/
COMMENT=	Powerful web content management system (CMS)

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.1.0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.1.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.1.0:../../security/php-mcrypt

PHP_VERSIONS_ACCEPTED=	5

USE_TOOLS=	pax
NO_BUILD=	yes

EG_DATA=	basic.css news.xml print.css system/config tl_files
EG_FILES=	system/config/config.php system/config/countries.php \
		system/config/dcaconfig.php system/config/languages.php \
		system/config/tcpdf.php system/config/timezones.php \
		system/config/tinyFlash.php system/config/tinyMCE.php \
		system/config/tinyNews.php
TMPL_FILES=	tl_files/tiny_templates/index.html \
		tl_files/xBrowser_style_sheets/xBasic.css \
		tl_files/xBrowser_style_sheets/xElements.css \
		tl_files/xBrowser_style_sheets/xForm.css \
		tl_files/xBrowser_style_sheets/xNavigation.css
WWW_EG_FILES=	basic.css news.xml print.css

CONF_FILES_PERMS+=	${TL_EGDIR}/system/config/localconfig.php \
			${TL_WEBDIR}/system/config/localconfig.php \
			${APACHE_USER} ${APACHE_GROUP} 0600

.for f in ${EG_FILES}
CONF_FILES+=		${TL_EGDIR}/${f} ${TL_WEBDIR}/${f}
.endfor

.for f in ${TMPL_FILES}
REQD_FILES+=		${TL_EGDIR}/${f} ${TL_WEBDIR}/${f}
.endfor

.for f in ${WWW_EG_FILES}
CONF_FILES_PERMS+=	${TL_EGDIR}/${f} ${TL_WEBDIR}/${f} www www 0644
.endfor

WWW_FILES=	._htaccess CHANGELOG.txt INSTALL.txt LICENSE.txt \
		cron.php flash.php index.php \
		plugins robots.txt templates typolight
WWW_SYSFILES=	config/.htaccess constants.php drivers functions.php \
		html iefixes.css initialize.php interface.php libraries \
		logs/.htaccess mbstring.php modules themes tmp/.htaccess \
		typolight.css

INSTALLATION_DIRS+=	${TL_EGDIR} ${TL_WEBDIR}/system/config
OWN_DIRS_PERMS+= \
		${TL_WEBDIR} root ${APACHE_GROUP} 0775 \
		${TL_WEBDIR}/system/html ${BINOWN} ${APACHE_GROUP} 0770 \
		${TL_WEBDIR}/system/logs ${BINOWN} ${APACHE_GROUP} 0770 \
		${TL_WEBDIR}/system/tmp ${BINOWN} ${APACHE_GROUP} 0770 \
		${TL_WEBDIR}/tl_files ${BINOWN} ${APACHE_GROUP} 0770 \
		${TL_WEBDIR}/tl_files/tiny_templates \
		${BINOWN} ${APACHE_GROUP} 0770 \
		${TL_WEBDIR}/tl_files/xBrowser_style_sheets \
		${BINOWN} ${APACHE_GROUP} 0770

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

pre-configure:
	cd ${WRKSRC}; ${RM} -rf music_academy.css \
		templates/example_website.sql tl_files/music_academy; \
		${CP} /dev/null news.xml

do-install:
	cd ${WRKSRC}; pax -rw -pm ${WWW_FILES} ${DESTDIR}${PREFIX}/${TL_WEBDIR}
	cd ${WRKSRC}/system; \
		pax -rw -pm ${WWW_SYSFILES} \
			${DESTDIR}${PREFIX}/${TL_WEBDIR}/system; \
		${INSTALL_DATA} config/.htaccess \
			${DESTDIR}${PREFIX}/${TL_WEBDIR}/system/config
	cd ${WRKSRC}; pax -rw -pm ${EG_DATA} ${DESTDIR}${PREFIX}/${TL_EGDIR}
	rm -f ${DESTDIR}${PREFIX}/${TL_EGDIR}/system/config/.htaccess

.include "Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
