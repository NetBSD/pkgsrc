# $NetBSD: Makefile,v 1.1.1.1 2004/07/17 01:11:36 darcy Exp $
# FreeBSD Id: ports/www/mod_python3/Makefile,v 1.28 2004/03/11 14:36:30 perky Exp

DISTNAME=		mod_python-${VERSION}
PKGNAME=    	ap2-${PYPKGPREFIX}-python-${VERSION}
CATEGORIES=		www python
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD:=modpython/}
EXTRACT_SUFX=	.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.modpython.org/
COMMENT=		Apache module that embeds the Python interpreter

USE_BUILDLINK3= YES
USE_PKGINSTALL= YES
APACHE_MODULE=  YES
VERSION=3.1.3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs="${APXS}"
ONFIGURE_ARGS+=-
PYTHON_VERSIONS_ACCEPTED= 23 23pth
PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../www/apache2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

