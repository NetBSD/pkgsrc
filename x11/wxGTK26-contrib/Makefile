# $NetBSD: Makefile,v 1.26 2014/05/05 00:48:33 ryoon Exp $
#

.include "../../x11/wxGTK26/Makefile.common"

PKGNAME=	${DISTNAME:S/wxGTK/wxGTK-contrib/}
PKGREVISION=	26
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Contrib libraries for wxWidgets GTK

USE_TOOLS+=		gmake

BUILD_DIRS=		contrib/src

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
