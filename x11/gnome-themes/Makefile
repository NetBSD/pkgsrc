# $NetBSD: Makefile,v 1.59 2008/04/15 18:09:07 drochner Exp $
#

DISTNAME=		gnome-themes-2.22.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-themes/2.22/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Collection of themes and icons for GNOME 2

CONFLICTS+=		clearlooks-metacity-[0-9]*

USE_DIRS+=		gnome2-1.5 theme-1.0 xdg-1.4
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

dont-pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Smokey-Red
.for f in 96x96/filesystems 72x72/filesystems 64x64/filesystems \
    48x48/filesystems 48x48/emblems
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Smokey-Red/${f}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Smokey-Blue
.for f in 96x96/filesystems 72x72/filesystems 64x64/filesystems \
    48x48/emblems
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Smokey-Blue/${f}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Sandy
.for f in 96x96/filesystems 72x72/filesystems 48x48/filesystems \
    36x36/filesystems 24x24/filesystems 12x12/filesystems
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Sandy/${f}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/LowContrastLargePrint/48x48
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/HighContrastLargePrintInverse/48x48
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/HighContrastLargePrint/48x48
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Flat-Blue
.for f in 96x96/filesystems 72x72/filesystems 72x72/devices 48x48/filesystems \
    48x48/emblems 48x48/devices 36x36/filesystems 36x36/emblems \
    24x24/filesystems 24x24/emblems 20x20/filesystems \
    192x192/filesystems 12x12/filesystems 12x12/emblems scalable/emblems
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Flat-Blue/${f}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Crux
.for f in 96x96/filesystems 96x96/emblems 72x72/filesystems 72x72/emblems \
    48x48/filesystems 48x48/emblems 36x36/filesystems \
    24x24/filesystems 192x192/filesystems 12x12/filesystems
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Crux/${f}
.endfor

BUILDLINK_API_DEPENDS.gtk2-engines+=    gtk2-engines>=2.9.0

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2-engines/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
