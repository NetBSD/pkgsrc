# $NetBSD: Makefile,v 1.80 2024/02/28 15:34:32 taca Exp $

DISTNAME=	drupal-7.99
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://ftp.drupal.org/files/projects/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drupal.org/
COMMENT=	Open source content management system
LICENSE=	gnu-gpl-v2

PHP_VERSIONS_ACCEPTED=	56 74 81 82

.include "../../lang/php/phpversion.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.4.0:../../graphics/php-gd
.if ${PKG_PHP_MAJOR_VERS} < 8
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.4.0:../../textproc/php-json
.endif

NO_BUILD=	YES
DRUPAL=		share/drupal
PAX_DIRS=	includes misc modules profiles scripts themes
DOCS=		CHANGELOG.txt COPYRIGHT.txt INSTALL.mysql.txt \
		INSTALL.pgsql.txt INSTALL.sqlite.txt INSTALL.txt LICENSE.txt \
		MAINTAINERS.txt README.txt UPGRADE.txt

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS+=	WWW_USER

BUILD_DEFS+=		WWW_USER WWW_GROUP
USE_TOOLS+=		pax

OWN_DIRS_PERMS+=	${DRUPAL}/sites/default \
			${WWW_USER} ${WWW_GROUP} 0750

CONF_FILES=	share/examples/drupal/drupal.conf \
		${PKG_SYSCONFDIR}/drupal.conf \
		share/examples/drupal/default.settings.php \
		${DRUPAL}/sites/default/default.settings.php

CONF_FILES_PERMS+=	share/examples/drupal/default.settings.php \
			${DRUPAL}/sites/default/settings.php \
			${WWW_USER} ${WWW_GROUP} 0640

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	scripts/drupal.sh scripts/password-hash.sh
REPLACE_FILES.php+=	scripts/dump-database-d6.sh
REPLACE_FILES.php+=	scripts/dump-database-d7.sh
REPLACE_FILES.php+=	scripts/generate-d6-content.sh
REPLACE_FILES.php+=	scripts/generate-d7-content.sh

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	drupal.conf
SUBST_VARS.conf=	DRUPAL PREFIX
SUBST_MESSAGE.conf=	Fixing configuration files.

INSTALLATION_DIRS+=	${DRUPAL}/files ${DRUPAL}/sites \
			share/doc/drupal share/examples/drupal
.for i in ${PAX_DIRS}
INSTALLATION_DIRS+=	${DRUPAL}/${i}
.endfor

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/drupal.conf ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${PREFIX}/${DRUPAL}
	${INSTALL_DATA} ${WRKSRC}/drupal.conf \
		${DESTDIR}${PREFIX}/share/examples/drupal
	${INSTALL_DATA} ${WRKSRC}/sites/default/default.settings.php \
		${DESTDIR}${PREFIX}/share/examples/drupal
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${PREFIX}/${DRUPAL}
.for i in ${PAX_DIRS}
	cd ${WRKSRC}/${i} && ${PAX} -rw . ${DESTDIR}${PREFIX}/${DRUPAL}/${i}
.endfor
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/drupal
.endfor

post-install:
	${FIND} ${DESTDIR}${PREFIX}/${DRUPAL} \
		\( -name '*.jpg' -o -name '*.png' \) | ${XARGS} ${CHMOD} 0644

.include "../../mk/bsd.pkg.mk"
