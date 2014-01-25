# $NetBSD: Makefile,v 1.10 2014/01/25 10:30:26 wiz Exp $

DISTNAME=	python-dateutil-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	http://labix.org/download/python-dateutil/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://labix.org/python-dateutil
COMMENT=	Extensions to the standard datetime module (Python-2.x version)

EGG_NAME=	${DISTNAME:S/-/_/}
PYTHON_VERSIONS_INCOMPATIBLE=	33

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
