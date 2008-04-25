# $NetBSD: Makefile,v 1.2 2008/04/25 20:39:13 joerg Exp $
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

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
