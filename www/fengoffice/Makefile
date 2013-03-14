# $NetBSD: Makefile,v 1.23 2013/03/14 16:33:15 taca Exp $
#

DISTNAME=	fengoffice_2.2.3.1
PKGNAME=	${DISTNAME:S/_/-/:C/.rc$/rc1/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opengoo/}
EXTRACT_SUFX=	.zip

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://fengoffice.com/web/community/community_index.php
COMMENT=	Easy to use Open Source Web Office
LICENSE=	gnu-agpl-v3

CONFLICTS+=	opengoo-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.1.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.1.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.1.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.1.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.1.0:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=5.1.0:../../mail/php-imap

EXTRACT_DIR=	${WRKDIR}/fengoffice
WRKSRC=		${WRKDIR}/fengoffice
USE_TOOLS=	pax
NO_BUILD=	yes

OWN_DIRS_PERMS+= ${FO_DIR}/public/files ${REAL_ROOT_USER} ${APACHE_GROUP} 0775
OWN_DIRS_PERMS+= ${FO_DIR}/upload ${REAL_ROOT_USER} ${APACHE_GROUP} 0770
OWN_DIRS_PERMS+= ${FO_DIR}/cache ${REAL_ROOT_USER} ${APACHE_GROUP} 0770
OWN_DIRS_PERMS+= ${FO_DIR}/config ${REAL_ROOT_USER} ${APACHE_GROUP} 0770
OWN_DIRS_PERMS+=  ${FO_DIR}/tmp ${REAL_ROOT_USER} ${APACHE_GROUP} 0770

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	FO_DIR=${FO_DIR} APACHE_USER=${APACHE_USER}
PLIST_SUBST+=	FO_DIR=${FO_DIR}

PRINT_PLIST_AWK+= \
		/^${FO_DIR:S|/|\\/|g}/ \
		{ gsub(/${FO_DIR:S|/|\\/|g}/, "$${FO_DIR}"); \
		print; next; }

.include "../../mk/bsd.prefs.mk"

FO_DIR?=	share/fengoffice
INSTALLATION_DIRS=	${FO_DIR}

post-extract:
	cd ${WRKSRC}; ${FIND} . -type f -exec ${CHMOD} -x {} \;

pre-install:
	${RM} -f ${WRKSRC}/config/empty.config.php
	${FIND} ${WRKSRC} -type f \
		\( -name .project -o -name .cvsignore \) -exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC}; ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${FO_DIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
