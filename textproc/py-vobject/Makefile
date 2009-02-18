# $NetBSD: Makefile,v 1.1.1.1 2009/02/18 16:38:41 kleink Exp $
#

DISTNAME=	vobject-0.8.1b
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://vobject.skyhouseconsulting.com/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://vobject.skyhouseconsulting.com/
COMMENT=	Python iCalendar library

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.1:../../time/py-dateutil

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
