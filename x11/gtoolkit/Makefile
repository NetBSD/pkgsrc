# $NetBSD: Makefile,v 1.7 2004/04/17 00:26:48 rh Exp $
#
.include "Makefile.common"
PKGREVISION=		5

COMMENT=		Objective-C interface to the GTK+ widget set

BUILD_DIRS=		${WRKSRC}/GToolKit

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/gnustep-make/gnustep.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
