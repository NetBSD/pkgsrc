# $NetBSD: Makefile,v 1.44.2.1 2014/02/04 21:33:04 tron Exp $

DISTNAME=	drupal-6.30
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drupal.org/
COMMENT=	Open source content management system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.5:../../graphics/php-gd

NO_BUILD=	YES
DRUPAL=		share/drupal
PAX_DIRS=	includes misc modules scripts themes
DOCS=		CHANGELOG.txt COPYRIGHT.txt INSTALL.mysql.txt \
		INSTALL.pgsql.txt INSTALL.txt LICENSE.txt \
		MAINTAINERS.txt UPGRADE.txt

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS+=	WWW_USER

BUILD_DEFS+=		WWW_USER WWW_GROUP
USE_TOOLS+=		perl:run pax
REPLACE_PERL=		scripts/code-style.pl

OWN_DIRS_PERMS+=	${DRUPAL}/sites/default \
			${WWW_USER} ${WWW_GROUP} 0750
OWN_DIRS_PERMS+=	${DRUPAL}/files \
			${WWW_USER} ${WWW_GROUP} 0750

CONF_FILES=	share/examples/drupal/drupal.conf \
		${PKG_SYSCONFDIR}/drupal.conf \
		share/examples/drupal/default.profile \
		${DRUPAL}/profiles/default/default.profile \
		share/examples/drupal/default.settings.php \
		${DRUPAL}/sites/default/default.settings.php

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	scripts/drupal.sh

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	drupal.conf
SUBST_SED.conf=		-e "s|@DRUPAL@|${DRUPAL}|g"
SUBST_SED.conf+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

INSTALLATION_DIRS+=	${DRUPAL}/files ${DRUPAL}/sites/all \
			share/doc/drupal share/examples/drupal
.for i in ${PAX_DIRS}
INSTALLATION_DIRS+=	${DRUPAL}/${i}
.endfor

.include "options.mk"

OWN_DIRS=	share/drupal/sites/default
OWN_DIRS+=	share/drupal/profiles
OWN_DIRS+=	share/drupal/profiles/default

post-extract:
	${CP} ${FILESDIR}/drupal.conf ${WRKSRC}

pre-install:
	${FIND} ${WRKSRC} -type f -name "*.orig" -exec ${RM} -f {} \;

do-install:
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${PREFIX}/${DRUPAL}
	${INSTALL_DATA} ${WRKSRC}/sites/all/README.txt \
		${DESTDIR}${PREFIX}/${DRUPAL}/sites/all
	${INSTALL_DATA} ${WRKSRC}/drupal.conf \
		${DESTDIR}${PREFIX}/share/examples/drupal
	${INSTALL_DATA} ${WRKSRC}/sites/default/default.settings.php \
		${DESTDIR}${PREFIX}/share/examples/drupal
	${INSTALL_DATA} ${WRKSRC}/profiles/default/default.profile \
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

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
