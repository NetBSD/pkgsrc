# $NetBSD: Makefile,v 1.6 2024/06/13 05:15:58 adam Exp $

DISTNAME=	ramlfications-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ramlfications/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ramlfications.readthedocs.io/
COMMENT=	Python RAML parser
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-inflect-[0-9]*:../../lang/py-inflect
DEPENDS+=	${PYPKGPREFIX}-jsonref-[0-9]*:../../textproc/py-jsonref
DEPENDS+=	${PYPKGPREFIX}-markdown2-[0-9]*:../../textproc/py-markdown2
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-termcolor-[0-9]*:../../devel/py-termcolor
DEPENDS+=	${PYPKGPREFIX}-xmltodict-[0-9]*:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-localserver-[0-9]*:../../devel/py-test-localserver

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ramlfications ramlfications-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
