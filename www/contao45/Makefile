# $NetBSD: Makefile,v 1.5.2.1 2018/05/06 10:39:13 spz Exp $
#

DISTNAME=	contao-${CT_PKGVER}
PKGNAME=	${PHP_PKG_PREFIX}-contao${CT_VER}-${CT_VERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=contao/}
GITHUB_PROJECT=	managed-edition
GITHUB_RELEASE=	${CT_VERSION}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://contao.org/
COMMENT=	Contao Open Source CMS ${CT_VERSION}
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=7.1:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=7.1:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=7.1:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=7.1:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=7.1:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-json>=7.1:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=7.1:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=7.1:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-pecl-mcrypt>=1.0.1:../../security/php-pecl-mcrypt

CT_VERSION=	4.5.8
USE_TOOLS=	bash:run pax
NO_BUILD=	yes

PHP_VERSIONS_ACCEPTED=	71 72

EG_DATA=	app/config

RESTRICT_DIRS=	${EG_DATA} var/cache var/logs

CONF_FILES+=	${CT_EGDIR}/contao.conf ${PKG_SYSCONFDIR}/contao.conf

.for d in ${RESTRICT_DIRS}
OWN_DIRS_PERMS+= ${CT_WEBDIR}/${d} ${APACHE_USER} ${APACHE_GROUP} 0770
.endfor

WWW_FILES=	README.md assets composer.json composer.lock vendor web

INSTALLATION_DIRS+=	${CT_DOCDIR} ${CT_EGDIR}/${EG_DATA} \
			${CT_WEBDIR}/${EG_DATA}

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

REPLACE_BASH+=	vendor/paragonie/random_compat/build-phar.sh \
	vendor/sensio/distribution-bundle/Resources/bin/build.sh \
	vendor/sensio/distribution-bundle/Resources/bin/build_demo.sh \
	vendor/ua-parser/uap-php/update-resources.sh

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php= \
	vendor/bin/contao-api vendor/bin/update-psl-icann-section \
	vendor/contao/manager-bundle/bin/contao-api \
	vendor/league/uri-hostname-parser/bin/update-psl-icann-section \
	vendor/contao/manager-bundle/bin/contao-console \
	vendor/doctrine/dbal/bin/doctrine-dbal \
	vendor/oyejorge/less.php/bin/lessc \
	vendor/matthiasmullie/minify/bin/minifycss \
	vendor/matthiasmullie/minify/bin/minifyjs \
	vendor/leafo/scssphp/bin/pscss \
	vendor/sensiolabs/security-checker/security-checker \
	vendor/ua-parser/uap-php/bin/uaparser \
	vendor/sensio/distribution-bundle/Resources/bin/build_bootstrap.php \
	vendor/swiftmailer/swiftmailer/lib/swiftmailer_generate_mimes_config.php \
	vendor/symfony/symfony/link vendor/symfony/symfony/phpunit \
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

pre-configure:
	${CP} ${FILESDIR}/contao.conf ${WRKDIR}
	cd ${WRKSRC}; ${CHMOD} -x ${PERMFIXFILES}

do-install:
	cd ${WRKSRC}; pax -rw ${WWW_FILES} ${DESTDIR}${PREFIX}/${CT_WEBDIR}
	${INSTALL_DATA} ${WRKDIR}/contao.conf ${DESTDIR}${PREFIX}/${CT_EGDIR}
	${INSTALL_DATA} ${FILESDIR}/README \
		${DESTDIR}${PREFIX}/${CT_DOCDIR}

.include "../../www/contao/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
