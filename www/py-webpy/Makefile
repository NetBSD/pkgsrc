# $NetBSD: Makefile,v 1.6 2011/06/14 09:04:13 obache Exp $
#

DISTNAME=		web.py-0.23
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		www python
MASTER_SITES=		http://webpy.org/static/

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://webpy.org/
COMMENT=		Simple, public domain web publishing system

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/webpy
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
