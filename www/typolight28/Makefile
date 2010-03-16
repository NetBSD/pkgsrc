# $NetBSD: Makefile,v 1.5 2010/03/16 16:02:21 taca Exp $
#

DISTNAME=	typolight-${TL_VERSION}
PKGNAME=	typolight${TL_VER}-${TL_PKGVER}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=typolight/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.typolight.org/
COMMENT=	Powerful web content management system (CMS)
LICENSE=	gnu-lgpl-v3

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
		system/config/dcaconfig.php system/config/langconfig.php \
		system/config/languages.php \
		system/config/tcpdf.php system/config/timezones.php \
		system/config/tinyFlash.php system/config/tinyMCE.php \
		system/config/tinyNews.php
TMPL_FILES=	tl_files/tiny_templates/index.html
WWW_EG_FILES=	basic.css print.css robots.txt

CONF_FILES_PERMS+=	${TL_EGDIR}/system/config/localconfig.php \
			${TL_WEBDIR}/system/config/localconfig.php \
			${APACHE_USER} ${APACHE_GROUP} 0600

CONF_FILES+=		${TL_EGDIR}/typolight.conf \
			${PKG_SYSCONFDIR}/typolight.conf \
			${TL_EGDIR}/templates-htaccess \
			${TL_WEBDIR}/templates/.htaccess

.for f in ${EG_FILES}
CONF_FILES+=		${TL_EGDIR}/${f} ${TL_WEBDIR}/${f}
.endfor

.for f in ${TMPL_FILES}
REQD_FILES+=		${TL_EGDIR}/${f} ${TL_WEBDIR}/${f}
.endfor

.for f in ${WWW_EG_FILES}
CONF_FILES_PERMS+=	${TL_EGDIR}/${f} ${TL_WEBDIR}/${f} \
			${APACHE_USER} ${APACHE_GROUP} 0644
.endfor

SUBST_CLASSES+=		conf
SUBST_FILES.conf+=	${WRKDIR}/typolight.conf
SUBST_SED.conf+=        -e 's|@PREFIX@|${PREFIX:Q}|g'
SUBST_SED.conf+=        -e 's|@TL_WEBDIR@|${TL_WEBDIR:Q}|g'
SUBST_STAGE.conf=	post-configure

WWW_FILES=	CHANGELOG.txt GPL.txt INSTALL.txt LGPL.txt \
		cron.php index.php plugins templates typolight
WWW_SYSFILES=	config/.htaccess constants.php drivers functions.php \
		html iefixes.css initialize.php interface.php libraries \
		logs/.htaccess mbstring.php modules themes tmp/.htaccess \
		typolight.css

INSTALLATION_DIRS+=	${TL_DOCDIR} ${TL_EGDIR} ${TL_WEBDIR}/system/config
OWN_DIRS_PERMS+= \
	${TL_WEBDIR} ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${TL_WEBDIR}/plugins ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${TL_WEBDIR}/plugins/tcpdf/cache \
		${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${TL_WEBDIR}/system ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${TL_WEBDIR}/system/drivers ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${TL_WEBDIR}/system/html ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
	${TL_WEBDIR}/system/libraries ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${TL_WEBDIR}/system/logs ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
	${TL_WEBDIR}/system/modules ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${TL_WEBDIR}/system/themes ${REAL_ROOT_USER} ${APACHE_GROUP} 0775 \
	${TL_WEBDIR}/system/tmp ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
	${TL_WEBDIR}/templates ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
	${TL_WEBDIR}/tl_files ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
	${TL_WEBDIR}/tl_files/tiny_templates \
		${REAL_ROOT_USER} ${APACHE_GROUP} 0770

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

.include "../../www/typolight/options.mk"

pre-configure:
	${MV} ${WRKSRC}/templates/.htaccess ${WRKDIR}/templates-htaccess
	${CP} ${FILESDIR}/typolight.conf ${WRKDIR}

pre-install:
	cd ${WRKSRC}; ${RM} -rf music_academy.css \
		templates/music_academy.sql tl_files/music_academy
	${FIND} ${WRKSRC} -name "*.orig*" -exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC}; pax -rw ${WWW_FILES} ${DESTDIR}${PREFIX}/${TL_WEBDIR}
	cd ${WRKSRC}/system; \
		pax -rw ${WWW_SYSFILES} \
			${DESTDIR}${PREFIX}/${TL_WEBDIR}/system; \
		${INSTALL_DATA} config/.htaccess \
			${DESTDIR}${PREFIX}/${TL_WEBDIR}/system/config
	cd ${WRKSRC}; pax -rw ${EG_DATA} ${DESTDIR}${PREFIX}/${TL_EGDIR}
	rm -f ${DESTDIR}${PREFIX}/${TL_EGDIR}/system/config/.htaccess
	${INSTALL_DATA} ${WRKDIR}/typolight.conf ${DESTDIR}${PREFIX}/${TL_EGDIR}
	${INSTALL_DATA} ${WRKDIR}/templates-htaccess \
		${DESTDIR}${PREFIX}/${TL_EGDIR}
	${INSTALL_DATA} ${FILESDIR}/README \
		${DESTDIR}${PREFIX}/${TL_DOCDIR}

.include "Makefile.version"
.include "../../www/typolight/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
