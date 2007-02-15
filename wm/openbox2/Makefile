# $NetBSD: Makefile,v 1.16 2007/02/15 14:53:44 joerg Exp $
#

DISTNAME=	openbox-2.2.3
PKGREVISION=	3
CATEGORIES=	wm x11
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Window manager based on Blackbox (2.x branch)

DEPENDS+=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

CPPFLAGS+=	-DHAVE_STRFTIME=1

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
