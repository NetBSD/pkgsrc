# $NetBSD: Makefile,v 1.24 2003/06/02 01:16:09 jschauma Exp $
#

DISTNAME=	mod_fastcgi_2.2.10
PKGNAME=	ap-fastcgi-2.2.10
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.fastcgi.com/
COMMENT=	New, improved CGI-like interface module for Apache

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_fastcgi.so

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/mod_fastcgi.html \
		${PREFIX}/share/httpd/htdocs/manual/mod/

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
