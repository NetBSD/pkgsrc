# $NetBSD: Makefile,v 1.5 2004/10/03 00:18:23 tv Exp $
#

DISTNAME=	openbox-2.2.3
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Window manager based on Blackbox (2.x branch)

DEPENDS=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_BUILDLINK3=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

CPPFLAGS+=	-DHAVE_STRFTIME=1

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
