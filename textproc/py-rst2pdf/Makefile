# $NetBSD: Makefile,v 1.5 2019/06/10 15:39:44 adam Exp $

DISTNAME=	rst2pdf-0.94.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
# PyPI distfile does not include images, styles, and templates
#MASTER_SITES=	${MASTER_SITE_PYPI:=r/rst2pdf/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=rst2pdf/}
GITHUB_PROJECT=	rst2pdf

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://rst2pdf.org/
COMMENT=	Convert restructured text to PDF via reportlab
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pdfrw-[0-9]*:../../textproc/py-pdfrw
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-reportlab-[0-9]*:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-smartypants-[0-9]*:../../textproc/py-smartypants
TEST_DEPENDS+=	${PYPKGPREFIX}-PDF2-[0-9]*:../../print/py-PDF2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

# setup.cfg contains only 'tag_build = .dev', which we don't want.
pre-configure:
	${RM} ${WRKSRC}/setup.cfg

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} rst2pdf rst2pdf-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
