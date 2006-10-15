# $NetBSD: Makefile,v 1.15 2006/10/15 19:37:26 rillig Exp $
#

DISTNAME=	WebSVN_161
PKGNAME=	websvn-1.61
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/14334/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://websvn.tigris.org/
COMMENT=	Subversion repository web frontend

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.0.0:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib

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

post-extract:
	chmod -R go-w ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/distconfig.inc ${EGDIR}
	cd ${WRKSRC} && ${PAX} -rwppm . ${PREFIX}/${HTTPD_ROOT}/websvn

post-install:
	${RM} ${PREFIX}/${HTTPD_ROOT}/websvn/include/distconfig.inc

.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
