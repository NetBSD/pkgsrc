# $NetBSD: Makefile,v 1.12 2008/09/08 15:14:21 ahoka Exp $
#

.include "Makefile.common"

PKGREVISION=		7
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
