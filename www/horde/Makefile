# $NetBSD: Makefile,v 1.76 2013/03/16 07:21:25 obache Exp $

DISTNAME=	horde-3.3.13
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.horde.org/pub/horde/ \
		ftp://ftp.horde.org/pub/horde/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.horde.org/
COMMENT=	PHP application framework
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	horde-2.*{,nb*}

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=4.3.3:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=4.3.3:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=4.3.3:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.3:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Log-[0-9]*:../../sysutils/pear-Log
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime-[0-9]*:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-DB-[0-9]*:../../databases/pear-DB
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.3:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=4.3.3:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Console_Table-[0-9]*:../../textproc/pear-Console_Table
DEPENDS+=	${PHP_PKG_PREFIX}-pear-File_Find-[0-9]*:../../textproc/pear-File_Find
DEPENDS+=	${PHP_PKG_PREFIX}-pear-HTTP_Request-[0-9]*:../../www/pear-HTTP_Request

USE_TOOLS+=	pax

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/horde
EGDIR=		${PREFIX}/share/examples/horde
HORDEDIR=	${PREFIX}/share/horde
PAXDIRS=	js lib locale po scripts services templates themes util admin \
		rpc
SENDMAIL?=	/usr/sbin/sendmail
PKG_USERS_VARS+=APACHE_USER

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		HORDEDIR=${HORDEDIR}

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*/bin/php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	po/translation.php \
			scripts/upgrades/migrate_user_categories.php \
			scripts/upgrades/move_history_out_of_datatree.php \
			scripts/alarms.php \
			scripts/import_squirrelmail_prefs.php \
			scripts/upgrades/convert_datatree_groups_to_sql.php \
			scripts/upgrades/convert_datatree_perms_to_sql.php \
			scripts/import_squirrelmail_file_prefs.php \
			scripts/import_squirrelmail_sql_prefs.php

CONF_FILES+=		${EGDIR}/horde.conf ${PKG_SYSCONFDIR}/horde.conf
OWN_DIRS_PERMS+=	${HORDEDIR}/config \
			${APACHE_USER} ${ROOT_GROUP} 0750
CONF_FILES_PERMS+=	${EGDIR}/config/conf.php \
			${HORDEDIR}/config/conf.php \
			${APACHE_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/config/conf.xml \
			${HORDEDIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${EGDIR}/config/mime_drivers.php \
			${HORDEDIR}/config/mime_drivers.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${EGDIR}/config/motd.php \
			${HORDEDIR}/config/motd.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${EGDIR}/config/nls.php \
			${HORDEDIR}/config/nls.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${EGDIR}/config/prefs.php \
			${HORDEDIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${EGDIR}/config/registry.php \
			${HORDEDIR}/config/registry.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${EGDIR}/config/hooks.php \
			${HORDEDIR}/config/hooks.php \
			${APACHE_USER} ${ROOT_GROUP} 0440

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

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}/config ${HORDEDIR}/config

do-install:
	${INSTALL_DATA} ${WRKSRC}/horde.conf.dist ${DESTDIR}${EGDIR}/horde.conf
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${DOCDIR}
.for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${DESTDIR}${HORDEDIR}/${d}
.endfor
.for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && pax -rwpam . ${DESTDIR}${HORDEDIR}/${d}
.endfor
	cd ${WRKSRC}/config && for f in *.dist; do \
		${INSTALL_DATA} $$f ${DESTDIR}${EGDIR}/config/$${f%.dist}; \
	done
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${HORDEDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${HORDEDIR}
	${FIND} ${DESTDIR}${HORDEDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${HORDEDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
