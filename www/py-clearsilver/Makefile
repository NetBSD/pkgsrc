# $NetBSD: Makefile,v 1.14 2009/03/05 18:51:33 joerg Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../www/clearsilver/Makefile.common"

CONFIGURE_ARGS+=		--enable-python
CONFIGURE_ARGS+=		--with-python=${PYTHONBIN:Q}

MAKE_FLAGS+=			PYTHON_SITE=${LOCALBASE}/${PYSITELIB}
CFLAGS+=			-fPIC

INSTALL_DIRS=			${WRKSRC}/python

PY_PATCHPLIST=			YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
