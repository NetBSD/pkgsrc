# $NetBSD: Makefile,v 1.13 2016/02/16 13:00:02 taca Exp $
#

DISTNAME=	${TYPO3NAME}
PKGNAME=	${PHP_PKG_PREFIX}-typo3-${VER}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=typo3/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://typo3.com/
COMMENT=	The TYPO3 content management system, 6.2 LTS release
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-{mysqli,pgsql}>=5.1.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3.7:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=5.3.7:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3.7:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.3.7:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.3.7:../../archivers/php-zlib

VER=		6.2.18
NO_BUILD=	yes
USE_TOOLS+=	bash:run pax

TYPO3NAME=	typo3_src-${VER}
WRKSRC=		${WRKDIR}/${DISTNAME}

# maybe resides in lang/php/phpversion.mk
REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	typo3/cli_dispatch.phpsh

REPLACE_BASH= typo3/sysext/core/Build/Scripts/xlfcheck.sh \
	typo3/sysext/core/Build/Scripts/update-static-composer.sh

OWN_DIRS_PERMS+= ${TYPO3DIR}/${SITEDIR} ${REAL_ROOT_USER} ${APACHE_GROUP} 0770

BUILD_DEFS+=	APACHE_GROUP

FILES_SUBST+=	SITEDIR=${SITEDIR} TYPO3DIR=${TYPO3DIR} TYPO3NAME=${TYPO3NAME} 
MESSAGE_SUBST+=	SITEDIR=${SITEDIR} TYPO3DIR=${TYPO3DIR} 
PLIST_SUBST+=	SITEDIR=${SITEDIR} TYPO3DIR=${TYPO3DIR} TYPO3NAME=${TYPO3NAME}

INSTALLATION_DIRS+= ${TYPO3DIR}/${TYPO3NAME}

PRINT_PLIST_AWK+=	/^${TYPO3DIR:S|/|\\/|g}\/${TYPO3NAME}/ \
			{ gsub(/${TYPO3DIR:S|/|\\/|g}\/${TYPO3NAME}/, \
				"$${TYPO3DIR}/$${TYPO3NAME}") }
PRINT_PLIST_AWK+=	/^${TYPO3DIR:S|/|\\/|g}\/${SITEDIR}/ \
			{ gsub(/${TYPO3DIR:S|/|\\/|g}\/${SITEDIR}/, \
				"$${TYPO3DIR}/$${SITEDIR}") }

.include "../../mk/bsd.prefs.mk"

SITEDIR?=	www
TYPO3DIR?=	share/typo3

do-install:
	cd ${WRKSRC} && ${FIND} . ! -type d -a \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${TYPO3DIR}/${TYPO3NAME}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
