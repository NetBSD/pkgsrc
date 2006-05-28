# $NetBSD: Makefile,v 1.13 2006/05/28 00:26:27 rh Exp $
#
.include "Makefile.common"
PKGREVISION=		10

COMMENT=		Objective-C interface to the GTK+ widget set

USE_LANGUAGES=		objc

BUILD_DIRS=		${WRKSRC}/GToolKit

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/gnustep-make/gnustep.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
