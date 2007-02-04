# $NetBSD: Makefile,v 1.1.1.1 2007/02/04 09:33:42 wiz Exp $
#

DISTNAME=	gnome-python-desktop-2.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python/2/}
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://ftp.gnome.org/pub/gnome/sources/gnome-python-desktop/2.16/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftp.gnome.org/pub/gnome/sources/gnome-python-desktop/2.16/
COMMENT=	Python modules for the GNOME desktop

GNU_CONFIGURE=	yes
PY_PATCHPLIST=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gnome-python-desktop-2.0.pc.in

.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../multimedia/totem/buildlink3.mk"
.include "../../multimedia/gnome2-media/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/libgtop2/buildlink3.mk"
# needs 2.15.3, pkgsrc is 2.14
#.include "../../sysutils/nautilus-cd-burner/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
