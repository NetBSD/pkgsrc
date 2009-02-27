# $NetBSD: Makefile,v 1.5 2009/02/27 00:05:02 kleink Exp $
#

DISTNAME=	vobject-0.8.1c
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://vobject.skyhouseconsulting.com/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://vobject.skyhouseconsulting.com/
COMMENT=	Python iCalendar library

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.1:../../time/py-dateutil

PYTHON_VERSIONS_ACCEPTED=	25 24

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
