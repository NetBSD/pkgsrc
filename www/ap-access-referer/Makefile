# $NetBSD: Makefile,v 1.6 2006/01/24 07:32:41 wiz Exp $
#

DISTNAME=	mod_access_referer-1.0.2
PKGNAME=	ap-access-referer-1.0.2
PKGREVISION=	1
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
