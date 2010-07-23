# $NetBSD: Makefile,v 1.10 2010/07/23 21:35:41 gdt Exp $
#

VERSION=		0.10.0
DISTNAME=		Nevow-${VERSION}
PKGNAME=		${PYPKGPREFIX}-nevow-${VERSION}
CATEGORIES=		www python
# Nevow does not appear to make tarballs easily available; there's a link
# in trac with ?format=raw at the end.  Many others have the same sorts
# of issues, so ride on their redistribution.
MASTER_SITES=		http://tahoe-lafs.org/source/tahoe-lafs/deps/tahoe-dep-sdists/
EXTRACT_SUFX=		.tar.bz2
LICENSE=		mit

MAINTAINER=		sifu@0xx0.net
#MAINTAINER+=		gdt@ir.bbn.com
HOMEPAGE=		http://divmod.org/trac/wiki/DivmodNevow
COMMENT=		Next-generation web application templating system

PKG_DESTDIR_SUPPORT=	user-destdir

# Upstream docs are not clear.  Add versions as they are tested.
PYTHON_VERSIONS_ACCEPTED=	26

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted
DEPENDS+=		${PYPKGPREFIX}-xml>=0.8.3:../../textproc/py-xml

WRKSRC=			${WRKDIR}/${DISTNAME}
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PY_NO_EGG=		no

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
