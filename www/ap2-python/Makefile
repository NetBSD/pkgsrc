# $NetBSD: Makefile,v 1.21 2007/06/30 16:09:09 joerg Exp $

DISTNAME=	mod_python-${VERSION}
PKGNAME=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-python-${VERSION}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE:=httpd/modpython/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Apache module that embeds the Python interpreter

USE_LIBTOOL=	YES
APACHE_MODULE=	YES
VERSION=	3.2.10

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=--with-python=${PYTHONBIN:Q}

PYTHON_VERSIONS_ACCEPTED=	24 23
PY_PATCHPLIST=	YES

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
