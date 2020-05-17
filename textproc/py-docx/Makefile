# $NetBSD: Makefile,v 1.5 2020/05/17 21:38:46 adam Exp $

DISTNAME=	python-docx-0.8.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-docx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-openxml/python-docx
COMMENT=	Python library for Microsoft Word (.docx) files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml>=2.3.2:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-behave-[0-9]*:../../devel/py-behave
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
