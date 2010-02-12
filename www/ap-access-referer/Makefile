# $NetBSD: Makefile,v 1.10 2010/02/12 20:56:54 joerg Exp $
#

DISTNAME=	mod_access_referer-1.0.2
PKGNAME=	ap13-access-referer-1.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=accessreferer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://accessreferer.sourceforge.net/
COMMENT=	Apache module for referer-based access control

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ap-access-referer-[0-9]*

APACHE_MODULE_NAME=	mod_access_referer.so

DOCDIR=		${PREFIX}/share/doc

INSTALLATION_DIRS+=	lib/httpd ${DOCDIR}/html/mod_access_referer

do-install:
	${INSTALL_LIB} ${WRKSRC}/mod_access_referer.so 			\
	    ${DESTDIR}${PREFIX}/lib/httpd
	${INSTALL_DATA} ${WRKSRC}/mod_access_referer.html		\
	    ${DESTDIR}${DOCDIR}/html/mod_access_referer

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
