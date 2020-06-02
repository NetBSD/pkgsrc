# $NetBSD: Makefile,v 1.55 2020/06/02 08:25:02 adam Exp $

DISTNAME=	pygtksourceview-2.10.1
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
PKGREVISION=	30
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygtksourceview/2.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Python bindings for gtksourceview2
LICENSE=	gnu-lgpl-v2

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_LIBTOOL=			YES
PKGCONFIG_OVERRIDE+=		pygtksourceview-2.0.pc.in
GNU_CONFIGURE=			YES
USE_TOOLS+=			pkg-config
PY_PATCHPLIST=			YES
PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2

.include "../../lang/python/extension.mk"

BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.15.2
.include "../../devel/py-gobject/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview2+=	gtksourceview2>=2.3.0
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
