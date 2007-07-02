# $NetBSD: Makefile,v 1.1.1.1 2007/07/02 18:05:24 wiz Exp $
#

DISTNAME=	python-dateutil-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	http://labix.org/download/python-dateutil/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://labix.org/python-dateutil
COMMENT=	Extensions to the standard datetime module

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	24 23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
