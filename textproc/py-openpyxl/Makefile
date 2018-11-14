# $NetBSD: Makefile,v 1.17 2018/11/14 09:09:47 adam Exp $

DISTNAME=	openpyxl-2.5.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openpyxl/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://openpyxl.readthedocs.io/
COMMENT=	Python library to read/write Excel 2007 xlsx/xlsm files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jdcal-[0-9]*:../../time/py-jdcal
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

SUBST_CLASSES+=		requires
SUBST_STAGE.requires=	post-install
SUBST_FILES.requires=	${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/requires.txt
SUBST_SED.requires=	-e '/et_xmlfile/d'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
