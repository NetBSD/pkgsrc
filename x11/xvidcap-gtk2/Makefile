# $NetBSD: Makefile,v 1.31 2013/10/10 14:42:40 ryoon Exp $
#

.include "../../x11/xvidcap/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-gtk2-/}
PKGREVISION=		26
COMMENT=		Capture X display to individual frames or MPEG video (GTK2 version)

CONFLICTS+=		xvidcap<1.1.3nb3

CONFIGURE_ARGS+=	--with-gtk2
USE_TOOLS+=		pkg-config
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
