# $NetBSD: Makefile,v 1.88 2009/03/16 12:35:59 jmcneill Exp $
#

DISTNAME=		gnome-desktop-2.25.92
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-desktop/2.25/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Common GNOME2 desktop files and libgnome-desktop library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_TOOLS+=		automake autoconf aclocal autoreconf m4
USE_LIBTOOL=		yes

AUTOCONF_REQD=		2.62

CONFIGURE_ARGS+=	--with-gnome-distributor="The NetBSD Foundation"

BUILD_DEPENDS+=		gettext-m4>=0.14.6:../../devel/gettext-m4

pre-configure:
	cd ${WRKSRC} && autoconf -f
	cd ${WRKSRC} && autoheader -f

post-install:
.for f in netbsd-logo-icon.png netbsd-logo-icon-transparent.png
	${INSTALL_DATA} ${FILESDIR}/${f} ${DESTDIR}${PREFIX}/share/pixmaps/${f}
.endfor

.include "../../devel/GConf/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.4
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.11.3
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXrandr+=	libXrandr>=1.2
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
# gnome-about needs py-gnome2-desktop at runtime, which needs us, so
# we have a circular dependency. To work around this, just depend on
# Python and hope that py-gnome2-desktop gets the same version.
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
