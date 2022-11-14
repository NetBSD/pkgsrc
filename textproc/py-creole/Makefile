# $NetBSD: Makefile,v 1.16 2022/11/14 18:21:46 wiz Exp $

DISTNAME=	python-creole-1.4.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-creole/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jedie/python-creole
COMMENT=	Markup converter in pure Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-textile-[0-9]*:../../textproc/py-textile
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=		# none

REPLACE_PYTHON+=	creole/*.py
REPLACE_PYTHON+=	creole/*/*.py

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

# as of 1.4.10
# FAILED (failures=9, errors=6, expected failures=10)
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
