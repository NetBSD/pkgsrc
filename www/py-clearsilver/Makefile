# $NetBSD: Makefile,v 1.11 2008/04/25 20:39:13 joerg Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=			1

.include "../../www/clearsilver/Makefile.common"

CONFIGURE_ARGS+=		--enable-python
CONFIGURE_ARGS+=		--with-python=${PYTHONBIN:Q}

MAKE_FLAGS+=			PYTHON_SITE=${LOCALBASE}/${PYSITELIB}
CFLAGS+=			-fPIC

INSTALL_DIRS=			${WRKSRC}/python

PY_PATCHPLIST=			YES
PYBINMODULE=			YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
