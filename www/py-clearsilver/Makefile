# $NetBSD: Makefile,v 1.4 2005/04/06 05:28:40 epg Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}

.include "../../www/clearsilver/Makefile.common"

DEPENDS+=			${CLEARSILVER_BASE}:../../www/clearsilver-base

CONFIGURE_ARGS+=		--enable-python
CONFIGURE_ARGS+=		--with-python=${PYTHONBIN}

MAKE_FLAGS+=			PYTHON_SITE=${LOCALBASE}/${PYSITELIB}

INSTALL_DIRS=			${WRKSRC}/python

PY_PATCHPLIST=			YES
PYBINMODULE=			YES
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
