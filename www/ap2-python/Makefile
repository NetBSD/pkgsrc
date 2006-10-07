# $NetBSD: Makefile,v 1.18 2006/10/07 21:01:16 reed Exp $

DISTNAME=	mod_python-${VERSION}
PKGREVISION=	1
PKGNAME=	ap2-${PYPKGPREFIX}-python-${VERSION}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE:=httpd/modpython/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Apache module that embeds the Python interpreter

USE_LIBTOOL=	YES
APACHE_MODULE=	YES
VERSION=	3.2.8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=--with-python=${PYTHONBIN:Q}

PYTHON_VERSIONS_ACCEPTED=	24 23
PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../www/apache2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
