# $NetBSD: Makefile,v 1.13 2008/10/06 01:04:29 minskim Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}

PKG_DESTDIR_SUPPORT=	user-destdir

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
