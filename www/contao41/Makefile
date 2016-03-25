# $NetBSD: Makefile,v 1.5 2016/03/25 16:03:46 taca Exp $
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

DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.4.0:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.4.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.4.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=5.4.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.4.0:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=5.4.0:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=5.4.0:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.4.0:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.4.0:../../archivers/php-zlib
DEPENDS+=	bash>=4.0:../../shells/bash

CT_VERSION=	4.1.2
USE_TOOLS=	bash pax
NO_BUILD=	yes

EG_CONFIG=	app/config/config.yml app/config/config_dev.yml \
		app/config/config_prod.yml app/config/config_test.yml \
		app/config/parameters.yml.dist app/config/routing.yml \
		app/config/routing_dev.yml app/config/security.yml \
		web/robots.txt
EG_DATA=	app/config web/robots.txt

RESTRICT_DIRS=	app/config app/cache app/logs

CONF_FILES+=	${CT_EGDIR}/contao.conf ${PKG_SYSCONFDIR}/contao.conf

REPLACE_BASH=	vendor/sensio/distribution-bundle/Sensio/Bundle/DistributionBundle/Resources/bin/build.sh

.for f in ${EG_CONFIG}
CONF_FILES+=	${CT_EGDIR}/${f} ${CT_WEBDIR}/${f}
.endfor

.for d in ${RESTRICT_DIRS}
OWN_DIRS_PERMS+=	${CT_WEBDIR}/${d} ${APACHE_USER} ${APACHE_GROUP} 0770
.endfor

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php= \
	app/console vendor/bin/doctrine-dbal vendor/bin/lessc \
	vendor/bin/minifycss vendor/bin/minifyjs vendor/bin/pscss \
	vendor/bin/security-checker vendor/doctrine/dbal/bin/doctrine-dbal \
	vendor/leafo/scssphp/bin/pscss \
	vendor/matthiasmullie/minify/bin/minifycss \
	vendor/matthiasmullie/minify/bin/minifyjs \
	vendor/oyejorge/less.php/bin/lessc \
	vendor/sensio/distribution-bundle/Sensio/Bundle/DistributionBundle/Resources/bin/build_bootstrap.php \
	vendor/sensiolabs/security-checker/security-checker \
	vendor/swiftmailer/swiftmailer/lib/swiftmailer_generate_mimes_config.php \
	vendor/symfony/symfony/phpunit

SUBST_CLASSES+=		conf
SUBST_FILES.conf+=	${WRKDIR}/contao.conf
SUBST_SED.conf+=        -e 's|@PREFIX@|${PREFIX:Q}|g'
SUBST_SED.conf+=        -e 's|@CT_WEBDIR@|${CT_WEBDIR:Q}|g'
SUBST_STAGE.conf=	post-configure

WWW_FILES=	CHANGELOG.md README.md app/AppCache.php app/AppKernel.php \
		app/autoload.php app/bootstrap.php.cache app/cache \
		app/console app/logs assets build.xml composer.json \
		composer.lock vendor web
WWW_SYSFILES=	.htaccess bin config/default.php cron docs helper \
		initialize.php modules themes

INSTALLATION_DIRS+=	${CT_DOCDIR} ${CT_EGDIR} ${CT_WEBDIR}/app/config

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

pre-configure:
	${CP} ${FILESDIR}/contao.conf ${WRKDIR}

pre-install:
	cd ${WRKSRC}; ${RM} -fr files/music_academy templates/music_academy.sql

do-install:
	cd ${WRKSRC}; pax -rw ${WWW_FILES} ${DESTDIR}${PREFIX}/${CT_WEBDIR}
	cd ${WRKSRC}; pax -rw ${EG_DATA} ${DESTDIR}${PREFIX}/${CT_EGDIR}
	${INSTALL_DATA} ${WRKDIR}/contao.conf ${DESTDIR}${PREFIX}/${CT_EGDIR}
	${INSTALL_DATA} ${FILESDIR}/README \
		${DESTDIR}${PREFIX}/${CT_DOCDIR}

.include "../../www/contao/Makefile.common"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
