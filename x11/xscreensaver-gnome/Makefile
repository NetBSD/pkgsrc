# $NetBSD: Makefile,v 1.24 2003/12/18 13:49:17 atatat Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/}
COMMENT=	Screen saver and locker for the X window system (GNOME applet)
PKGREVISION=	1

CONFLICTS+=	xscreensaver<4.14 xscreensaver-demo-[0-9]*

.include "../../x11/xscreensaver/Makefile.common"

# so that the screensaver.desktop rule in ``configure'' works
USE_GMAKE=	YES

CONFIGURE_ARGS+=	--with-gtk=${BUILDLINK_PREFIX.gtk}
CONFIGURE_ARGS+=	--with-pixbuf=${BUILDLINK_PREFIX.gdk-pixbuf}
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-gnome=${BUILDLINK_PREFIX.gnome-libs}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/share/control-center/screensavers

BUILD_DIRS=		${WRKSRC}/utils ${WRKSRC}/driver
INSTALL_DIRS=		${WRKSRC}/driver
INSTALL_TARGET=		install-gnome xxxinstall-gnome

# Very ugly hack so that GTK2 is not found, since the package does not support
# choosing GTK1 over GTK2 (which is needed, since gnome-libs link against GTK1).
pre-configure:
	cd ${WRKSRC} && ${SED} -e "s/have_gtk2=yes/have_gtk=no/g" \
			       -e "s/HAVE_GTK2/DUMMY_HAVE_GTK2/g" configure \
			> configure.patched && \
	${MV} configure.patched configure && ${CHMOD} 755 configure

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driver/xscreensaver-demo ${PREFIX}/bin
	${LN} -s ${BUILDLINK_PREFIX.xscreensaver}/libexec/xscreensaver/config \
		${PREFIX}/share/control-center/screensavers

.include "../../devel/libglade/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/controlcenter/buildlink2.mk"
.include "../../x11/xscreensaver/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
