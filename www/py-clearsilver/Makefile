# $NetBSD: Makefile,v 1.28 2019/09/02 13:20:02 adam Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=			3

.include "../../www/clearsilver/Makefile.common"

CONFIGURE_ARGS+=		--enable-python
CONFIGURE_ARGS+=		--with-python=${PYTHONBIN:Q}

MAKE_FLAGS+=			PYTHON_SITE=${LOCALBASE}/${PYSITELIB}
CFLAGS+=			-fPIC

INSTALL_DIRS=			python

PY_PATCHPLIST=			YES
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.10.5

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
