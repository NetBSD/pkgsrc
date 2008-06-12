# $NetBSD: Makefile,v 1.4 2008/06/12 02:14:56 joerg Exp $
#

DISTNAME=		web.py-0.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www python
MASTER_SITES=		http://webpy.org/

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://webpy.org/
COMMENT=		Simple, public domain web publishing system

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	25 24

WRKSRC=			${WRKDIR}/${DISTNAME}
#PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
