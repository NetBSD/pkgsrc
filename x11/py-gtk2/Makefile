# $NetBSD: Makefile,v 1.6 2003/08/25 19:26:10 recht Exp $
#

DISTNAME=	pygtk-1.99.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pygtk/gtk2/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygtk/1.99/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for GTK+2

CONFLICTS=	${PYPKGPREFIX}-gtk<0.6.10

PY_PATCHPLIST=	YES
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pygtk-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth
BUILDLINK_DEPENDS.python22-pth=	python22-pth>=2.2.2nb2

.include "../../devel/libglade2/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/gtkglarea2/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
