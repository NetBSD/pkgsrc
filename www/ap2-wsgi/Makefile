# $NetBSD: Makefile,v 1.7 2008/09/12 05:41:59 epg Exp $
#

DISTNAME=	mod_wsgi-${VERSION}
PKGNAME=        ${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-wsgi-${VERSION}
CATEGORIES=	www python
MASTER_SITES=	http://modwsgi.googlecode.com/files/

MAINTAINER=	jan.m.danielsson@gmail.com
HOMEPAGE=	http://modwsgi.googlecode.com/
COMMENT=	WSGI module for apache

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
APACHE_MODULE=	yes
VERSION=	2.3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=--with-python=${PYTHONBIN:Q}

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
