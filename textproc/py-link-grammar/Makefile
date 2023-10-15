# $NetBSD: Makefile,v 1.1 2023/10/15 06:40:28 ryoon Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding of syntactic parsing library

.include "../../textproc/link-grammar/Makefile.common"

DEPENDS+=	link-grammar-[0-9]*:../../textproc/link-grammar

BUILDLINK_DEPMETHOD.python=	full

CONFIGURE_ARGS+=	--enable-python-bindings

PY_PATCHPLIST=	yes
INSTALL_DIRS+=	bindings/python

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
