# $NetBSD: Makefile,v 1.1.1.1 2005/05/03 13:19:19 drochner Exp $
#

DISTNAME=	gnome-python-extras-2.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gnome-python/gnome2/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python-extras/2.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python binding for GNOME2

PY_PATCHPLIST=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	gnome-python-extras-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	24 23

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
# XXX optional? or firefox?
#.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
# XXX not yet existing
#.include "../../devel/gdl/buildlink3.mk"
# XXX not yet (totem-gst vs totem-xine?)
#.include "../../multimedia/totem/buildlink3.mk"
.include "../../sysutils/libgtop2/buildlink3.mk"
.include "../../sysutils/nautilus-cd-burner/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
