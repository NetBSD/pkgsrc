# $NetBSD: Makefile,v 1.18 2012/02/06 12:42:32 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/xvidcap/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-gtk2-/}
PKGREVISION=		14
COMMENT=		Capture X display to individual frames or MPEG video (GTK2 version)

CONFLICTS+=		xvidcap<1.1.3nb3

CONFIGURE_ARGS+=	--with-gtk2
USE_TOOLS+=		pkg-config
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
