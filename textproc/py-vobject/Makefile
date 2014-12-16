# $NetBSD: Makefile,v 1.14 2014/12/16 13:23:19 wiz Exp $

DISTNAME=	vobject-0.8.1c
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	http://vobject.skyhouseconsulting.com/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://vobject.skyhouseconsulting.com/
COMMENT=	Python iCalendar (ics) and vCard library
LICENSE=	apache-2.0

PYTHON_VERSIONED_DEPENDENCIES=	dateutil
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.8.1c

PYTHON_SELF_CONFLICT=	yes
EGG_NAME=	${DISTNAME}0

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
