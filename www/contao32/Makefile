# $NetBSD: Makefile,v 1.2 2013/12/21 02:46:25 taca Exp $
#

DISTNAME=	${CT_VERSION}
PKGNAME=	contao${CT_VER}-${CT_PKGVER}
CATEGORIES=	www
MASTER_SITES=	${CT_MASTER_SITE}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.contao.org/
COMMENT=	Contao Open Source CMS ${CT_VERSION}
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.2.0:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.2.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.2.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-{mysql,mysqli}>=5.2.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.2.0:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=5.2.0:../../net/php-soap

CT_VERS=	32
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

REPLACE_BASH=	system/bin/minify

.for f in ${EG_TEMPLATES}
REQD_FILES+=	${CT_EGDIR}/files/${f} ${CT_WEBDIR}/tl_files/${f}
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
REPLACE_FILES.php=	system/bin/ide_compat

SUBST_CLASSES+=		conf
SUBST_FILES.conf+=	${WRKDIR}/contao.conf
SUBST_SED.conf+=        -e 's|@PREFIX@|${PREFIX:Q}|g'
SUBST_SED.conf+=        -e 's|@CT_WEBDIR@|${CT_WEBDIR:Q}|g'
SUBST_STAGE.conf=	post-configure

SUBST_CLASSES+=		php
SUBST_FILES.php+=	${WRKSRC}/system/bin/transifex
SUBST_SED.php+=		-e "s|\#!/.*php|\#!${PREFIX}/bin/php|"
SUBST_STAGE.php=	post-configure

WWW_FILES=	.gitignore .htaccess.default README.md assets contao \
		index.php share templates
WWW_SYSFILES=	.htaccess bin config/default.php cron docs helper \
		initialize.php modules themes

INSTALLATION_DIRS+=	${CT_DOCDIR} ${CT_EGDIR} ${CT_WEBDIR}/system/config

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

pre-configure:
	cd ${WRKSRC} && ${RM} -f assets/css/*.css
	${CP} ${FILESDIR}/contao.conf ${WRKDIR}

pre-install:
	cd ${WRKSRC}; ${RM} -fr files/music_academy templates/music_academy.sql
	${FIND} ${WRKSRC} -name "*.orig*" -exec ${RM} -f {} \;
	cd ${WRKSRC}/assets && \
		${FIND} ace html5shiv jquery/ui -type f -exec chmod -x {} \;

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
