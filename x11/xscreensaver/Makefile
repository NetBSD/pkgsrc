# $NetBSD: Makefile,v 1.79 2006/05/21 15:19:31 jlam Exp $

COMMENT=	Screen saver and locker for the X window system
PKGREVISION=	5

CONFLICTS+=	xscreensaver-gnome<4.14
# man/man1/barcode.1
CONFLICTS+=	barcode-[0-9]*

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

.include "options.mk"
.include "../../textproc/libxml2/buildlink3.mk"

# Remove useless locale files that have no translations in them.
post-extract:
	cd ${WRKSRC}/po && ${RM} -f ca.po pt_BR.po

.include "../../mk/bsd.pkg.mk"
