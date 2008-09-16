# $NetBSD: Makefile,v 1.3 2008/09/16 13:31:26 taca Exp $
#

DISTNAME=	${TYPO3NAME}
PKGNAME=	typo3-${VER}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=typo3/}
DISTFILES=	${TYPO3NAME}${EXTRACT_SUFX} ${SITESRC}${EXTRACT_SUFX}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://typo3.com/
COMMENT=	The typo3 content management system

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.2.0:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.2.0:../../archivers/php-zlib/

#PKG_DESTDIR_SUPPORT=	user-destdir

VER=		4.2.1
NO_BUILD=	yes
USE_TOOLS=	pax

TYPO3NAME=	typo3_src-${VER}
SITESRC=	dummy-${VER}

PHP_VERSIONS_ACCEPTED=	5

# maybe resides in lang/php/phpversion.mk
REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	typo3/cli_dispatch.phpsh \
			typo3/mod/user/ws/cli/ws_cli.phpsh \
			typo3/sysext/indexed_search/cli/indexer_cli.phpsh

TYPO3DATA=	fileadmin typo3conf typo3temp uploads

BUILD_DEFS+=	APACHE_GROUP

FILES_SUBST+=	TYPO3DIR=${TYPO3DIR:Q} SITEDIR=${SITEDIR:Q}
PLIST_SUBST+=	SITEDIR=${SITEDIR:Q} TYPO3DIR=${TYPO3DIR:Q} \
		TYPO3NAME=${TYPO3NAME:Q}

INSTALLATION_DIRS+= ${TYPO3DIR}/${SITEDIR} ${TYPO3DIR}/${TYPO3NAME}

.for d in ${TYPO3DATA}
SPECIAL_PERMS+=	${TYPO3DIR}/${SITEDIR}/${d} ${BINOWN} ${APACHE_GROUP} 0770
CHECK_PERMS_SKIP+= ${TYPO3DIR}/${SITEDIR}/${d}
.endfor

.include "../../mk/bsd.prefs.mk"

SITEDIR?=	www
TYPO3DIR?=	share/typo3

do-install:
	cd ${WRKSRC}; pax -rw . ${DESTDIR}${PREFIX}/${TYPO3DIR}/${TYPO3NAME}
	cd ${WRKDIR}/${SITESRC}; \
		pax -rw . ${DESTDIR}${PREFIX}/${TYPO3DIR}/${SITEDIR}

.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
