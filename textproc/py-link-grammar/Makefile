# $NetBSD: Makefile,v 1.8 2024/04/29 00:12:29 ryoon Exp $

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

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
