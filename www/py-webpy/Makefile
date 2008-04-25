# $NetBSD: Makefile,v 1.3 2008/04/25 20:39:13 joerg Exp $
#

DISTNAME=		web.py-0.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www python
MASTER_SITES=		http://webpy.org/

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://webpy.org/
COMMENT=		Simple, public domain web publishing system

PYTHON_VERSIONS_ACCEPTED=	25 24

WRKSRC=			${WRKDIR}/${DISTNAME}
#PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
