# $NetBSD: Makefile,v 1.22 2017/01/01 14:44:04 wiz Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=			1

.include "../../www/clearsilver/Makefile.common"

CONFIGURE_ARGS+=		--enable-python
CONFIGURE_ARGS+=		--with-python=${PYTHONBIN:Q}

MAKE_FLAGS+=			PYTHON_SITE=${LOCALBASE}/${PYSITELIB}
CFLAGS+=			-fPIC

INSTALL_DIRS=			python

PY_PATCHPLIST=			YES
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.10.5

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
