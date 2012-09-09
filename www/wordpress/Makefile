# $NetBSD: Makefile,v 1.26.2.1 2012/09/09 16:32:55 tron Exp $

DISTNAME=		wordpress-${VERSION}
VERSION=		3.4.2
CATEGORIES=		www
MASTER_SITES=		http://wordpress.org/

MAINTAINER=		morr@NetBSD.org
HOMEPAGE=		http://wordpress.org/
COMMENT=		Blogging tool written in php
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
EGDIR=			${PREFIX}/share/examples/wordpress
DOCDIR=			${PREFIX}/share/doc/wordpress
WPHOME=			${PREFIX}/share/wordpress
FILES_SUBST+=		WPHOME=${WPHOME}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

CONF_FILES+=		${EGDIR}/wordpress.conf ${PKG_SYSCONFDIR}/wordpress.conf
CONF_FILES_PERMS+=	${EGDIR}/wp-config-sample.php ${WPHOME}/wp-config.php \
			${WWW_USER} ${WWW_GROUP} 0640
OWN_DIRS_PERMS+=	${WPHOME}/wp-content/uploads \
			${WWW_USER} ${WWW_GROUP} 0750

INSTALLATION_DIRS+=	${DOCDIR} ${WPHOME} ${EGDIR}

DEPENDS+=		${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql

do-install:
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DESTDIR}${DOCDIR}

	${INSTALL_DATA} ${WRKSRC}/wp-config-sample.php ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/wordpress.conf ${DESTDIR}${EGDIR}

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
