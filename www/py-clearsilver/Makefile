# $NetBSD: Makefile,v 1.18 2014/01/25 10:30:27 wiz Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=			1

.include "../../www/clearsilver/Makefile.common"

CONFIGURE_ARGS+=		--enable-python
CONFIGURE_ARGS+=		--with-python=${PYTHONBIN:Q}

MAKE_FLAGS+=			PYTHON_SITE=${LOCALBASE}/${PYSITELIB}
CFLAGS+=			-fPIC

INSTALL_DIRS=			python

PY_PATCHPLIST=			YES
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.10.5

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
