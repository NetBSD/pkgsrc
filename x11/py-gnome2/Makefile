# $NetBSD: Makefile,v 1.24 2005/04/26 21:05:08 drochner Exp $
#

DISTNAME=	gnome-python-2.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gnome-python/gnome2/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python/2.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python binding for GNOME2

PY_PATCHPLIST=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	gnome-python-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	24 23

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../net/py-ORBit/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
