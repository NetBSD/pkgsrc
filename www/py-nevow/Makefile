# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:50 wiz Exp $
#

DISTNAME=		nevow-0.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www python
MASTER_SITES=		http://www.divmod.org/users/release/divmod/

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://nevow.com/
COMMENT=		Next-generation web application templating system

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted
DEPENDS+=		${PYPKGPREFIX}-xml>=0.8.3:../../textproc/py-xml

WRKSRC=			${WRKDIR}/${DISTNAME}
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
