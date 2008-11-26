# $NetBSD: Makefile,v 1.83 2008/11/26 20:52:33 jnemeth Exp $
#

DISTNAME=		gnome-desktop-2.24.1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-desktop/2.24/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Common GNOME2 desktop files and libgnome-desktop library

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_DATA} ${FILESDIR}/${f} ${DESTDIR}${PREFIX}/share/pixmaps/${f}
.endfor

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
# gnome-about needs py-gnome2-desktop at runtime, which needs us, so
# we have a circular dependency. To work around this, just depend on
# Python and hope that py-gnome2-desktop gets the same version.
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
