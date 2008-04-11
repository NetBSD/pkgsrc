# $NetBSD: Makefile,v 1.10 2008/04/11 15:27:22 abs Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	15 20

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
