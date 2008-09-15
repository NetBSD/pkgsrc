# $NetBSD: Makefile,v 1.1.1.1 2008/09/15 18:13:29 taca Exp $
#

DISTNAME=	${TYPO3NAME}
PKGNAME=	typo3-${VER}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=typo3/}
DISTFILES=	${TYPO3NAME}${EXTRACT_SUFX} ${SITESRC}${EXTRACT_SUFX}

MAINTAINER=	pkg-users@NetBSD.org
HOMEPAGE=	http://typo3.com/
COMMENT=	The typo3 content management system

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.3:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=4.3.3:../../archivers/php-zlib/

#PKG_DESTDIR_SUPPORT=	user-destdir

VER=		4.2.1
NO_BUILD=	yes
USE_TOOLS=	pax

TYPO3NAME=	typo3_src-${VER}
SITESRC=	dummy-${VER}

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
