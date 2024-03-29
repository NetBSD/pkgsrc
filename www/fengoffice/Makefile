# $NetBSD: Makefile,v 1.42 2024/02/19 15:43:36 taca Exp $
#

DISTNAME=	fengoffice-${FO_VERSION}
PKGNAME=	${DISTNAME:S/_/-/:C/.rc$/rc1/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fengoffice/}
GITHUB_TYPE=	tag
GITHUB_PROJECT=	fengoffice
GITHUB_RELEASE=	${FO_VERSION}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://fengoffice.com/web/community/community_index.php
COMMENT=	Easy to use Open Source Web Office
LICENSE=	gnu-agpl-v3

CONFLICTS+=	opengoo-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=7.1:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.1.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.1.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.1.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=5.1.0:../../mail/php-imap

FO_VERSION=	3.8.5.8

#EXTRACT_USING=	bsd-tar
USE_TOOLS=	pax
NO_BUILD=	yes

OWN_DIRS_PERMS+=	${FO_DIR}/public/files ${REAL_ROOT_USER} ${APACHE_GROUP} 0775
OWN_DIRS_PERMS+=	${FO_DIR}/upload ${REAL_ROOT_USER} ${APACHE_GROUP} 0770
OWN_DIRS_PERMS+=	${FO_DIR}/cache ${REAL_ROOT_USER} ${APACHE_GROUP} 0770
OWN_DIRS_PERMS+=	${FO_DIR}/config ${REAL_ROOT_USER} ${APACHE_GROUP} 0770
OWN_DIRS_PERMS+=	${FO_DIR}/tmp ${REAL_ROOT_USER} ${APACHE_GROUP} 0770

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	FO_DIR=${FO_DIR} APACHE_USER=${APACHE_USER}
PLIST_SUBST+=	FO_DIR=${FO_DIR}

PRINT_PLIST_AWK+= \
		/^${FO_DIR:S|/|\\/|g}/ \
		{ gsub(/${FO_DIR:S|/|\\/|g}/, "$${FO_DIR}"); \
		print; next; }

.include "../../mk/bsd.prefs.mk"

FO_DIR?=		share/fengoffice
INSTALLATION_DIRS=	${FO_DIR}

post-extract:
	cd ${WRKSRC}; ${FIND} . -type f -exec ${CHMOD} -x {} \;
	for f in environment/classes/encoding/EncodingConverter.class.php \
		 public/assets/themes/default/stylesheets/og/co.css \
		 plugins/mail/application/helpers/MailUtilities.class.php; do \
		${TR} -d '\r' < ${WRKSRC}/$${f} > ${WRKSRC}/$${f}.new; \
		${MV} ${WRKSRC}/$${f}.new ${WRKSRC}/$${f}; \
	done

pre-install:
	${RM} -f ${WRKSRC}/config/empty.config.php
	${FIND} ${WRKSRC} -type f \
		\( -name .project -o -name .cvsignore \) -exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC}; ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${FO_DIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
