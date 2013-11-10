# $NetBSD: Makefile,v 1.1 2013/11/10 11:13:08 ryoon Exp $

DISTNAME=		wordpress-${VERSION}-ja
PKGNAME=		${PHP_PKG_PREFIX}-ja-wordpress-${VERSION}
VERSION=		3.7.1
CATEGORIES=		www
MASTER_SITES=		http://ja.wordpress.org/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://ja.wordpress.org/
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
MESSAGE_SUBST+=		PKG_PHP_MAJOR_VERS=${PKG_PHP_MAJOR_VERS}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

CONF_FILES+=		${EGDIR}/ja-wordpress.conf ${PKG_SYSCONFDIR}/ja-wordpress.conf
CONF_FILES_PERMS+=	${EGDIR}/wp-config-sample.php ${WPHOME}/wp-config.php \
			${WWW_USER} ${WWW_GROUP} 0640
OWN_DIRS_PERMS+=	${WPHOME}/wp-content/uploads \
			${WWW_USER} ${WWW_GROUP} 0750

INSTALLATION_DIRS+=	${DOCDIR} ${WPHOME} ${EGDIR}

DEPENDS+=		${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql

do-configure:
	${SED} -e "s:@WPHOME@:${WPHOME}:g" <${FILESDIR}/wordpress.conf >${WRKDIR}/ja-wordpress.conf

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
