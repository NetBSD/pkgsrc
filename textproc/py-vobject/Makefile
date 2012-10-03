# $NetBSD: Makefile,v 1.9 2012/10/03 23:55:20 cheusov Exp $
#

DISTNAME=	vobject-0.8.1c
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	http://vobject.skyhouseconsulting.com/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://vobject.skyhouseconsulting.com/
COMMENT=	Python iCalendar (ics) and vCard library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		${PYPKGPREFIX}-dateutil>=1.1:../../time/py-dateutil
PYTHON_SELF_CONFLICT=	yes

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
