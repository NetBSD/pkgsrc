# $NetBSD: Makefile,v 1.5 2026/02/19 14:45:11 hauke Exp $

DISTNAME=	osticket-v1.18.3
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=osTicket/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://osticket.com/
COMMENT=	Open source support ticket system
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/upload

NO_BUILD=	yes
USE_LANGUAGES=	# none

USE_TOOLS+=	chmod find pax perl

DEPENDS+=	${PHP_PKG_PREFIX}-apcu>=5.1:../../www/php-apcu
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=${PHP_BASE_VERS}:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=${PHP_BASE_VERS}:../../mail/php-imap
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=${PHP_BASE_VERS}:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-opcache>=${PHP_BASE_VERS}:../../devel/php-opcache
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip

PHP_VERSIONS_INCOMPATIBLE=	56

REPLACE_PHP+=	manage.php
REPLACE_PHP+=	setup/scripts/api_ticket_create.php
REPLACE_PHP+=	setup/scripts/automail.php
REPLACE_PHP+=	setup/scripts/rcron.php
REPLACE_PHP+=	include/laminas-mail/vendor/bin/generate-deps-for-config-factory
REPLACE_PHP+=	include/laminas-mail/vendor/bin/generate-factory-for-class
REPLACE_PHP+=	include/laminas-mail/vendor/laminas/laminas-servicemanager/bin/generate-deps-for-config-factory
REPLACE_PHP+=	include/laminas-mail/vendor/laminas/laminas-servicemanager/bin/generate-factory-for-class

REPLACE_SH+=	include/mpdf/vendor/paragonie/random_compat/build-phar.sh
REPLACE_PERL+=	setup/scripts/automail.pl

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		APACHE_USER APACHE_GROUP VARBASE

PKG_SYSCONFSUBDIR=	osticket
PKG_SYSCONFDIR_PERMS=	${APACHE_USER} ${APACHE_GROUP} 0700

EGDIR=			share/examples/osticket
OSTICKET_DIR=		share/osticket

CONF_FILES+=		${EGDIR}/ost-config.php.sample \
				${PKG_SYSCONFDIR}/ost-config.php

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	../apache-osticket.conf
SUBST_VARS.paths+=	PREFIX

INSTALLATION_DIRS+=	${EGDIR} ${OSTICKET_DIR}

post-patch:
	${CP} ${PKGDIR}/files/apache-osticket.conf ${WRKDIR}

do-install:
	find ${WRKSRC} -name \*.orig -exec rm {} \;
	find ${WRKSRC} \( -name \*.jpg -or -name \*.png -or -name \*.svg \
			-or -name \*.ttf -or -name \*.woff -or -name \*.eot \
			-or -name \*.js -or -name \*.json -or -name \*.html \
			-or -name \*.css \)  \
			-exec chmod ugo-x {} \;
	find ${WRKSRC}/include -name \*.php -exec chmod ugo-x {} \;
	chmod ugo-x ${WRKSRC}/setup/cli/manage.php
	${MV} ${WRKSRC}/include/ost-sampleconfig.php \
		 ${DESTDIR}${PREFIX}/${EGDIR}/ost-config.php.sample
	${LN} -s ${PKG_SYSCONFDIR}/ost-config.php \
			${WRKSRC}/include/ost-config.php
	${INSTALL_DATA} ${WRKDIR}/apache-osticket.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/apache-osticket.conf
	cd ${WRKSRC}/setup/scripts && ${PAX} -rw . ${DESTDIR}${PREFIX}/${EGDIR}
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/${OSTICKET_DIR}

.include "../../mk/apache.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
