# $NetBSD: Makefile,v 1.26 2005/05/22 20:08:49 jlam Exp $
#

DISTNAME=	pygtk-2.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pygtk/gtk2/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygtk/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for GTK+2

CONFLICTS=	${PYPKGPREFIX}-gtk<0.6.10

PY_PATCHPLIST=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	pygtk-2.0.pc.in pygobject-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
USE_TOOLS+=	gmake

PYTHON_VERSIONS_ACCEPTED=	24 23

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
