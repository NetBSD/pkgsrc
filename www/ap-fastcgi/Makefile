# $NetBSD: Makefile,v 1.22 2003/02/17 18:02:21 grant Exp $
#

DISTNAME=	mod_fastcgi_2.2.10
PKGNAME=	ap-fastcgi-2.2.10
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fastcgi.com/
COMMENT=	New, improved CGI-like interface module for Apache

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_fastcgi.so
APACHE_MODULE_SRC=	*.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/mod_fastcgi.html \
		${PREFIX}/share/httpd/htdocs/manual/mod/

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
