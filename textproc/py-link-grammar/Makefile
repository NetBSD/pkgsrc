# $NetBSD: Makefile,v 1.9 2025/09/30 13:33:29 ryoon Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding of syntactic parsing library

.include "../../textproc/link-grammar/Makefile.common"

DEPENDS+=	link-grammar-[0-9]*:../../textproc/link-grammar

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_DEPMETHOD.python=	full

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} > 311
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
.endif

CONFIGURE_ARGS+=	--enable-python-bindings
CONFIGURE_ARGS+=	PYTHON_VERSION=${PYVERSSUFFIX}

PY_PATCHPLIST=	yes
INSTALL_DIRS+=	bindings/python

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/linkgrammar/*.opt-2.pyc
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/linkgrammar/__pycache__/*.opt-2.pyc

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
