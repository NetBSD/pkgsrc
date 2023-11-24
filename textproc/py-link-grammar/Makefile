# $NetBSD: Makefile,v 1.4 2023/11/24 13:39:55 ryoon Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding of syntactic parsing library

.include "../../textproc/link-grammar/Makefile.common"

DEPENDS+=	link-grammar-[0-9]*:../../textproc/link-grammar

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_DEPMETHOD.python=	full

CONFIGURE_ARGS+=	--enable-python-bindings
CONFIGURE_ARGS+=	PYTHON_VERSION=${PYVERSSUFFIX}

PY_PATCHPLIST=	yes
INSTALL_DIRS+=	bindings/python

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
