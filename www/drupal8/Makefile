# $NetBSD: Makefile,v 1.34 2020/06/21 16:48:44 taca Exp $

DISTNAME=	drupal-8.9.1
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drupal.org/
COMMENT=	Open source content management system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.4.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.4.0:../../textproc/php-json

PHP_VERSIONS_ACCEPTED=	73 74

NO_BUILD=	YES
DRUPAL=		share/drupal
PAX_DIRS=	includes misc modules profiles scripts themes

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
REPLACE_FILES.php=	core/scripts/drupal.sh core/scripts/password-hash.sh
REPLACE_FILES.php+=	core/scripts/update-countries.sh
REPLACE_FILES.php+=	core/scripts/rebuild_token_calculator.sh
REPLACE_FILES.php+=	vendor/pear/archive_tar/scripts/phptar.in

REPLACE_SH+=		core/tests/Drupal/Tests/Composer/Plugin/Scaffold/fixtures/scripts/disable-git-bin/git
REPLACE_SH+=		vendor/paragonie/random_compat/build-phar.sh
REPLACE_SH+=		vendor/twig/twig/drupal_test.sh

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
	${CHMOD} 0644 ${WRKSRC}/core/scripts/run-tests.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${PREFIX}/${DRUPAL}
	${INSTALL_DATA} ${WRKSRC}/drupal.conf \
		${DESTDIR}${PREFIX}/share/examples/drupal
	${INSTALL_DATA} ${WRKSRC}/sites/default/default.settings.php \
		${DESTDIR}${PREFIX}/share/examples/drupal

	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/${DRUPAL}


.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
