# $NetBSD: Makefile,v 1.11 2007/01/11 15:12:53 joerg Exp $
#

.include "Makefile.common"

PKGREVISION=		6
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
