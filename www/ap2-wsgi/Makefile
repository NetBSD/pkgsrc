# $NetBSD: Makefile,v 1.4 2007/12/18 01:00:13 gdt Exp $
#

DISTNAME=	mod_wsgi-${VERSION}
PKGNAME=        ${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-wsgi-${VERSION}
CATEGORIES=	www python
MASTER_SITES=	http://modwsgi.googlecode.com/files/

MAINTAINER=	jan.m.danielsson@gmail.com
HOMEPAGE=	http://modwsgi.googlecode.com/
COMMENT=	WSGI module for apache

USE_LIBTOOL=	yes
APACHE_MODULE=	yes
VERSION=	1.3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=--with-python=${PYTHONBIN:Q}

PYTHON_VERSIONS_ACCEPTED=	24 23

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
