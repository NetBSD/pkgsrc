# $NetBSD: Makefile,v 1.3 2019/08/24 18:10:50 schmonz Exp $

PKGNAME=		${PYPKGPREFIX}-${PKGNAME_MODULE}
COMMENT=		Python bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/python/

DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../lang/python/pyversion.mk"

.if (${PYPKGPREFIX} == py27)
CONFIGURE_ARGS+=	--with-python
PYTHON_3_OR_PYTHON=	python
.else
CONFIGURE_ARGS+=	--with-python3 PYTHON3=${PYTHONBIN}
PYTHON_3_OR_PYTHON=	python3
.endif

PLIST_SUBST+=		PYTHON_3_OR_PYTHON=${PYTHON_3_OR_PYTHON:Q}
PY_PATCHPLIST=		yes

REPLACE_PYTHON=		python/docs/examples/*.py

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/${PYTHON_3_OR_PYTHON}/examples/*.py
.if (${PYPKGPREFIX} != py27)
	${MKDIR} ${DESTDIR}${PREFIX}/${PYSITELIB}/xapian/__pycache__
	${MV} ${DESTDIR}${PREFIX}/${PYSITELIB}/xapian/*.cpython* ${DESTDIR}${PREFIX}/${PYSITELIB}/xapian/__pycache__/
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
