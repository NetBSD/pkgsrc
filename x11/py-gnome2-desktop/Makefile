# $NetBSD: Makefile,v 1.123 2018/11/14 22:22:48 kleink Exp $

DISTNAME=	gnome-python-desktop-2.32.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python/2/}
PKGREVISION=	61
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python-desktop/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Python modules for the GNOME desktop

GNU_CONFIGURE=	yes
PY_PATCHPLIST=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

#DEPENDS+=	bug-buddy>=2.16:../../net/bug-buddy

PKGCONFIG_OVERRIDE+=	gnome-python-desktop-2.0.pc.in

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gtk2

.include "../../lang/python/pyversion.mk"

# The "real" value here is: 27
# but because of single-version deps of gnome bits this will only
# ever work for the python version those gnome bits were built with.
PYTHON_VERSIONS_REALLY_ACCEPTED=27
PYTHON_VERSIONS_ACCEPTED=	${PYTHON_VERSION_DEFAULT:M27}

.include "options.mk"

.include "../../lang/python/extension.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../multimedia/gnome-media/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
# works, but should better be in its own pkg to limit dependencies
#.include "../../sysutils/brasero/buildlink3.mk"
BUILDLINK_API_DEPENDS.evince+=	evince>=2.32<2.33
.include "../../print/evince/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
# disabled in configure script by default
# CONFIGURE_ARGS+=	--enable-metacity
#.include "../../wm/metacity/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
