# $NetBSD: Makefile,v 1.7 2024/02/10 10:13:42 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding of syntactic parsing library

.include "../../textproc/link-grammar/Makefile.common"

DEPENDS+=	link-grammar-[0-9]*:../../textproc/link-grammar

# not for 3.12: tries to use distutils
PYTHON_VERSIONS_INCOMPATIBLE=	27 312

BUILDLINK_DEPMETHOD.python=	full

CONFIGURE_ARGS+=	--enable-python-bindings
CONFIGURE_ARGS+=	PYTHON_VERSION=${PYVERSSUFFIX}

PY_PATCHPLIST=	yes
INSTALL_DIRS+=	bindings/python

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
