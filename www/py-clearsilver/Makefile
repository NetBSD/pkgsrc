# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 00:00:49 epg Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}

.include "../../www/clearsilver/Makefile.common"

DEPENDS+=			${CLEARSILVER_BASE}:../../www/clearsilver

CONFIGURE_ARGS+=		--enable-python
CONFIGURE_ARGS+=		--with-python=${PYTHONBIN}

INSTALL_DIRS=			${WRKSRC}/python

PY_PATCHPLIST=			YES
PYBINMODULE=			YES
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
