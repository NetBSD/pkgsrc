# $NetBSD: Makefile,v 1.12 2014/12/13 09:28:01 obache Exp $

DISTNAME=	python-dateutil-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-dateutil/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dateutil.readhedocs.org/
COMMENT=	Extensions to the standard datetime module
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
