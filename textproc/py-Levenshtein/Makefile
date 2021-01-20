# $NetBSD: Makefile,v 1.2 2021/01/20 09:09:41 adam Exp $

DISTNAME=	python-Levenshtein-0.12.1
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
