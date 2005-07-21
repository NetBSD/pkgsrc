# $NetBSD: Makefile,v 1.74 2005/07/21 10:43:23 tron Exp $

COMMENT=	Screen saver and locker for the X window system
PKGREVISION=	1

CONFLICTS+=	xscreensaver-gnome<4.14
# man/man1/barcode.1
CONFLICTS+=	barcode-[0-9]*

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.if exists(${PREFIX}/${PKGLOCALEDIR}/locale/ca/LC_MESSAGES/xscreensaver.mo)
PLIST_SUBST+=           OLD_GETTEXT=
.else
PLIST_SUBST+=           OLD_GETTEXT="@comment "
.endif

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
