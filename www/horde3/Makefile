# $NetBSD: Makefile,v 1.1.1.1 2005/01/16 21:10:17 adrianp Exp $

DISTNAME=	horde-3.0.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.horde.org/pub/horde/tarballs/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.horde.org/
COMMENT=	PHP application framework

CONFLICTS+=	horde-2.*

DEPENDS+=	php-gettext>=4.3.3:../../devel/php-gettext
DEPENDS+=	php-mcrypt>=4.3.3:../../security/php-mcrypt
DEPENDS+=	php-iconv>=4.3.3:../../converters/php-iconv
DEPENDS+=	php-gd>=4.3.3:../../graphics/php-gd
DEPENDS+=	pear-Log-[0-9]*:../../sysutils/pear-Log
DEPENDS+=	pear-Mail_Mime-[0-9]*:../../mail/pear-Mail_Mime
DEPENDS+=	ap-php>=4.3.3:../../www/ap-php
DEPENDS+=	php-domxml>=4.3.3:../../textproc/php4-domxml
DEPENDS+=	php-zlib>=4.3.3:../../archivers/php-zlib

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/horde
EGDIR=		${PREFIX}/share/examples/horde
HORDEDIR=	${PREFIX}/share/horde
PAXDIRS=	js lib locale po scripts services templates themes util admin
SENDMAIL?=      /usr/sbin/sendmail

USE_BUILDLINK3=		YES
PKG_SYSCONFSUBDIR?=	httpd
USE_PKGINSTALL=		YES
MESSAGE_SUBST+=		HORDEDIR=${HORDEDIR}

CONF_FILES+=		${EGDIR}/horde.conf ${PKG_SYSCONFDIR}/horde.conf
CONF_FILES_PERMS+=	${HORDEDIR}/config/conf.php.dist \
			${HORDEDIR}/config/conf.php \
			${APACHE_USER} ${ROOT_GROUP} 0640
SUPPORT_FILES_PERMS+=	${HORDEDIR}/config/conf.xml.dist \
			${HORDEDIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${HORDEDIR}/config/mime_drivers.php.dist \
			${HORDEDIR}/config/mime_drivers.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${HORDEDIR}/config/motd.php.dist \
			${HORDEDIR}/config/motd.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${HORDEDIR}/config/nls.php.dist \
			${HORDEDIR}/config/nls.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${HORDEDIR}/config/prefs.php.dist \
			${HORDEDIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${HORDEDIR}/config/registry.php.dist \
			${HORDEDIR}/config/registry.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SUPPORT_FILES_PERMS+=	${HORDEDIR}/config/hooks.php.dist \
			${HORDEDIR}/config/hooks.php \
			${APACHE_USER} ${ROOT_GROUP} 0000
SPECIAL_PERMS+=		${HORDEDIR}/config ${APACHE_USER} ${ROOT_GROUP} 0750

SUBST_CLASSES=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	horde.conf.dist config/conf.xml config/conf.xml.dist \
			scripts/set_perms.sh
SUBST_SED.files=	-e "s|@HORDEDIR@|${HORDEDIR}|g" \
			-e "s|/usr/lib/sendmail|${SENDMAIL}|g" \
			-e "s|/bin/sh|${SH}|g"
SUBST_MESSAGE.files=	"Fixing configuration files."

.include "options.mk"
.include "../../mk/apache.mk"

do-build:
	@${CP} ${FILESDIR}/horde.conf.dist ${WRKSRC}/horde.conf.dist
	@${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	@${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f
	@${CHMOD} 0750 ${WRKSRC}/scripts/set_perms.sh

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
.	undef d 

.	for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && ${PAX} -rw . ${HORDEDIR}/${d}
.	endfor
.	undef d 

	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${HORDEDIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${HORDEDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HORDEDIR}
	${CHMOD} -R a-w ${HORDEDIR}

.include "../../mk/bsd.pkg.mk"
