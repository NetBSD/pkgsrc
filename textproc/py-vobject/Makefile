# $NetBSD: Makefile,v 1.8 2011/03/01 11:29:05 wiz Exp $
#

DISTNAME=	vobject-0.8.1c
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://vobject.skyhouseconsulting.com/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://vobject.skyhouseconsulting.com/
COMMENT=	Python iCalendar (ics) and vCard library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.1:../../time/py-dateutil


PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
