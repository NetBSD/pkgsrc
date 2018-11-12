# $NetBSD: Makefile,v 1.47 2018/11/12 03:53:12 ryoon Exp $

DISTNAME=	pygtksourceview-2.10.1
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
PKGREVISION=	25
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygtksourceview/2.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Python bindings for gtksourceview2
LICENSE=	gnu-lgpl-v2

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	pygtksourceview-2.0.pc.in
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config
PY_PATCHPLIST=	YES
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

.include "../../lang/python/extension.mk"

BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.15.2
.include "../../devel/py-gobject/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview2+=	gtksourceview2>=2.3.0
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
