# $NetBSD: Makefile,v 1.3 2025/02/03 00:01:37 taca Exp $

DISTNAME=	drupal-11.1.0
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://ftp-origin.drupal.org/files/projects/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drupal.org/
COMMENT=	Open source content management system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=8.3.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-opcache>=8.3.0:../../devel/php-opcache
DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=8.3.0:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=8.3.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=8.3.0:../../archivers/php-zlib

PHP_VERSIONS_ACCEPTED=	83 # 84

NO_BUILD=	YES
DRUPAL=		share/drupal
PAX_DIRS=	includes misc modules profiles scripts themes

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS+=	WWW_USER

BUILD_DEFS+=		WWW_USER WWW_GROUP
USE_TOOLS+=		bash:run pax

OWN_DIRS_PERMS+=	${DRUPAL}/sites/default \
			${WWW_USER} ${WWW_GROUP} 0750

CONF_FILES=	share/examples/drupal/drupal.conf \
		${PKG_SYSCONFDIR}/drupal.conf \
		share/examples/drupal/default.settings.php \
		${DRUPAL}/sites/default/default.settings.php

CONF_FILES_PERMS+=	share/examples/drupal/default.settings.php \
			${DRUPAL}/sites/default/settings.php \
			${WWW_USER} ${WWW_GROUP} 0640

REPLACE_PHP+=	core/scripts/drupal.sh core/scripts/password-hash.sh
REPLACE_PHP+=	core/scripts/rebuild_token_calculator.sh
REPLACE_PHP+=	core/scripts/update-countries.sh
REPLACE_PHP+=	vendor/bin/var-dump-server
REPLACE_PHP+=	vendor/bin/patch-type-declarations
REPLACE_PHP+=	vendor/bin/yaml-lint
REPLACE_PHP+=	vendor/pear/archive_tar/scripts/phptar.in
REPLACE_PHP+=	vendor/symfony/error-handler/Resources/bin/extract-tentative-return-types.php
REPLACE_PHP+=	vendor/symfony/error-handler/Resources/bin/patch-type-declarations
REPLACE_PHP+=	vendor/symfony/var-dumper/Resources/bin/var-dump-server
REPLACE_PHP+=	vendor/symfony/yaml/Resources/bin/yaml-lint

REPLACE_BASH+=		core/scripts/dev/commit-code-check.sh

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

pre-configure:
	${CP} ${FILESDIR}/drupal.conf ${WRKSRC}
	${CHMOD} 0644 ${WRKSRC}/core/scripts/run-tests.sh
	${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} -f {} \;

do-install:
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${PREFIX}/${DRUPAL}
	${INSTALL_DATA} ${WRKSRC}/drupal.conf \
		${DESTDIR}${PREFIX}/share/examples/drupal
	${INSTALL_DATA} ${WRKSRC}/sites/default/default.settings.php \
		${DESTDIR}${PREFIX}/share/examples/drupal

	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/${DRUPAL}


.include "../../lang/php/replace.mk"
.include "../../lang/php/json.mk"
.include "../../mk/bsd.pkg.mk"
