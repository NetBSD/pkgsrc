# $NetBSD: Makefile,v 1.77 2019/08/11 13:25:21 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-demo-/}
PKGREVISION=	5
COMMENT=	Demo viewer and configuration tool for xscreensaver

CONFLICTS+=	xscreensaver<4.14 xscreensaver-gnome-[0-9]*

.include "../../x11/xscreensaver/Makefile.common"

USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-gtk=${BUILDLINK_PREFIX.gtk2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

BUILD_DIRS=		utils driver
INSTALL_DIRS=		driver
INSTALL_TARGET=		install-gnome

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/applications

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driver/xscreensaver-demo \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/driver/xscreensaver-demo.man \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xscreensaver-demo.1
	${INSTALL_DATA} ${FILESDIR}/xscreensaver-demo.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/xscreensaver-demo.desktop

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
