# $NetBSD: Makefile,v 1.5.4.1 2008/08/16 12:28:51 rtr Exp $

DISTNAME=	drupal-6.4
CATEGORIES=	www
MASTER_SITES=	http://drupal.org/files/projects/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://drupal.org/
COMMENT=	Open source content management system

CONFLICTS+=	drupal-5.*{,nb*}

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.5:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.5:../../graphics/php-gd

NO_BUILD=	YES
DRUPAL=		${PREFIX}/share/drupal
PAX_DIRS=	includes misc modules scripts themes
DOCS=		CHANGELOG.txt COPYRIGHT.txt INSTALL.mysql.txt \
		INSTALL.pgsql.txt INSTALL.txt LICENSE.txt \
		MAINTAINERS.txt UPGRADE.txt

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

BUILD_DEFS+=		APACHE_USER APACHE_GROUP
USE_TOOLS+=		perl:run pax
REPLACE_PERL=		scripts/code-style.pl

OWN_DIRS_PERMS+=	${DRUPAL}/sites/default \
			${APACHE_USER} ${APACHE_GROUP} 0750
OWN_DIRS_PERMS+=	${DRUPAL}/files \
			${APACHE_USER} ${APACHE_GROUP} 0750

CONF_FILES=	${PREFIX}/share/examples/drupal/drupal.conf \
		${PKG_SYSCONFDIR}/drupal.conf
CONF_FILES+=	${PREFIX}/share/examples/drupal/default.profile \
		${DRUPAL}/profiles/default/default.profile

CONF_FILES_PERMS+=	${PREFIX}/share/examples/drupal/default.settings.php \
			${DRUPAL}/sites/default/default.settings.php \
			${APACHE_USER} ${APACHE_GROUP} 0640

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	drupal.conf scripts/drupal.sh
SUBST_SED.conf=		-e "s|@DRUPAL@|${DRUPAL}|g"
SUBST_SED.conf+=	-e "s|/usr/bin/php|${PREFIX}/bin/php|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} == "4"
DEPENDS+=	php>=4.3.5:../../www/php4
.endif

.if ${PKG_PHP_VERSION} == "5"
DEPENDS+=	php>=5.2.0:../../lang/php5
.endif

.include "options.mk"

OWN_DIRS=	share/drupal/sites/default
OWN_DIRS+=	share/drupal/profiles
OWN_DIRS+=	share/drupal/profiles/default

post-extract:
	${CP} ${FILESDIR}/drupal.conf ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DRUPAL}
	${INSTALL_DATA_DIR} ${DRUPAL}/files
	${INSTALL_DATA_DIR} ${DRUPAL}/sites
	${INSTALL_DATA_DIR} ${DRUPAL}/sites/all
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/drupal
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/drupal

	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DRUPAL}
	${INSTALL_DATA} ${WRKSRC}/sites/all/README.txt ${DRUPAL}/sites/all
	${INSTALL_DATA} ${WRKSRC}/drupal.conf \
		${PREFIX}/share/examples/drupal/drupal.conf
	${INSTALL_DATA} ${WRKSRC}/sites/default/default.settings.php \
		${PREFIX}/share/examples/drupal/default.settings.php
	${INSTALL_DATA} ${WRKSRC}/profiles/default/default.profile \
		${PREFIX}/share/examples/drupal/default.profile
	${INSTALL_DATA} ${WRKSRC}/*.php ${DRUPAL}

.	for i in ${PAX_DIRS}
		cd ${WRKSRC}/${i} && pax -rw . ${DRUPAL}/${i}
.	endfor

.	for i in ${DOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/drupal
.	endfor

	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${DRUPAL}/files
	${CHMOD} 0770 ${DRUPAL}/files

post-install:
	${FIND} ${DRUPAL} -name \*.jpg | ${XARGS} ${CHMOD} 0644
	${FIND} ${DRUPAL} -name \*.png | ${XARGS} ${CHMOD} 0644

.include "../../mk/bsd.pkg.mk"
