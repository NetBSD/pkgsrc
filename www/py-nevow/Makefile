# $NetBSD: Makefile,v 1.14 2013/04/06 19:42:42 rodent Exp $
#

VERSION=		0.10.0
DISTNAME=		Nevow-${VERSION}
PKGNAME=		${PYPKGPREFIX}-nevow-${VERSION}
PKGREVISION=		1
CATEGORIES=		www python
# Nevow does not appear to make tarballs easily available; there's a link
# in trac with ?format=raw at the end.  Many others have the same sorts
# of issues, so ride on their redistribution.
MASTER_SITES=		http://tahoe-lafs.org/source/tahoe-lafs/deps/tahoe-dep-sdists/
EXTRACT_SUFX=		.tar.bz2
LICENSE=		mit

MAINTAINER=		gdt@ir.bbn.com
HOMEPAGE=		http://divmod.org/trac/wiki/DivmodNevow
COMMENT=		Next-generation web application templating system

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted
DEPENDS+=		${PYPKGPREFIX}-xml>=0.8.3:../../textproc/py-xml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
