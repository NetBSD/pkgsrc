# $NetBSD: Makefile,v 1.15 2011/12/01 20:53:54 gls Exp $

PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=			1

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
