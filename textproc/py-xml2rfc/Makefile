# $NetBSD: Makefile,v 1.3 2021/12/30 13:05:40 adam Exp $

DISTNAME=	xml2rfc-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xml2rfc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tools.ietf.org/tools/xml2rfc/trac/
COMMENT=	IETF RFC 7749 XML-to-RFC conversion too
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-fonttools via py-weasyprint

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-configargparse>=1.2.3:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-country>=1.8,!=19.7.15:../../geography/py-country
DEPENDS+=	${PYPKGPREFIX}-flakes>=0.8.1:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-google-i18n-address>=2.3.2:../../devel/py-google-i18n-address
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.0.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-intervaltree>=2.1.0,!=3.0.0:../../devel/py-intervaltree
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11,<3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-kitchen>=1.2.6:../../devel/py-kitchen
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.8,!=4.3.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-setuptools>=24.2.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml

TEST_DEPENDS+=	${PYPKGPREFIX}-PDF2>=0:../../print/py-PDF2
TEST_DEPENDS+=	${PYPKGPREFIX}-cairo>=0:../../graphics/py-cairo
TEST_DEPENDS+=	${PYPKGPREFIX}-decorator>=0:../../devel/py-decorator
TEST_DEPENDS+=	${PYPKGPREFIX}-dict2xml>=0:../../devel/py-dict2xml
TEST_DEPENDS+=	${PYPKGPREFIX}-tox>=0:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-weasyprint>=0:../../print/py-weasyprint

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC} && \
	${PYTHONBIN} -m unittest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
