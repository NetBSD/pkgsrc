# $NetBSD: Makefile,v 1.26 2019/04/26 14:12:48 maya Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=			2

.include "../../www/clearsilver/Makefile.common"

CONFIGURE_ARGS+=		--enable-python
CONFIGURE_ARGS+=		--with-python=${PYTHONBIN:Q}

MAKE_FLAGS+=			PYTHON_SITE=${LOCALBASE}/${PYSITELIB}
CFLAGS+=			-fPIC

INSTALL_DIRS=			python

PY_PATCHPLIST=			YES
PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.10.5

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
