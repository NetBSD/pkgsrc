# $NetBSD: Makefile,v 1.3 2021/02/03 01:09:31 gutteridge Exp $

DISTNAME=	python-Levenshtein-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-Levenshtein/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ztane/python-Levenshtein
COMMENT=	Python extension for computing string edit distances
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
