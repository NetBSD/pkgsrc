# $NetBSD: Makefile,v 1.1 2014/01/16 10:26:00 wiz Exp $

DISTNAME=	python-dateutil-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	http://labix.org/download/python-dateutil/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://labix.org/python-dateutil
COMMENT=	Extensions to the standard datetime module (Python-3.x version)
LICENSE=	modified-bsd

EGG_NAME=	${DISTNAME:S/-/_/}

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	26 27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
