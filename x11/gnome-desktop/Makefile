# $NetBSD: Makefile,v 1.51 2006/03/30 21:47:15 jmmv Exp $
#

DISTNAME=		gnome-desktop-2.14.0
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-desktop/2.14/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Common GNOME2 desktop files and libgnome-desktop library

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:run pkg-config
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-gnome-distributor="The NetBSD Foundation"

BUILDLINK_DEPENDS.glib2+=	glib2>=2.8.0

post-install:
.for f in netbsd-logo-icon.png netbsd-logo-icon-transparent.png
	${INSTALL_DATA} ${FILESDIR}/${f} ${PREFIX}/share/pixmaps/${f}
.endfor

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
