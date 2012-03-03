# $NetBSD: Makefile,v 1.12 2012/03/03 00:12:30 wiz Exp $
#

.include "../../x11/wxGTK26/Makefile.common"

PKGNAME=		${DISTNAME:S/wxGTK/wxGTK-contrib/}
PKGREVISION=		13
MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GTK-based implementation of the wxWidgets GUI library (contrib libraries)

USE_TOOLS+=		gmake

BUILD_DIRS=		contrib/src

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
