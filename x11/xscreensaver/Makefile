# $NetBSD: Makefile,v 1.95 2012/07/03 18:34:05 drochner Exp $

COMMENT=	Screen saver and locker for the X window system

CONFLICTS+=	xscreensaver-gnome<4.14

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"
.include "options.mk"
.include "../../textproc/libxml2/buildlink3.mk"

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

EGDIR=			${PREFIX}/share/examples/xscreensaver
MESSAGE_SUBST+=		EGDIR=${EGDIR:Q}

# Remove useless locale files that have no translations in them.
post-extract:
	cd ${WRKSRC}/po && ${RM} -f ca.po pt_BR.po

INSTALLATION_DIRS=	${EGDIR}/pam.d

post-install:
	${INSTALL_DATA} ${FILESDIR}/pam-xscreensaver-NetBSD \
	    ${DESTDIR}${EGDIR}/pam.d/xscreensaver-NetBSD

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
