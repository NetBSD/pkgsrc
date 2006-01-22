# $NetBSD: Makefile,v 1.38 2006/01/22 04:13:33 joerg Exp $
#

DISTNAME=		gnome-themes-2.12.1
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-themes/2.12/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Collection of themes and icons for GNOME 2

CONFLICTS+=		clearlooks-metacity-[0-9]*

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5 theme-1.0
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Smokey-Red
	cd ${PREFIX}/share/icons/Smokey-Red && ${INSTALL_DATA_DIR} \
	    96x96/filesystems 72x72/filesystems 64x64/filesystems \
	    48x48/filesystems 48x48/emblems
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Smokey-Blue
	cd ${PREFIX}/share/icons/Smokey-Blue && ${INSTALL_DATA_DIR} \
	    96x96/filesystems 72x72/filesystems 64x64/filesystems \
	    48x48/emblems
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Sandy
	cd ${PREFIX}/share/icons/Sandy && ${INSTALL_DATA_DIR} \
	    96x96/filesystems 72x72/filesystems \
	    48x48/filesystems 36x36/filesystems 24x24/filesystems \
	    12x12/filesystems
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/LowContrastLargePrint/48x48
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/HighContrastLargePrintInverse/48x48
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/HighContrastLargePrint/48x48
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Flat-Blue
	cd ${PREFIX}/share/icons/Flat-Blue && ${INSTALL_DATA_DIR} \
	    96x96/filesystems 72x72/filesystems 72x72/devices \
	    48x48/filesystems 48x48/emblems \
	    48x48/devices 36x36/filesystems 36x36/emblems \
	    24x24/filesystems 24x24/emblems 20x20/filesystems \
	    192x192/filesystems 12x12/filesystems 12x12/emblems scalable/emblems
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/Crux
	cd ${PREFIX}/share/icons/Crux && ${INSTALL_DATA_DIR} \
	    96x96/filesystems 96x96/emblems 72x72/filesystems 72x72/emblems \
	    48x48/filesystems 48x48/emblems 36x36/filesystems \
	    24x24/filesystems 192x192/filesystems 12x12/filesystems

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2-engines/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
