# $NetBSD: Makefile,v 1.2 2024/02/26 14:11:45 taca Exp $
#

DISTNAME=	${CM_NAME}.phar
PKGNAME=	${PHP_PKG_PREFIX}-${CM_NAME}-${CM_VERSION}
CATEGORIES=	www
MASTER_SITES=	https://download.contao.org/contao-manager/stable/
DIST_SUBDIR=	${CM_NAME}/${CM_VERSION}
EXTRACT_SUFX=

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://contao.org/
COMMENT=	Management tool for Contao Open Source CMS
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-intl>=8.1.0:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=8.1.0:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=8.1.0:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=8.1.0:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=8.1.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=8.1.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-pecl-mcrypt>=1.0.1:../../security/php-pecl-mcrypt

CM_NAME=	contao-manager
CM_VERSION=	1.8.4
NO_BUILD=	yes

PHP_VERSIONS_ACCEPTED=	81 82 83

CT_DOCDIR=	share/doc/${PHP_PKG_PREFIX}/${CM_NAME}
CT_EGDIR=	share/examples/${PHP_PKG_PREFIX}/${CM_NAME}
CT_WEBDIR=	share/${PHP_PKG_PREFIX}/contao
CT_PUBDIR?=	public

WRKSRC=		${WRKDIR}
BUILD_DEFS+=	APACHE_USER CT_DOCDIR CT_EGDIR CT_WEBDIR CT_PUBDIR
PLIST_SUBST+=	CT_DOCDIR=${CT_DOCDIR} CT_EGDIR=${CT_EGDIR} \
		DISTNAME=${DISTNAME}

CONF_FILES+=		${CT_EGDIR}/contao.conf \
			${PKG_SYSCONFDIR}/contao.conf
CONF_FILES_PERMS+=	${CT_EGDIR}/${DISTNAME}.php \
			${CT_WEBDIR}/${CT_PUBDIR}/${DISTNAME}.php \
			${APACHE_USER} ${APACHE_GROUP} 0644
OWN_DIRS_PERMS+=	${CT_WEBDIR} ${APACHE_USER} ${APACHE_GROUP} 0770
OWN_DIRS_PERMS+=	${CT_WEBDIR}/${CT_PUBDIR} \
			${APACHE_USER} ${APACHE_GROUP} 0770
PKG_SYSCONFSUBDIR=	${PHP_PKG_PREFIX}
PRINT_PLIST_AWK+=	/${DISTNAME:S|.|\\.|g}/ \
			{ sub(/${DISTNAME:S|.|\\.|g}/, "$${DISTNAME}"); }
PRINT_PLIST_AWK+=	/^${CT_DOCDIR:S|/|\\/|g}/ \
			{ sub(/^${CT_DOCDIR:S|/|\\/|g}/, "$${CT_DOCDIR}"); }
PRINT_PLIST_AWK+=	/^${CT_EGDIR:S|/|\\/|g}/ \
			{ sub(/^${CT_EGDIR:S|/|\\/|g}/, "$${CT_EGDIR}"); }

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_MESSAGE.path=	Substituting path
SUBST_FILES.path+=	${WRKDIR}/README ${WRKDIR}/contao.conf
SUBST_VARS.path+=	CT_WEBDIR CT_PUBDIR PREFIX PKG_SYSCONFDIR
SUBST_VARS.path+=	PHP_PKG_PREFIX

INSTALLATION_DIRS+=	${CT_DOCDIR} ${CT_EGDIR} ${CT_WEBDIR}/${CT_PUBDIR}

pre-configure:
	${CP} ${FILESDIR}/README ${FILESDIR}/contao.conf ${WRKDIR}

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/${CT_EGDIR}/${DISTNAME}.php
	${INSTALL_DATA} ${WRKDIR}/contao.conf ${DESTDIR}${PREFIX}/${CT_EGDIR}
	${INSTALL_DATA} ${WRKDIR}/README ${DESTDIR}${PREFIX}/${CT_DOCDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
