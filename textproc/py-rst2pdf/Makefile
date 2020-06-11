# $NetBSD: Makefile,v 1.6 2020/06/11 10:30:41 adam Exp $

DISTNAME=	rst2pdf-0.97
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rst2pdf/}

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

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} rst2pdf rst2pdf-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
