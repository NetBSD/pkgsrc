# $NetBSD: Makefile,v 1.49 2012/01/29 22:27:27 taca Exp $

DISTNAME=	drupal-5.22
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://drupal.org/files/projects/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drupal.org/
COMMENT=	Open source content management system
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.3:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.3:../../graphics/php-gd
.if ${PKG_PHP_VERSION} == "5"
DEPENDS+=	php>=5.2.4<5.3:../../lang/php5
.endif

NO_BUILD=	YES
DRUPAL=		${PREFIX}/share/drupal
PAX_DIRS=	includes misc modules scripts themes

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

BUILD_DEFS+=		APACHE_USER APACHE_GROUP
USE_TOOLS+=		perl:run pax
REPLACE_PERL=		scripts/code-style.pl

#OWN_DIRS+=		${DRUPAL}/sites/default
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

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/drupal.conf ${WRKSRC}

INSTALLATION_DIRS+= share/doc/drupal share/examples/drupal
INSTALLATION_DIRS+= share/drupal share/drupal/files
INSTALLATION_DIRS+= share/drupal/profiles share/drupal/profiles/default
INSTALLATION_DIRS+= share/drupal/sites share/drupal/sites/all
INSTALLATION_DIRS+= share/drupal/sites/default

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/drupal
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${DESTDIR}${DRUPAL}
	${INSTALL_DATA} ${WRKSRC}/sites/all/README.txt \
		${DESTDIR}${DRUPAL}/sites/all
	${INSTALL_DATA} ${WRKSRC}/drupal.conf \
		${DESTDIR}${PREFIX}/share/examples/drupal/drupal.conf
	${INSTALL_DATA} ${WRKSRC}/sites/default/settings.php \
		${DESTDIR}${PREFIX}/share/examples/drupal/settings.php
	${INSTALL_DATA} ${WRKSRC}/profiles/default/default.profile \
		${DESTDIR}${PREFIX}/share/examples/drupal/default.profile
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${DRUPAL}

.	for i in ${PAX_DIRS}
		cd ${WRKSRC}/${i} && pax -rw . ${DESTDIR}${DRUPAL}/${i}
.	endfor

post-install:
	${FIND} ${DESTDIR}${DRUPAL} -name \*.jpg | ${XARGS} ${CHMOD} 0644
	${FIND} ${DESTDIR}${DRUPAL} -name \*.png | ${XARGS} ${CHMOD} 0644

.include "../../mk/bsd.pkg.mk"
