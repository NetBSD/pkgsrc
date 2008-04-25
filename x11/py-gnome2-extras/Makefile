# $NetBSD: Makefile,v 1.26 2008/04/25 18:47:25 tnn Exp $
#

DISTNAME=	gnome-python-extras-2.14.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gnome-python/gnome2/}
PKGREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python-extras/2.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python binding for GNOME2

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	gnome-python-extras-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}
USE_TOOLS+=		pkg-config gmake

PYTHON_VERSIONS_ACCEPTED=	25 24

SUBST_CLASSES+=	ffhome
SUBST_STAGE.ffhome=	pre-configure
SUBST_FILES.ffhome=	gtkmozembed/gtkmozembedmodule.c
SUBST_VARS.ffhome=	LOCALBASE

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
# seamonkey untested.
#.include "../../www/seamonkey/buildlink3.mk"
.include "../../www/firefox/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../devel/gdl/buildlink3.mk"
# needs older version than is in pkgsrc
#.include "../../databases/libgda/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
# currently do not compile
#.include "../../wip/libgksu/buildlink3.mk"
#.include "../../wip/libgksuui/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
