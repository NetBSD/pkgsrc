# $NetBSD: Makefile,v 1.47 2018/11/14 22:22:53 kleink Exp $
#

.include "../../x11/xvidcap/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-gtk2-/}
PKGREVISION=		41
COMMENT=		Capture X display to individual frames or MPEG video (GTK2 version)

CONFLICTS+=		xvidcap<1.1.3nb3

CONFIGURE_ARGS+=	--with-gtk2
USE_TOOLS+=		pkg-config
LDFLAGS.DragonFly=	-lXt -lX11
LDFLAGS.Linux+=		-lXt -lX11

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
