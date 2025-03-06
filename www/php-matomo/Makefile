# $NetBSD: Makefile,v 1.1 2025/03/06 01:21:38 manu Exp $

DISTNAME=	matomo-5.2.2
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://builds.matomo.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.matomo.org/
COMMENT=	Web analytics platform
LICENSE=	gnu-gpl-v3

PHP_VERSIONS_ACCEPTED=	74 81 82 83

WRKSRC=		${WRKDIR}/matomo
USE_LANGUAGES=	# none
USE_TOOLS+=	pax
NO_BUILD=	yes

.include "../../lang/php/phpversion.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gmp-[0-9]*:../../devel/php-gmp
DEPENDS+=	${PHP_PKG_PREFIX}-intl-[0-9]*:../../textproc/php-intl
.if ${PKG_PHP_MAJOR_VERS} < 8
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
.endif
DEPENDS+=	${PHP_PKG_PREFIX}-ldap-[0-9]*:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-pdo-[0-9]*:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-zip-[0-9]*:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib
DEPENDS+=	dbip-city-lite-[0-9]*:../../net/dbip-city-lite

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	/usr/bin/env php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php+=	console
REPLACE_FILES.php+=	vendor/symfony/error-handler/Resources/bin/extract-tentative-return-types.php
REPLACE_FILES.php+=	vendor/symfony/error-handler/Resources/bin/patch-type-declarations
REPLACE_FILES.php+=	vendor/symfony/var-dumper/Resources/bin/var-dump-server
REPLACE_FILES.php+=	vendor/wikimedia/less.php/bin/lessc

REPLACE_PYTHON+=	misc/log-analytics/import_logs.py

.include "../../mk/bsd.prefs.mk"

PKG_USERS_VARS+=	APACHE_USER

MATOMODIR=	share/matomo

MAKE_DIRS_PERMS+=	${MATOMODIR}/config ${APACHE_USER} ${SHAREGRP} 0755
MAKE_DIRS_PERMS+=	${MATOMODIR}/tmp ${APACHE_USER} ${SHAREGRP} 0755

do-install:
	cd ${WRKSRC} && ${FIND} . -type f ! -name '*.orig' -print | \
	    ${PAX} -rw -pmp ${DESTDIR}${PREFIX}/${MATOMODIR}
	${LN} -sf ../../dbip/dbip-city-lite.mmdb \
	     ${DESTDIR}${PREFIX}/${MATOMODIR}/misc/DBIP-City.mmdb

CHECK_INTERPRETER_SKIP+=	${MATOMODIR}/vendor/pear/archive_tar/scripts/phptar.in

.include "../../lang/php/phpversion.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
