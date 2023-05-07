# $NetBSD: Makefile,v 1.11 2023/05/07 10:53:22 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${PKGNAME_MODULE}
PKGREVISION=	1
COMMENT=	Python bindings for Xapian search engine
HOMEPAGE=	https://xapian.org/docs/bindings/python/

DEPENDS+=	${PYPKGPREFIX}-sphinx>=7:../../textproc/py-sphinx

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
