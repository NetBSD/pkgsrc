# $NetBSD: Makefile,v 1.2 2025/02/08 04:07:19 taca Exp $

DISTNAME=	typo3_src-${VER}
PKGNAME=	${PHP_PKG_PREFIX}-typo3-${VER}
CATEGORIES=	www
MASTER_SITES=	https://cdn.typo3.com/typo3/${VER}/

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://typo3.com/
COMMENT=	The TYPO3 content management system, 13 LTS release
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=${PHP_BASE_VERS}:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=${PHP_BASE_VERS}:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=${PHP_BASE_VERS}:../../graphics/php-exif

PHP_VERSIONS_ACCEPTED=	82 83 # 84

REPLACE_PHP+=	typo3/sysext/core/bin/typo3
REPLACE_PHP+=	vendor/nikic/php-parser/bin/php-parse
REPLACE_PHP+=	vendor/symfony/yaml/Resources/bin/yaml-lint
REPLACE_PHP+=	vendor/typo3/cms-cli/typo3
REPLACE_PHP+=	vendor/typo3fluid/fluid/bin/fluid

VER=		13.4.4

NO_BUILD=	YES
TYPO3DIR=	share/typo3

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

BUILD_DEFS+=		APACHE_USER APACHE_GROUP
USE_TOOLS+=		pax

CONF_FILES=		share/examples/typo3/typo3.conf \
			${PKG_SYSCONFDIR}/typo3.con
OWN_DIRS_PERMS+=	${PREFIX}/${TYPO3DIR} \
			${APACHE_USER} ${APACHE_GROUP} 0750

SUBST_CLASSES+=         conf
SUBST_STAGE.conf=       pre-install
SUBST_FILES.conf=       typo3.conf
SUBST_VARS.conf=        TYPO3DIR PREFIX
SUBST_MESSAGE.conf=     Fixing configuration files.

INSTALLATION_DIRS+=	share/examples/typo3 

pre-configure:
	${CP} ${FILESDIR}/typo3.conf ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/typo3.conf \
		${DESTDIR}${PREFIX}/share/examples/typo3/
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/${TYPO3DIR}


.include "../../lang/php/phpversion.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
