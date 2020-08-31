# $NetBSD: Makefile,v 1.29 2020/08/31 18:13:15 wiz Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=			4

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
