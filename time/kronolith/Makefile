# $NetBSD: Makefile,v 1.21 2013/03/16 07:21:23 obache Exp $

DISTNAME=	kronolith-h3-${KRONOLITHVER}
PKGNAME=	kronolith-${KRONOLITHVER}
PKGREVISION=	1
CATEGORIES=	www time
MASTER_SITES=	http://ftp.horde.org/pub/kronolith/ \
		ftp://ftp.horde.org/pub/kronolith/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.horde.org/kronolith/
COMMENT=	Horde calendar application
LICENSE=	gnu-gpl-v2

DEPENDS+=	horde>=3.2:../../www/horde
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Date-[0-9]*:../../time/pear-Date

USE_TOOLS+=	pax

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/kronolith
EGDIR=		${PREFIX}/share/examples/kronolith
HORDEDIR=	${PREFIX}/share/horde
KRONOLITHDIR=	${HORDEDIR}/kronolith
KRONOLITHVER=	2.3.6
PAXDIRS=	js lib locale po scripts templates themes

INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${KRONOLITHDIR}/config
INSTALLATION_DIRS+=	${PAXDIRS:=${KRONOLITHDIR}/%}

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*/bin.php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	scripts/import_icals.php \
			scripts/migrate_to_sql_driver.php \
			scripts/reminders.php

MESSAGE_SUBST+=	KRONOLITHDIR=${KRONOLITHDIR:Q}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR?=	httpd
USE_PKGINSTALL=		YES

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	kronolith.conf.dist
SUBST_SED.files=	-e "s|@KRONOLITHDIR@|${KRONOLITHDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

PKG_USERS_VARS+=	APACHE_USER

CONF_FILES=		${EGDIR}/kronolith.conf ${PKG_SYSCONFDIR}/kronolith.conf
CONF_FILES_PERMS+=	${KRONOLITHDIR}/config/conf.xml.dist \
			${KRONOLITHDIR}/config/conf.xml \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${KRONOLITHDIR}/config/keywords.php.dist \
			${KRONOLITHDIR}/config/keywords.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${KRONOLITHDIR}/config/menu.php.dist \
			${KRONOLITHDIR}/config/menu.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${KRONOLITHDIR}/config/prefs.php.dist \
			${KRONOLITHDIR}/config/prefs.php \
			${APACHE_USER} ${ROOT_GROUP} 0440
SPECIAL_PERMS+=		${KRONOLITHDIR}/config ${APACHE_USER} ${SHAREGRP} 0750

do-build:
	${CP} ${FILESDIR}/kronolith.conf.dist ${WRKSRC}/kronolith.conf.dist
	${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA} ${WRKSRC}/kronolith.conf.dist ${DESTDIR}${EGDIR}/kronolith.conf
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/RELEASE_NOTES ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/UPGRADING ${DESTDIR}${DOCDIR}

.	for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && pax -rwpma . ${DESTDIR}${KRONOLITHDIR}/${d}
.	endfor

	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${DESTDIR}${KRONOLITHDIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${KRONOLITHDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${KRONOLITHDIR}
	${FIND} ${DESTDIR}${KRONOLITHDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${KRONOLITHDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
