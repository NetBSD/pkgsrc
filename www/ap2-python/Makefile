# $NetBSD: Makefile,v 1.14 2006/01/24 07:32:43 wiz Exp $

DISTNAME=	mod_python-${VERSION}
PKGNAME=	ap2-${PYPKGPREFIX}-python-${VERSION}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE:=httpd/modpython/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Apache module that embeds the Python interpreter

USE_LIBTOOL=	YES
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
