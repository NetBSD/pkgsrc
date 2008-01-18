# $NetBSD: Makefile,v 1.15 2008/01/18 05:10:06 tnn Exp $
#

DISTNAME=	gnome-python-desktop-2.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python/2/}
PKGREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python-desktop/2.20/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python modules for the GNOME desktop

GNU_CONFIGURE=	yes
PY_PATCHPLIST=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

DEPENDS+=	bug-buddy>=2.16:../../net/bug-buddy

PKGCONFIG_OVERRIDE+=	gnome-python-desktop-2.0.pc.in

PYTHON_VERSIONS_ACCEPTED=	24

# XXX not yet, needs hal
PLIST_SUBST+=	NAUTILUSBURN="@comment "
#.include "../../sysutils/nautilus-cd-burner/buildlink3.mk"

.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../multimedia/totem/buildlink3.mk"
.include "../../multimedia/gnome-media/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
# disabled in configure script by default
# CONFIGURE_ARGS+=	--enable-metacity
#.include "../../wm/metacity/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
