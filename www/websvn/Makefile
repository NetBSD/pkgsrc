# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:50 wiz Exp $
#

DISTNAME=	WebSVN_161
PKGNAME=	websvn-1.61
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/14334/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://websvn.tigris.org/
COMMENT=	Subversion repository web frontend

DEPENDS+=	ap{,2}-php>=4.0.0:../../www/ap-php
DEPENDS+=	php-zlib-[0-9]*:../../archivers/php-zlib

WRKSRC=		${WRKDIR}/WebSVN
NO_BUILD=	yes

PKG_SYSCONFDIR.websvn=	${PREFIX}/${HTTPD_ROOT}/websvn/include

MESSAGE_SUBST+=	PKGBASE=${PKGBASE}
MESSAGE_SUBST+=	HTTPD_ROOT=${HTTPD_ROOT}
PLIST_SUBST+=	HTTPD_ROOT=${HTTPD_ROOT:Q}

HTTPD_ROOT?=	share/httpd/htdocs

BUILD_DEFS+=	HTTPD_ROOT

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
REQD_DIRS=	${PREFIX}/${HTTPD_ROOT}/websvn/include
CONF_FILES=	${EGDIR}/distconfig.inc ${PKG_SYSCONFDIR}/config.inc

INSTALLATION_DIRS=	${HTTPD_ROOT}/websvn share/examples/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/distconfig.inc ${EGDIR}
	cd ${WRKSRC} && ${PAX} -rwppm . ${PREFIX}/${HTTPD_ROOT}/websvn

post-install:
	${RM} ${PREFIX}/${HTTPD_ROOT}/websvn/include/distconfig.inc

.include "../../mk/bsd.pkg.mk"
