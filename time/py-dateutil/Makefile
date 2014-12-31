# $NetBSD: Makefile,v 1.13 2014/12/31 13:57:30 wiz Exp $

DISTNAME=	python-dateutil-2.3
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
