# $NetBSD: Makefile,v 1.5 2003/12/28 23:37:07 jmmv Exp $
#

DISTNAME=	gnome-python-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gnome-python/gnome2/}
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python binding for GNOME2

PY_PATCHPLIST=	YES
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gnome-python-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth
BUILDLINK_DEPENDS.python22-pth=	python22-pth>=2.2.2nb2

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../net/py-ORBit/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../sysutils/nautilus/buildlink2.mk"
.include "../../x11/libzvt/buildlink2.mk"
.include "../../x11/gnome-panel/buildlink2.mk"
.include "../../x11/py-gtk2/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
