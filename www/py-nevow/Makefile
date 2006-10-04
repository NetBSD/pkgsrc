# $NetBSD: Makefile,v 1.6 2006/10/04 22:04:10 wiz Exp $
#

DISTNAME=		nevow-0.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www python
MASTER_SITES=		http://www.divmod.org/users/release/divmod/

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://divmod.org/trac/wiki/DivmodNevow
COMMENT=		Next-generation web application templating system

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted
DEPENDS+=		${PYPKGPREFIX}-xml>=0.8.3:../../textproc/py-xml

PYTHON_VERSIONS_ACCEPTED=	24 23

WRKSRC=			${WRKDIR}/${DISTNAME}
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
