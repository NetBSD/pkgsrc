# $NetBSD: Makefile,v 1.18 2015/07/01 13:47:46 wiz Exp $

VERSION=		0.11.1
DISTNAME=		Nevow-${VERSION}
PKGNAME=		${PYPKGPREFIX}-nevow-${VERSION}
CATEGORIES=		www python
# Nevow does not appear to make tarballs easily available; there's a link
# in trac with ?format=raw at the end.  Many others have the same sorts
# of issues, so ride on their redistribution.
MASTER_SITES=		https://tahoe-lafs.org/source/tahoe-lafs/deps/tahoe-lafs-dep-sdists/

MAINTAINER=		gdt@ir.bbn.com
HOMEPAGE=		http://divmod.org/trac/wiki/DivmodNevow
COMMENT=		Next-generation web application templating system
LICENSE=		mit

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted
DEPENDS+=		${PYPKGPREFIX}-xml>=0.8.3:../../textproc/py-xml

REPLACE_PYTHON=		nevow/test/segfault.py

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-twisted py-xml

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
