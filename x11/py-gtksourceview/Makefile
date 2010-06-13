# $NetBSD: Makefile,v 1.10 2010/06/13 22:45:49 wiz Exp $

DISTNAME=	pygtksourceview-2.8.0
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
PKGREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygtksourceview/2.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for gtksourceview2
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	pygtksourceview-2.0.pc.in
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config
PY_PATCHPLIST=	YES

PYTHON_VERSIONS_ACCEPTED=	26 25

.include "../../lang/python/extension.mk"

BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.15.2
.include "../../devel/py-gobject/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview2+=	gtksourceview2>=2.3.0
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
