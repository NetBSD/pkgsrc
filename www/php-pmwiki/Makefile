# $NetBSD: Makefile,v 1.1 2026/05/30 12:59:58 ryoon Exp $

DISTNAME=	pmwiki-2.6.0
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://www.pmwiki.org/pub/pmwiki/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.pmwiki.org/
COMMENT=	Wiki-based content-management system
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax:build

EGDIR=			share/examples/pmwiki
PMWIKI_DIR=		share/pmwiki
INSTALLATION_DIRS+=	${EGDIR} ${PMWIKI_DIR}/wiki.d

.include "../../mk/bsd.prefs.mk"

WWW_USER?=	${APACHE_USER}
WWW_GROUP?=	${APACHE_GROUP}

BUILD_DEFS+=	APACHE_GROUP APACHE_USER

PKG_SYSCONFSUBDIR=	${PHP_PKG_PREFIX}-pmwiki

CONF_FILES=	${PREFIX}/${EGDIR}/sample-config.php \
		${PKG_SYSCONFDIR}/config.php

OWN_DIRS_PERMS+=	${PREFIX}/${PMWIKI_DIR}/wiki.d \
			${WWW_USER} ${WWW_GROUP} 0750

do-install:
	cd ${WRKSRC} && \
		${FIND} . \( -type f -o -type l \) \! -name '*.orig' -print | \
                pax -rw -pmp ${DESTDIR}${PREFIX}/${PMWIKI_DIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${WRKSRC}/docs/sample-config.php \
		${DESTDIR}${PREFIX}/${EGDIR}/sample-config.php
	cd ${DESTDIR}${PREFIX}/${PMWIKI_DIR} && \
		${LN} -sf ${PKG_SYSCONFDIR}/config.php config.php

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
