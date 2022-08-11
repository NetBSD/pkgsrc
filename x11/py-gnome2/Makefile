# $NetBSD: Makefile,v 1.134 2022/08/11 05:09:32 gutteridge Exp $

DISTNAME=	gnome-python-2.28.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gnome-python/gnome2/}
PKGREVISION=	51
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Python binding for GNOME2

PY_PATCHPLIST=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	gnome-python-2.0.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
USE_TOOLS+=		pkg-config gmake

PYTHON_VERSIONS_ACCEPTED=	27 # py-ORBit, py-gtk2

BUILDLINK_TRANSFORM.SunOS+=	rm:-std=c9x

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.11.1
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
BUILDLINK_API_DEPENDS.pyorbit+=	${PYPKGPREFIX}-ORBit>=2.0.1
.include "../../net/py-ORBit/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-vfs+=	gnome-vfs>=2.9.3
.include "../../sysutils/gnome-vfs/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.6.2
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
