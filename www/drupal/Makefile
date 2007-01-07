# $NetBSD: Makefile,v 1.16.2.1 2007/01/07 03:47:37 salo Exp $

DISTNAME=	drupal-4.7.5
CATEGORIES=	www
MASTER_SITES=	http://drupal.org/files/projects/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://drupal.org/
COMMENT=	Open source content management system

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.3:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.3:../../graphics/php-gd

NO_BUILD=	YES
DRUPAL=		${PREFIX}/share/drupal
PAX_DIRS=	database includes misc modules scripts themes
BUILD_DEFS+=	APACHE_USER APACHE_GROUP

CONF_FILES=	${PREFIX}/share/examples/drupal/drupal.conf \
		${PKG_SYSCONFDIR}/drupal.conf

CONF_FILES_PERMS+=	${PREFIX}/share/examples/drupal/settings.php \
			${DRUPAL}/sites/default/settings.php \
			${APACHE_USER} ${APACHE_GROUP} 0640

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	drupal.conf
SUBST_SED.conf=		-e "s|@DRUPAL@|${DRUPAL}|g"
SUBST_MESSAGE.conf=     Fixing configuration files.

.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/drupal.conf ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DRUPAL}
	${INSTALL_DATA_DIR} ${DRUPAL}/files
	${INSTALL_DATA_DIR} ${DRUPAL}/sites
	${INSTALL_DATA_DIR} ${DRUPAL}/sites/default
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/drupal
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/drupal

	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/drupal
	${INSTALL_DATA} ${WRKSRC}/drupal.conf \
		${PREFIX}/share/examples/drupal
	${INSTALL_DATA} ${WRKSRC}/sites/default/settings.php \
		${PREFIX}/share/examples/drupal
	${INSTALL_DATA} ${WRKSRC}/sites/default/settings.php \
		${DRUPAL}/sites/default/settings.php.example
	${INSTALL_DATA} ${WRKSRC}/*.php ${DRUPAL}

.	for i in ${PAX_DIRS}
		cd ${WRKSRC}/${i} && ${PAX} -rw . ${DRUPAL}/${i}
.	endfor

	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${DRUPAL}/files
	${CHMOD} 0770 ${DRUPAL}/files

post-install:
	${FIND} ${DRUPAL}/themes -name \*.jpg | ${XARGS} ${CHMOD} 0644
	${FIND} ${DRUPAL}/themes -name \*.png | ${XARGS} ${CHMOD} 0644

.include "../../mk/bsd.pkg.mk"
