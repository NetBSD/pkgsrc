# $NetBSD: Makefile,v 1.1 2024/02/26 15:06:27 taca Exp $
#

DISTNAME=	concrete-cms-${GITHUB_RELEASE}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=concretecms/}
GITHUB_PROJECT=	concretecms
GITHUB_RELEASE=	9.2.6
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.concretecms.org/
COMMENT=	Concrete CMS, Open sourece Content Management System
LICENSE=	mit

DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=5.3.3:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3.3:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.3.3:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.3.3:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.3.3:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.3.3:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-pecl-mcrypt>=1.0.0:../../security/php-pecl-mcrypt

SUPERSEDES+=	${PHP_PKG_PREFIX}-concrete5-[0-9]*

PHP_VERSIONS_ACCEPTED=	80 81 82

# Avoid unzip's warning
EXTRACT_OPTS_ZIP=	-qo

USE_LANGUAGES=	# none
NO_BUILD=	yes

USE_TOOLS+=	pax

BUILD_DEFS+=	APACHE_GROUP APACHE_USER

CC_DOCDIR?=		share/doc/${PHP_PKG_PREFIX}/concrete-cms
CC_WEBDIR?=		share/${PHP_PKG_PREFIX}/concrete-cms

INSTALLATION_DIRS=	${CC_WEBDIR} ${CC_DOCDIR}
OWN_DIRS_PERMS+=	${CC_WEBDIR}/application/config ${APACHE_USER} ${APACHE_GROUP} 0770
OWN_DIRS_PERMS+=	${CC_WEBDIR}/packages ${APACHE_USER} ${APACHE_GROUP} 0775

PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		CC_WEBDIR=${CC_WEBDIR}
PLIST_SUBST+=	CC_DOCDIR=${CC_DOCDIR} CC_WEBDIR=${CC_WEBDIR}

PRINT_PLIST_AWK+=	/^${CC_DOCDIR:S|/|\\/|g}/ \
			{ gsub(/${CC_DOCDIR:S|/|\\/|g}/, "$${CC_DOCDIR}") }
PRINT_PLIST_AWK+=	/^${CC_WEBDIR:S|/|\\/|g}/ \
			{ gsub(/${CC_WEBDIR:S|/|\\/|g}/, "$${CC_WEBDIR}") }

pre-install:
	cd ${WRKSRC} && ${FIND} . -type f -exec ${CHMOD} -x {} \;
	cd ${WRKSRC} && ${RMDIR} application/config packages || ${TRUE}

do-install:
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${CC_WEBDIR}
	${INSTALL_DATA} ${FILESDIR}/README ${DESTDIR}${PREFIX}/${CC_DOCDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
