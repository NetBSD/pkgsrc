# $NetBSD: Makefile,v 1.19 2014/06/10 15:22:17 joerg Exp $

DISTNAME=	${VERSION}
PKGNAME=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-wsgi-${VERSION}
CATEGORIES=	www python
MASTER_SITES=	https://github.com/GrahamDumpleton/mod_wsgi/archive/

MAINTAINER=	jan.m.danielsson@gmail.com
HOMEPAGE=	https://code.google.com/p/modwsgi/
COMMENT=	WSGI module for apache
LICENSE=	apache-2.0

APACHE_MODULE=	yes
VERSION=	4.1.3
DIST_SUBDIR=	mod_wsgi
WRKSRC=		${WRKDIR}/mod_wsgi-${VERSION}

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:Q}

PKG_APACHE_ACCEPTED=	apache22 apache24

.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
