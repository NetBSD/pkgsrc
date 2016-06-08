# $NetBSD: Makefile,v 1.8 2016/06/08 17:43:40 wiz Exp $

VERS=		1.0.5
DISTNAME=	python-creole-${VERS}
PKGNAME=	${PYPKGPREFIX}-creole-${VERS}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-creole/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://code.google.com/p/python-creole/
COMMENT=	Creole <-> HTML converter

LICENSE=	gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
DEPENDS+=		${PYPKGPREFIX}-textile>=0:../../textproc/py-textile

USE_LANGUAGES=		#none

SUBST_CLASSES+=		env
SUBST_SED.env=		-e "s,\#! */usr/bin/env  *python[0-9.]*,\#!${PYTHONBIN},"
SUBST_MESSAGE.env=	Fixing path to python.
SUBST_STAGE.env=	post-patch
SUBST_FILES.env=	creole/exceptions.py
SUBST_FILES.env+=	creole/html2creole/emitter.py
SUBST_FILES.env+=	creole/html2rest/emitter.py
SUBST_FILES.env+=	creole/html2textile/emitter.py
SUBST_FILES.env+=	creole/html_parser/parser.py
SUBST_FILES.env+=	creole/html_tools/deentity.py
SUBST_FILES.env+=	creole/html_tools/strip_html.py
SUBST_FILES.env+=	creole/html_tools/text_tools.py
SUBST_FILES.env+=	creole/rest2html/clean_writer.py
SUBST_FILES.env+=	creole/shared/base_emitter.py
SUBST_FILES.env+=	creole/shared/document_tree.py
SUBST_FILES.env+=	creole/shared/unknown_tags.py
SUBST_FILES.env+=	creole/tests/__init__.py
SUBST_FILES.env+=	creole/tests/all_tests.py
SUBST_FILES.env+=	creole/tests/test_creole2html.py
SUBST_FILES.env+=	creole/tests/test_cross_compare_all.py
SUBST_FILES.env+=	creole/tests/test_cross_compare_creole.py
SUBST_FILES.env+=	creole/tests/test_cross_compare_rest.py
SUBST_FILES.env+=	creole/tests/test_cross_compare_textile.py
SUBST_FILES.env+=	creole/tests/test_html2creole.py
SUBST_FILES.env+=	creole/tests/test_html2rest.py
SUBST_FILES.env+=	creole/tests/test_html2textile.py
SUBST_FILES.env+=	creole/tests/test_rest2html.py
SUBST_FILES.env+=	creole/tests/test_setup_utils.py
SUBST_FILES.env+=	creole/tests/test_utils.py

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
