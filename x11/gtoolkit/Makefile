# $NetBSD: Makefile,v 1.2 2002/11/09 13:43:48 wiz Exp $
#
.include "Makefile.common"

COMMENT=		Objective-C interface to the GTK+ widget set

BUILD_DIRS=		${WRKSRC}/GToolKit

.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
