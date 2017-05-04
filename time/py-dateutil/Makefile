# $NetBSD: Makefile,v 1.17 2017/05/04 19:45:57 adam Exp $

DISTNAME=	python-dateutil-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-dateutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dateutil.readhedocs.org/
COMMENT=	Extensions to the standard datetime module
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
