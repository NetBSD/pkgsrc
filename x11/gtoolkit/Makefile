# $NetBSD: Makefile,v 1.3 2003/07/13 13:54:05 wiz Exp $
#
.include "Makefile.common"
PKGREVISION=		1

COMMENT=		Objective-C interface to the GTK+ widget set

BUILD_DIRS=		${WRKSRC}/GToolKit

.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
