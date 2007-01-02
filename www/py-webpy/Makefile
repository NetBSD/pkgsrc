# $NetBSD: Makefile,v 1.1 2007/01/02 14:07:45 darcy Exp $
#

DISTNAME=		web.py-0.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		www python
MASTER_SITES=		http://webpy.org/

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://webpy.org/
COMMENT=		Simple, public domain web publishing system

PYTHON_VERSIONS_ACCEPTED=	24 23 22

WRKSRC=			${WRKDIR}/${DISTNAME}
#PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
