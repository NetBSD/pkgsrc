# $NetBSD: Makefile,v 1.51.2.1 2008/01/15 08:50:16 ghen Exp $

DISTNAME=	horde-3.1.6
CATEGORIES=	www
MASTER_SITES=	http://ftp.horde.org/pub/horde/ \
		ftp://ftp.horde.org/pub/horde/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.horde.org/
COMMENT=	PHP application framework

CONFLICTS+=	horde-2.*

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=4.3.3:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=4.3.3:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=4.3.3:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.3:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Log-[0-9]*:../../sysutils/pear-Log
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime-[0-9]*:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-DB-[0-9]*:../../databases/pear-DB
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.3:../../www/ap-php
.if ${PKG_PHP_VERSION} == "4"
DEPENDS+=	${PHP_PKG_PREFIX}-domxml>=4.3.3:../../textproc/php4-domxml
.elif ${PKG_PHP_VERSION} == "5"
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php5-dom
.endif
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=4.3.3:../../archivers/php-zlib

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/horde
EGDIR=		${PREFIX}/share/examples/horde
HORDEDIR=	${PREFIX}/share/horde
PAXDIRS=	js lib locale po scripts services templates themes util admin
SENDMAIL?=	/usr/sbin/sendmail
PKG_USERS_VARS+=APACHE_USER

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		HORDEDIR=${HORDEDIR:Q}

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*/bin/php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	po/translation.php \
			scripts/count_sessions.php \
			scripts/create-symlinks.php \
			scripts/remove_prefs.php \
			scripts/upgrades/migrate_user_categories.php \
			scripts/upgrades/move_history_out_of_datatree.php

CONF_FILES+=		${EGDIR}/horde.conf ${PKG_SYSCONFDIR}/horde.conf
CONF_FILES_PERMS+=	${HORDEDIR}/config/conf.php.dist \
			${HORDEDIR}/config/conf.php \
			${APACHE_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${HORDEDIR}/config/conf.xml.dist \
			${HORDEDIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${HORDEDIR}/config/mime_drivers.php.dist \
			${HORDEDIR}/config/mime_drivers.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${HORDEDIR}/config/motd.php.dist \
			${HORDEDIR}/config/motd.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${HORDEDIR}/config/nls.php.dist \
			${HORDEDIR}/config/nls.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${HORDEDIR}/config/prefs.php.dist \
			${HORDEDIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${HORDEDIR}/config/registry.php.dist \
			${HORDEDIR}/config/registry.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${HORDEDIR}/config/hooks.php.dist \
			${HORDEDIR}/config/hooks.php \
			${APACHE_USER} ${ROOT_GROUP} 0440

# Empty directories installed by install target
# that we need to create in the install script
# to get the same layout from a binary package installation
REQD_DIRS+=	share/horde/lib/data
REQD_DIRS+=	share/horde/lib/XML/tests
REQD_DIRS+=	share/horde/lib/XML/docs/examples
REQD_DIRS+=	share/horde/lib/XML/docs
REQD_DIRS+=	share/horde/lib/VFS/tests
REQD_DIRS+=	share/horde/lib/Text/tests
REQD_DIRS+=	share/horde/lib/Text/docs/examples
REQD_DIRS+=	share/horde/lib/Text/docs
REQD_DIRS+=	share/horde/lib/Horde/tests
REQD_DIRS+=	share/horde/lib/Horde/docs/examples
REQD_DIRS+=	share/horde/lib/Horde/docs
REQD_DIRS+=	share/horde/lib/Horde/Text/tests
REQD_DIRS+=	share/horde/lib/File/tests

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	horde.conf.dist config/conf.xml config/conf.xml.dist \
			scripts/set_perms.sh
SUBST_SED.files=	-e "s|@HORDEDIR@|${HORDEDIR}|g"
SUBST_SED.files+=	-e "s|/usr/lib/sendmail|${SENDMAIL}|g"
SUBST_SED.files+=	-e "s|/bin/sh|${SH}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

.include "options.mk"
.include "../../mk/apache.mk"

do-build:
	${RM} ${WRKSRC}/lib/Horde/Auth/login.php.orig
	${CP} ${FILESDIR}/horde.conf.dist ${WRKSRC}/horde.conf.dist
	${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f
	${CHMOD} 0750 ${WRKSRC}/scripts/set_perms.sh

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${HORDEDIR}
	${INSTALL_DATA_DIR} ${HORDEDIR}/config
	${INSTALL_DATA} ${WRKSRC}/horde.conf.dist ${EGDIR}/horde.conf
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}

.	for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${HORDEDIR}/${d}
.	endfor

.	for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && ${PAX} -rwpam . ${HORDEDIR}/${d}
.	endfor

	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${HORDEDIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${HORDEDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HORDEDIR}
	${FIND} ${HORDEDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${HORDEDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${CHOWN} ${APACHE_USER}:${SHAREGRP} ${HORDEDIR}/config
	${CHMOD} 0750 ${HORDEDIR}/config

.include "../../mk/apachever.mk"
.include "../../mk/bsd.pkg.mk"
