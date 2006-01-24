# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:54 wiz Exp $
#
.include "Makefile.common"
PKGREVISION=		8

COMMENT=		Objective-C interface to the GTK+ widget set

BUILD_DIRS=		${WRKSRC}/GToolKit

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/gnustep-make/gnustep.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
