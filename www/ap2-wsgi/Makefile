# $NetBSD: Makefile,v 1.16 2014/01/25 10:30:26 wiz Exp $

DISTNAME=	mod_wsgi-${VERSION}
PKGNAME=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-wsgi-${VERSION}
CATEGORIES=	www python
MASTER_SITES=	http://modwsgi.googlecode.com/files/

MAINTAINER=	jan.m.danielsson@gmail.com
HOMEPAGE=	http://modwsgi.googlecode.com/
COMMENT=	WSGI module for apache
LICENSE=	apache-2.0

APACHE_MODULE=	yes
VERSION=	3.4

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:Q}

PKG_APACHE_ACCEPTED=	apache2 apache22 apache24

.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
