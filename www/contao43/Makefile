# $NetBSD: Makefile,v 1.12 2017/05/24 15:59:36 taca Exp $
#

DISTNAME=	contao-${CT_PKGVER}
PKGNAME=	${PHP_PKG_PREFIX}-contao${CT_VER}-${CT_VERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=contao/}
GITHUB_PROJECT=	standard-edition
GITHUB_RELEASE=	${CT_VERSION}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://contao.org/
COMMENT=	Contao Open Source CMS ${CT_VERSION}
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.4.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.4.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=5.4.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=5.4.0:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=5.4.0:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.4.0:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.4.0:../../archivers/php-zlib
DEPENDS+=	bash>=4.0:../../shells/bash

CT_VERSION=	4.3.10
USE_TOOLS=	bash pax
NO_BUILD=	yes

EG_CONFIG=	app/config/config.yml app/config/config_dev.yml \
		app/config/config_prod.yml app/config/config_test.yml \
		app/config/routing.yml \
		app/config/routing_dev.yml app/config/security.yml
# app/config/parameters.yml.dist 
EG_DATA=	app/config

RESTRICT_DIRS=	app/config var/cache var/logs

CONF_FILES+=	${CT_EGDIR}/contao.conf ${PKG_SYSCONFDIR}/contao.conf

.for f in ${EG_CONFIG}
CONF_FILES+=	${CT_EGDIR}/${f} ${CT_WEBDIR}/${f}
.endfor

.for d in ${RESTRICT_DIRS}
OWN_DIRS_PERMS+= ${CT_WEBDIR}/${d} ${APACHE_USER} ${APACHE_GROUP} 0770
.endfor

WWW_FILES=	CHANGELOG.md README.md app/AppCache.php app/AppKernel.php \
		app/autoload.php assets bin/console \
		composer.json composer.lock vendor web

INSTALLATION_DIRS+=	${CT_DOCDIR} ${CT_EGDIR}/app/config \
			 ${CT_WEBDIR}/app/config

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

REPLACE_BASH+=	vendor/paragonie/random_compat/build-phar.sh \
	vendor/sensio/distribution-bundle/Resources/bin/build.sh \
	vendor/sensio/distribution-bundle/Resources/bin/build_demo.sh

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php= \
	bin/console vendor/bin/doctrine-dbal vendor/bin/lessc \
	vendor/bin/minifycss vendor/bin/minifyjs vendor/bin/pscss \
	vendor/bin/security-checker vendor/doctrine/dbal/bin/doctrine-dbal \
	vendor/jeremykendall/php-domain-parser/bin/parse \
	vendor/jeremykendall/php-domain-parser/bin/update-psl \
	vendor/leafo/scssphp/bin/pscss \
	vendor/matthiasmullie/minify/bin/minifycss \
	vendor/matthiasmullie/minify/bin/minifyjs \
	vendor/oyejorge/less.php/bin/lessc \
	vendor/sensio/distribution-bundle/Resources/bin/build_bootstrap.php \
	vendor/sensiolabs/security-checker/security-checker \
	vendor/swiftmailer/swiftmailer/lib/swiftmailer_generate_mimes_config.php \
	vendor/symfony/symfony/phpunit \
	vendor/symfony/symfony/src/Symfony/Bridge/PhpUnit/bin/simple-phpunit \
	vendor/tecnickcom/tcpdf/tools/tcpdf_addfont.php

SUBST_CLASSES+=		conf
SUBST_FILES.conf+=	${WRKDIR}/contao.conf
SUBST_SED.conf+=        -e 's|@PREFIX@|${PREFIX:Q}|g'
SUBST_SED.conf+=        -e 's|@CT_WEBDIR@|${CT_WEBDIR:Q}|g'
SUBST_STAGE.conf=	post-configure

PERMFIXFILES=	vendor/oyejorge/less.php/lib/Less/Less.php.combine \
	vendor/simplepie/simplepie/.travis.yml \
	vendor/simplepie/simplepie/library/SimplePie.php \
	vendor/simplepie/simplepie/library/SimplePie/Cache/Memcached.php \
	vendor/simplepie/simplepie/library/SimplePie/Registry.php

.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} < 71
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.4.0:../../security/php-mcrypt
.else
DEPENDS+=	${PHP_PKG_PREFIX}-pecl-mcrypt>=1.0.1:../../security/php-pecl-mcrypt
.endif

pre-configure:
	${CP} ${FILESDIR}/contao.conf ${WRKDIR}
	cd ${WRKSRC}; ${CHMOD} -x ${PERMFIXFILES}

do-install:
	cd ${WRKSRC}; pax -rw ${WWW_FILES} ${DESTDIR}${PREFIX}/${CT_WEBDIR}
	${INSTALL_DATA} ${WRKSRC}/app/config/parameters.yml.dist \
		${DESTDIR}${PREFIX}/${CT_WEBDIR}/app/config
	cd ${WRKSRC}/${EG_DATA}; \
		${INSTALL_DATA} *.yml ${DESTDIR}${PREFIX}/${CT_EGDIR}/app/config
	${INSTALL_DATA} ${WRKDIR}/contao.conf ${DESTDIR}${PREFIX}/${CT_EGDIR}
	${INSTALL_DATA} ${FILESDIR}/README \
		${DESTDIR}${PREFIX}/${CT_DOCDIR}

.include "../../www/contao/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
