# $NetBSD: Makefile,v 1.19 2004/10/03 00:18:37 tv Exp $
#

DISTNAME=	gnome-python-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gnome-python/gnome2/}
PKGREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python binding for GNOME2

PY_PATCHPLIST=	YES
USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	gnome-python-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth
BUILDLINK_DEPENDS.python22-pth=	python22-pth>=2.2.2nb2

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/py-ORBit/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
