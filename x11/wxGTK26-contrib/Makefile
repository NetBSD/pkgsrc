# $NetBSD: Makefile,v 1.27 2015/04/25 14:25:20 tnn Exp $
#

.include "../../x11/wxGTK26/Makefile.common"

PKGNAME=	${DISTNAME:S/wxGTK/wxGTK-contrib/}
PKGREVISION=	27
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Contrib libraries for wxWidgets GTK

USE_TOOLS+=		gmake

BUILD_DIRS=		contrib/src

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
