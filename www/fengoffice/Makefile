# $NetBSD: Makefile,v 1.1.1.1 2009/12/20 15:39:45 taca Exp $
#

DISTNAME=	fengoffice_1.6.1
PKGNAME=	${DISTNAME:S/_/-/:S/.rc/rc1/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opengoo/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PKGBASE}-20091219

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://fengoffice.com/web/community/community_index.php
COMMENT=	Easy to use Open Source Web Office
LICENSE=	gnu-gpl-v3

CONFLICTS+=	opengoo-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.1.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.1.0:../../misc/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.1.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.1.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.1.0:../../textproc/php5-dom
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=5.1.0:../../mail/php-imap

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_TOOLS=	pax
NO_BUILD=	yes

OWN_DIRS_PERMS+= ${FO_DIR}/public/files ${BINOWN} ${APACHE_GROUP} 0775
OWN_DIRS_PERMS+= ${FO_DIR}/upload ${BINOWN} ${APACHE_GROUP} 0770
OWN_DIRS_PERMS+= ${FO_DIR}/cache ${BINOWN} ${APACHE_GROUP} 0770
OWN_DIRS_PERMS+= ${FO_DIR}/config ${BINOWN} ${APACHE_GROUP} 0770
SPECIAL_PERMS+=  ${FO_DIR}/tmp ${BINOWN} ${APACHE_GROUP} 0770

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	FO_DIR=${FO_DIR} APACHE_USER=${APACHE_USER}
PLIST_SUBST+=	FO_DIR=${FO_DIR}

PRINT_PLIST_AWK+= \
		/^${FO_DIR:S|/|\\/|g}/ \
		{ gsub(/${FO_DIR:S|/|\\/|g}/, "$${FO_DIR}"); \
		print; next; }

.include "../../mk/bsd.prefs.mk"

FO_DIR?=	share/fengoffice

post-extract:
	cd ${WRKSRC}; ${FIND} . -type f -exec ${CHMOD} -x {} \;

pre-install:
	cd ${WRKSRC}; ${RM} -f .htaccess .project \
		application/views/files/.cvsignore \
		environment/classes/.cvsignore \
		config/empty.config.php

do-install:
	cd ${WRKSRC}; ${FIND} . -type f -print | \
		pax -rw ${DESTDIR}${PREFIX}/${FO_DIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
