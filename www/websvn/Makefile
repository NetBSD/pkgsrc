# $NetBSD: Makefile,v 1.2 2004/06/21 01:34:16 xtraeme Exp $
#

DISTNAME=	WebSVN_140
PKGNAME=	websvn-1.40
CATEGORIES=	www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/10659/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://websvn.tigris.org/
COMMENT=	Subversion repository web frontend

BUILD_DEPENDS+=	{apache-[0-9]*,apache6-[0-9]*,apache2-[0-9]*}:../../www/apache2
BUILD_DEPENDS+=	ap-php-[0-9]*:../../www/ap-php4

WRKSRC=		${WRKDIR}/WebSVN
NO_BUILD=	yes
USE_PKGINSTALL=	yes

PKG_SYSCONFDIR.websvn=	${PREFIX}/${HTTPD_ROOT}/websvn/include	

MESSAGE_SUBST+=	PKGBASE=${PKGBASE}
MESSAGE_SUBST+=	HTTPD_ROOT=${HTTPD_ROOT}
PLIST_SUBST+=	HTTPD_ROOT=${HTTPD_ROOT}

HTTPD_ROOT?=	share/httpd/htdocs

BUILD_DEFS+=	HTTPD_ROOT

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
MAKE_DIRS=	${PREFIX}/${HTTPD_ROOT}/websvn/include
CONF_FILES=	${EGDIR}/distconfig.inc ${PKG_SYSCONFDIR}/config.inc

INSTALLATION_DIRS=	${HTTPD_ROOT}/websvn share/examples/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/distconfig.inc ${EGDIR}
	cd ${WRKSRC} && ${PAX} -rwppm . ${PREFIX}/${HTTPD_ROOT}/websvn

post-install:
	${RM} ${PREFIX}/${HTTPD_ROOT}/websvn/include/distconfig.inc

.include "../../mk/bsd.pkg.mk"
