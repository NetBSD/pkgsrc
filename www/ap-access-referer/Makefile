# $NetBSD: Makefile,v 1.5 2005/04/11 21:47:49 tv Exp $
#

DISTNAME=	mod_access_referer-1.0.2
PKGNAME=	ap-access-referer-1.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=accessreferer/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://accessreferer.sourceforge.net/
COMMENT=	Apache module for referer-based access control


APACHE_MODULE_NAME=	mod_access_referer.so

DOCDIR=		${PREFIX}/share/doc

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/html/mod_access_referer
	${INSTALL_DATA} ${WRKSRC}/mod_access_referer.html		\
		${DOCDIR}/html/mod_access_referer

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
