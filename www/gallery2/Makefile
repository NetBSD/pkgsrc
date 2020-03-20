# $NetBSD: Makefile,v 1.18 2020/03/20 11:58:34 nia Exp $
#

DISTNAME=		gallery-2.3.2-full
PKGNAME=		gallery-2.3.2
PKGREVISION=		1
CATEGORIES=		www graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gallery/}

MAINTAINER=		pettai@NetBSD.org
HOMEPAGE=		http://gallery.sourceforge.net/
COMMENT=		Web-based photo gallery written in PHP
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PHP_PKG_PREFIX}-gd>=5.0.4:../../graphics/php-gd
DEPENDS+=		${PHP_PKG_PREFIX}-gettext>=5.0.4:../../devel/php-gettext
DEPENDS+=		${PHP_PKG_PREFIX}-{mysql,pgsql}-[0-9]*:../../databases/php-mysql

PHP_VERSIONS_ACCEPTED=	56

USE_TOOLS=		pax
USE_LANGUAGES=		# none

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/gallery2

REPLACE_PERL=		lib/tools/po/*.pl

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*/bin/php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	lib/tools/po/extract.php

PKG_SYSCONFSUBDIR=	gallery2

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/gallery2
G2DIR=			${PREFIX}/share/gallery2
DATADIR=		${VARBASE}/gallery2
G2DATA=			${DATADIR}/g2data

CONF_FILES=		${EGDIR}/gallery2.conf \
			${PKG_SYSCONFDIR}/gallery2.conf

CONF_FILES_PERMS+=	${EGDIR}/config.php \
			${G2DIR}/config.php \
			${APACHE_USER} ${APACHE_GROUP} 0640

MESSAGE_SUBST+=		G2DIR=${G2DIR:Q}
MESSAGE_SUBST+=		G2DATA=${G2DATA:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
FILES_SUBST+=		G2DIR=${G2DIR:Q}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/gallery2.conf
SUBST_FILES.paths+=	${WRKDIR}/config.php
SUBST_VARS.paths+=	G2DIR G2DATA
SUBST_STAGE.paths=	pre-configure

OWN_DIRS_PERMS+=	${G2DATA} ${APACHE_USER} ${APACHE_GROUP} 755

INSTALLATION_DIRS=	share/examples/gallery2
INSTALLATION_DIRS+=	share/gallery2

post-extract:
	${CP} ${FILESDIR}/gallery2.conf ${WRKDIR}/
	${CP} ${FILESDIR}/config.php ${WRKDIR}/

do-install:
	${INSTALL_DATA} ${WRKDIR}/gallery2.conf ${DESTDIR}${EGDIR}/gallery2.conf
	${INSTALL_DATA} ${WRKDIR}/config.php ${DESTDIR}${EGDIR}/config.php
	${INSTALL_DATA} ${FILESDIR}/.htaccess ${DESTDIR}${G2DIR}/.htaccess
	cd ${WRKSRC} && ${PAX} -rwppm . ${DESTDIR}${G2DIR}/

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
