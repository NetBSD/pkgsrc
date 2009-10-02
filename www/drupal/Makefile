# $NetBSD: Makefile,v 1.39.2.2 2009/10/02 09:52:28 tron Exp $

DISTNAME=	drupal-5.20
CATEGORIES=	www
MASTER_SITES=	http://drupal.org/files/projects/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drupal.org/
COMMENT=	Open source content management system
LICENSE=	gnu-gpl-v2

CONFLICTS+=	drupal-6.*{,nb*}

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.3:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.3:../../graphics/php-gd

NO_BUILD=	YES
DRUPAL=		${PREFIX}/share/drupal
PAX_DIRS=	includes misc modules scripts themes

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

BUILD_DEFS+=		APACHE_USER APACHE_GROUP
USE_TOOLS+=		perl:run pax
REPLACE_PERL=		scripts/code-style.pl

OWN_DIRS+=		${DRUPAL}/sites/default
OWN_DIRS_PERMS+=	${DRUPAL}/files ${APACHE_USER} ${APACHE_GROUP} 0750

CONF_FILES=	${PREFIX}/share/examples/drupal/drupal.conf \
		${PKG_SYSCONFDIR}/drupal.conf
CONF_FILES+=	${PREFIX}/share/examples/drupal/default.profile \
		${DRUPAL}/profiles/default/default.profile

CONF_FILES_PERMS+=	${PREFIX}/share/examples/drupal/settings.php \
			${DRUPAL}/sites/default/settings.php \
			${APACHE_USER} ${APACHE_GROUP} 0640

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	drupal.conf
SUBST_SED.conf=		-e "s|@DRUPAL@|${DRUPAL}|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} == "4"
DEPENDS+=	php>=4.4.7:../../www/php4
.endif

.if ${PKG_PHP_VERSION} == "5"
DEPENDS+=	php>=5.2.4:../../lang/php5
.endif

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/drupal.conf ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DRUPAL}
	${INSTALL_DATA_DIR} ${DRUPAL}/files
	${INSTALL_DATA_DIR} ${DRUPAL}/profiles
	${INSTALL_DATA_DIR} ${DRUPAL}/profiles/default
	${INSTALL_DATA_DIR} ${DRUPAL}/sites
	${INSTALL_DATA_DIR} ${DRUPAL}/sites/all
	${INSTALL_DATA_DIR} ${DRUPAL}/sites/default
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/drupal
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/drupal
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/drupal
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DRUPAL}
	${INSTALL_DATA} ${WRKSRC}/sites/all/README.txt \
		${DRUPAL}/sites/all
	${INSTALL_DATA} ${WRKSRC}/drupal.conf \
		${PREFIX}/share/examples/drupal/drupal.conf
	${INSTALL_DATA} ${WRKSRC}/sites/default/settings.php \
		${PREFIX}/share/examples/drupal/settings.php
	${INSTALL_DATA} ${WRKSRC}/profiles/default/default.profile \
		${PREFIX}/share/examples/drupal/default.profile
	${INSTALL_DATA} ${WRKSRC}/*.php ${DRUPAL}

.	for i in ${PAX_DIRS}
		cd ${WRKSRC}/${i} && pax -rw . ${DRUPAL}/${i}
.	endfor

	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${DRUPAL}/files
	${CHMOD} 0770 ${DRUPAL}/files

post-install:
	${FIND} ${DRUPAL} -name \*.jpg | ${XARGS} ${CHMOD} 0644
	${FIND} ${DRUPAL} -name \*.png | ${XARGS} ${CHMOD} 0644

.include "../../mk/bsd.pkg.mk"
