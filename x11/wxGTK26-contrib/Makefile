# $NetBSD: Makefile,v 1.23 2013/06/06 12:53:51 wiz Exp $
#

.include "../../x11/wxGTK26/Makefile.common"

PKGNAME=	${DISTNAME:S/wxGTK/wxGTK-contrib/}
PKGREVISION=	23
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Contrib libraries for wxWidgets GTK

USE_TOOLS+=		gmake

BUILD_DIRS=		contrib/src

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
