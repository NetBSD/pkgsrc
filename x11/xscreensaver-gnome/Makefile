# $NetBSD: Makefile,v 1.21 2003/11/12 01:31:53 salo Exp $
#

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	1
COMMENT=	Screen saver and locker for the X window system (with GNOME support)

CONFLICTS+=	xscreensaver-[0-9]*

.include "../../x11/xscreensaver/Makefile.common"

# so that the screensaver.desktop rule in ``configure'' works
USE_GMAKE=	YES

CONFIGURE_ARGS+=	--with-gtk=${BUILDLINK_PREFIX.gtk}
CONFIGURE_ARGS+=	--with-pixbuf=${BUILDLINK_PREFIX.gdk-pixbuf}
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-gnome=${BUILDLINK_PREFIX.gnome-libs}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/share/control-center/screensavers

PLIST_SRC=	${.CURDIR}/PLIST

# Very ugly hack so that GTK2 is not found, since the package does not support
# choosing GTK1 over GTK2 (which is needed, since gnome-libs link against GTK1).
pre-configure:
	cd ${WRKSRC} && ${SED} -e "s/have_gtk2=yes/have_gtk=no/g" \
			       -e "s/HAVE_GTK2/DUMMY_HAVE_GTK2/g" configure \
			> configure.patched && \
	${MV} configure.patched configure && ${CHMOD} 755 configure

post-install:
	cd ${WRKSRC}/driver && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} xxxinstall-gnome

.include "../../devel/libglade/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/controlcenter/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
