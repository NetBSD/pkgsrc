# $NetBSD: Makefile,v 1.10 2022/09/24 19:11:20 schmonz Exp $

PKGNAME=	${PYPKGPREFIX}-${PKGNAME_MODULE}
COMMENT=	Python bindings for Xapian search engine
HOMEPAGE=	https://xapian.org/docs/bindings/python/

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27

CONFIGURE_ARGS+=	--with-python3 PYTHON3=${PYTHONBIN}

PY_PATCHPLIST=		yes
PYTHON_SELF_CONFLICT=	yes

REPLACE_PYTHON=		python/docs/examples/*.py

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/python3/examples/*.py
	${MKDIR} ${DESTDIR}${PREFIX}/${PYSITELIB}/xapian/__pycache__
	${MV} ${DESTDIR}${PREFIX}/${PYSITELIB}/xapian/*.cpython* ${DESTDIR}${PREFIX}/${PYSITELIB}/xapian/__pycache__/

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
