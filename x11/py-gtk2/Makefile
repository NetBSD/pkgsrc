# $NetBSD: Makefile,v 1.85 2012/09/07 19:17:50 adam Exp $
#

DISTNAME=	pygtk-2.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pygtk/gtk2/}
PKGREVISION=	6
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygtk/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pygtk.org/
COMMENT=	Python bindings for GTK+2
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	${PYPKGPREFIX}-gtk<0.6.10

PY_PATCHPLIST=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	pygtk-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}
USE_TOOLS+=	gmake pkg-config

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.15.3
.include "../../devel/py-gobject/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.16.0
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
