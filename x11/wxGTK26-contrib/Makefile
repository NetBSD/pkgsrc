# $NetBSD: Makefile,v 1.24 2013/09/02 19:50:47 adam Exp $
#

.include "../../x11/wxGTK26/Makefile.common"

PKGNAME=	${DISTNAME:S/wxGTK/wxGTK-contrib/}
PKGREVISION=	24
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Contrib libraries for wxWidgets GTK

USE_TOOLS+=		gmake

BUILD_DIRS=		contrib/src

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
