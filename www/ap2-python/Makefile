# $NetBSD: Makefile,v 1.12 2005/12/05 23:55:22 rillig Exp $

DISTNAME=	mod_python-${VERSION}
PKGNAME=	ap2-${PYPKGPREFIX}-python-${VERSION}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE:=httpd/modpython/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Apache module that embeds the Python interpreter

USE_LIBTOOL=	YES
USE_PKGINSTALL=	YES
APACHE_MODULE=	YES
VERSION=	3.1.3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=--with-python=${PYTHONBIN:Q}

PYTHON_VERSIONS_ACCEPTED=	24 23
PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../www/apache2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
