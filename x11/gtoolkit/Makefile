# $NetBSD: Makefile,v 1.4 2004/01/03 18:49:57 reed Exp $
#
.include "Makefile.common"
PKGREVISION=		2

COMMENT=		Objective-C interface to the GTK+ widget set

BUILD_DIRS=		${WRKSRC}/GToolKit

.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
