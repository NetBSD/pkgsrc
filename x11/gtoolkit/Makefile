# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:35 joerg Exp $
#
.include "Makefile.common"
PKGREVISION=		9

COMMENT=		Objective-C interface to the GTK+ widget set

BUILD_DIRS=		${WRKSRC}/GToolKit

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/gnustep-make/gnustep.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
