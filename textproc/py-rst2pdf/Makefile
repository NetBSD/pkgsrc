# $NetBSD: Makefile,v 1.1 2017/03/16 20:00:39 darcy Exp $

DISTNAME=      rst2pdf-0.93
PKGNAME=       ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=    python textproc
MASTER_SITES=  ${MASTER_SITE_PYPI:=r/rst2pdf/}

MAINTAINER=    darcy@NetBSD.org
HOMEPAGE=      http://rst2pdf.ralsina.me/stories/index.html
COMMENT=       Convert restructured text to PDF via reportlab
LICENSE=       mit

USE_LANGUAGES=      # none
PYTHON_VERSIONS_INCOMPATIBLE= 33 34 35 36
REPLACE_PYTHON= rst2pdf/__init__.py

DEPENDS+= ${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+= ${PYPKGPREFIX}-pdfrw-[0-9]*:../../textproc/py-pdfrw
DEPENDS+= ${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+= ${PYPKGPREFIX}-reportlab-[0-9]*:../../print/py-reportlab
DEPENDS+= ${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/rst2pdf ${DESTDIR}${PREFIX}/bin/rst2pdf-${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}/${PREFIX}/${PYSITELIB}/rst2pdf-0.93.dev0-py2.7.egg-info ${DESTDIR}/${PREFIX}/${PYSITELIB}/rst2pdf-0.93-py2.7.egg-info

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
