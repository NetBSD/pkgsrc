# $NetBSD: Makefile,v 1.13 2011/12/03 00:02:17 joerg Exp $

DISTNAME=	mod_wsgi-${VERSION}
PKGNAME=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-wsgi-${VERSION}
CATEGORIES=	www python
MASTER_SITES=	http://modwsgi.googlecode.com/files/

MAINTAINER=	jan.m.danielsson@gmail.com
HOMEPAGE=	http://modwsgi.googlecode.com/
COMMENT=	WSGI module for apache
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

APACHE_MODULE=	yes
VERSION=	3.3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:Q}

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
