# $NetBSD: Makefile,v 1.8 2005/03/24 21:13:03 wiz Exp $

DISTNAME=	mod_python-${VERSION}
PKGNAME=	ap2-${PYPKGPREFIX}-python-${VERSION}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD:=modpython/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Apache module that embeds the Python interpreter

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
USE_PKGINSTALL=	YES
APACHE_MODULE=	YES
VERSION=	3.1.3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}"
CONFIGURE_ARGS+=--with-python=${PYTHONBIN:Q}

PYTHON_VERSIONS_ACCEPTED=	24 23
PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../www/apache2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
