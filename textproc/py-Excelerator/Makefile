# $NetBSD: Makefile,v 1.8 2012/02/04 12:03:32 obache Exp $
#

DISTNAME=	pyexcelerator-${VERSION}
PKGNAME=	${PYPKGPREFIX}-Excelerator-${VERSION}
VERSION=	0.6.4.1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyexcelerator/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pyexcelerator/
COMMENT=	Python library for generating Excel 97/2000/XP/2003 files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	#none

EGG_NAME=	pyExcelerator-${VERSION}

REPLACE_PYTHON+=	pyExcelerator/BIFFRecords.py
REPLACE_PYTHON+=	pyExcelerator/Bitmap.py
REPLACE_PYTHON+=	pyExcelerator/Cell.py
REPLACE_PYTHON+=	pyExcelerator/Column.py
REPLACE_PYTHON+=	pyExcelerator/CompoundDoc.py
REPLACE_PYTHON+=	pyExcelerator/ExcelFormula.py
REPLACE_PYTHON+=	pyExcelerator/ExcelFormulaLexer.py
REPLACE_PYTHON+=	pyExcelerator/ExcelMagic.py
REPLACE_PYTHON+=	pyExcelerator/Formatting.py
REPLACE_PYTHON+=	pyExcelerator/ImportXLS.py
REPLACE_PYTHON+=	pyExcelerator/Row.py
REPLACE_PYTHON+=	pyExcelerator/Style.py
REPLACE_PYTHON+=	pyExcelerator/UnicodeUtils.py
REPLACE_PYTHON+=	pyExcelerator/Workbook.py
REPLACE_PYTHON+=	pyExcelerator/Worksheet.py
REPLACE_PYTHON+=	pyExcelerator/__init__.py

INSTALLATION_DIRS=	share/doc/py-Excelerator share/examples/py-Excelerator

post-install:
	for f in CHANGES.txt LICENSE.txt README.txt THANKS.txt TODO.txt ; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/share/doc/py-Excelerator/ ; \
	done
	for f in ${WRKSRC}/examples/*.py ${WRKSRC}/tools/*.py ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/examples/py-Excelerator/ ; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
