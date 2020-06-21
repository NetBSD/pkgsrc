# $NetBSD: Makefile,v 1.19 2020/06/21 16:42:55 taca Exp $

DISTNAME=		wordpress-${VERSION}-ja
PKGNAME=		${PHP_PKG_PREFIX}-ja-wordpress-${VERSION}
VERSION=		5.4.2
CATEGORIES=		www
MASTER_SITES=		https://ja.wordpress.org/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://ja.wordpress.org/
COMMENT=		Blogging tool written in php (Localized for Japanese)
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		pax

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"
.include "options.mk"

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/wordpress

WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}

PKG_GROUPS_VARS=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER
BUILD_DEFS+=		WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP
EGDIR=			${PREFIX}/share/examples/ja-wordpress
DOCDIR=			${PREFIX}/share/doc/ja-wordpress
WPHOME=			${PREFIX}/share/ja-wordpress
FILES_SUBST+=		WPHOME=${WPHOME}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

CONF_FILES+=		${EGDIR}/ja-wordpress.conf ${PKG_SYSCONFDIR}/ja-wordpress.conf
CONF_FILES_PERMS+=	${EGDIR}/wp-config-sample.php ${WPHOME}/wp-config.php \
			${WWW_USER} ${WWW_GROUP} 0640
OWN_DIRS_PERMS+=	${WPHOME}/wp-content/uploads \
			${WWW_USER} ${WWW_GROUP} 0750

INSTALLATION_DIRS+=	${DOCDIR} ${WPHOME} ${EGDIR}

DEPENDS+=		${PHP_PKG_PREFIX}-mysqli>=5.6.20:../../databases/php-mysqli
DEPENDS+=		${PHP_PKG_PREFIX}-gd>=5.6.20:../../graphics/php-gd
DEPENDS+=		${PHP_PKG_PREFIX}-curl>=5.6.20:../../www/php-curl
DEPENDS+=		${PHP_PKG_PREFIX}-zip>=5.6.20:../../archivers/php-zip
DEPENDS+=		${PHP_PKG_PREFIX}-zlib>=5.6.20:../../archivers/php-zlib

SUBST_CLASSES+=		conf
SUBST_MESSAGE.conf=	Fixing pathnames in configuration file.
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	../ja-wordpress.conf
SUBST_VARS.conf=	WPHOME
.if !empty(PKG_OPTIONS:Map-php) && ${PKG_APACHE} == "apache24"
SUBST_SED.conf+=	-e "/Order allow,deny/d"
SUBST_SED.conf+=	-e "s,Allow from all,Require all granted,g"
.endif

post-extract:
	${CP} ${FILESDIR}/wordpress.conf ${WRKDIR}/ja-wordpress.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/wp-config-sample.php ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/ja-wordpress.conf ${DESTDIR}${EGDIR}

	${RM} ${WRKSRC}/readme.html
	${RM} ${WRKSRC}/license.txt
	${RM} ${WRKSRC}/wp-config-sample.php

	cd ${WRKSRC} && pax -rw -pmp . ${DESTDIR}${WPHOME}
	${TOUCH} ${DESTDIR}${WPHOME}/wp-content/plugins/index.html
	${FIND} ${DESTDIR}${WPHOME} \
		-type d -exec ${CHMOD} ${PKGDIRMODE} "{}" \;
	${FIND} ${DESTDIR}${WPHOME} \
		-type f -exec ${CHMOD} ${SHAREMODE} "{}" \;

.include "../../mk/bsd.pkg.mk"
