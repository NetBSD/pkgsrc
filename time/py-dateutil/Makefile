# $NetBSD: Makefile,v 1.14 2015/01/11 21:05:30 wiz Exp $

DISTNAME=	python-dateutil-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-dateutil/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dateutil.readhedocs.org/
COMMENT=	Extensions to the standard datetime module
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
