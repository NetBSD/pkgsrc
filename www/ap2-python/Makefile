# $NetBSD: Makefile,v 1.29 2013/08/09 13:02:02 prlw1 Exp $

DISTNAME=	mod_python-${VERSION}
PKGNAME=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-python-${VERSION}
CATEGORIES=	www python
MASTER_SITES=	http://archive.apache.org/dist/httpd/modpython/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Apache module that embeds the Python interpreter
LICENSE=	apache-2.0

MAKE_JOBS_SAFE=	no

USE_LIBTOOL=	YES
APACHE_MODULE=	YES
VERSION=	3.3.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=--with-python=${PYTHONBIN:Q}

PY_PATCHPLIST=	YES

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
