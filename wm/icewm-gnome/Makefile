# $NetBSD: Makefile,v 1.18 2003/06/03 17:13:35 jmmv Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
COMMENT=	Small, fast and light-weight window manager (GNOME version)

CONFLICTS+=	icewm-[0-9]* icewm-imlib-[0-9]*

.include "../icewm/Makefile.common"

CONFIGURE_ARGS+=	--with-gnome-menus=yes
CONFIGURE_ARGS+=	--with-imlib=yes
CONFIGURE_ARGS+=	--with-xpm=no

.include "../../graphics/imlib/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
