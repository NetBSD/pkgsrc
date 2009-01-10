# $NetBSD: Makefile,v 1.57 2009/01/10 23:13:44 adrianp Exp $
#

DISTNAME=	pygtk-2.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pygtk/gtk2/}
PKGREVISION=	3
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygtk/2.13/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for GTK+2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	${PYPKGPREFIX}-gtk<0.6.10

PY_PATCHPLIST=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	pygtk-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}
USE_TOOLS+=	gmake pkg-config
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

PYTHON_VERSIONS_ACCEPTED=	25 24

BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.15.3

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.if ${PYTHON_VERSION_DEFAULT} == "25"
PLIST_SRC+=	${PKGDIR}/PLIST.python25
.endif

post-build:
	${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
