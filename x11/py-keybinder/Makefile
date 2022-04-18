# $NetBSD: Makefile,v 1.24 2022/04/18 19:10:17 adam Exp $

PKGREVISION= 16
.include "../../x11/keybinder/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for the keybinder library
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	--disable-lua
CONFIGURE_ARGS+=	--enable-python

PY_PATCHPLIST=			yes
PYTHON_VERSIONS_ACCEPTED=	27

INSTALL_DIRS=	python-keybinder

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/keybinder/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
