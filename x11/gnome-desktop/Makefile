# $NetBSD: Makefile,v 1.75 2008/01/11 13:16:03 drochner Exp $
#

DISTNAME=		gnome-desktop-2.20.3
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-desktop/2.20/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Common GNOME2 desktop files and libgnome-desktop library

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-gnome-distributor="The NetBSD Foundation"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0

post-install:
.for f in netbsd-logo-icon.png netbsd-logo-icon-transparent.png
	${INSTALL_DATA} ${FILESDIR}/${f} ${PREFIX}/share/pixmaps/${f}
.endfor

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
