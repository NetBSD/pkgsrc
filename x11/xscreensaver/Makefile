# $NetBSD: Makefile,v 1.76 2005/09/18 21:31:21 jlam Exp $

COMMENT=	Screen saver and locker for the X window system
PKGREVISION=	2

CONFLICTS+=	xscreensaver-gnome<4.14
# man/man1/barcode.1
CONFLICTS+=	barcode-[0-9]*

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "../../textproc/libxml2/buildlink3.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.xscreensaver
PKG_SUPPORTED_OPTIONS=	pam
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif

.include "../../mk/bsd.pkg.mk"

.if exists(${WRKSRC}/po/ca.gmo)
PLIST_SUBST+=           OLD_GETTEXT=
.else
PLIST_SUBST+=           OLD_GETTEXT="@comment "
.endif
