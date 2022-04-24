# $NetBSD: Makefile,v 1.8 2022/04/24 17:23:07 adam Exp $

DISTNAME=	xml2rfc-3.12.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xml2rfc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ietf-tools/xml2rfc
COMMENT=	IETF RFC 7749 XML-to-RFC conversion tool
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-configargparse>=1.2.3:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-country>=1.8:../../geography/py-country
DEPENDS+=	${PYPKGPREFIX}-flakes>=0.8.1:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-google-i18n-address>=2.3.2:../../devel/py-google-i18n-address
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.0.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-intervaltree>=2.1.0:../../devel/py-intervaltree
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-kitchen>=1.2.6:../../devel/py-kitchen
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.3.2:../../textproc/py-lxml
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

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-fonttools via py-weasyprint

do-test:
	${RUN} cd ${WRKSRC} && ${PYTHONBIN} -m unittest

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} xml2rfc xml2rfc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
