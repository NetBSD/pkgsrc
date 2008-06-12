# $NetBSD: Makefile,v 1.8 2008/06/12 02:14:56 joerg Exp $
#

DISTNAME=		nevow-0.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www python
MASTER_SITES=		http://www.divmod.org/users/release/divmod/

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://divmod.org/trac/wiki/DivmodNevow
COMMENT=		Next-generation web application templating system

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted
DEPENDS+=		${PYPKGPREFIX}-xml>=0.8.3:../../textproc/py-xml

WRKSRC=			${WRKDIR}/${DISTNAME}
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
