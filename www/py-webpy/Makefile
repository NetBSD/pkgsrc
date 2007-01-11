# $NetBSD: Makefile,v 1.2 2007/01/11 11:30:00 joerg Exp $
#

DISTNAME=		web.py-0.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www python
MASTER_SITES=		http://webpy.org/

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://webpy.org/
COMMENT=		Simple, public domain web publishing system

PYTHON_VERSIONS_ACCEPTED=	24

WRKSRC=			${WRKDIR}/${DISTNAME}
#PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
