# $NetBSD: Makefile,v 1.16 2013/06/04 22:17:30 tron Exp $
#

.include "../../x11/vte/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	x11 python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for the Vte terminal widget
LICENSE=	gnu-lgpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ARGS+=	--disable-freetype-test
CONFIGURE_ARGS+=	--enable-Bsymbolic=auto

BUILD_DIRS=	python

pre-build:
	${LN} -s ${BUILDLINK_DIR}/lib/libvte.la ${WRKSRC}/src/libvte.la

.include "../../x11/py-gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.vte+=	vte>=${PKGVERSION_NOREV}
.include "../../x11/vte/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
