# $NetBSD: Makefile,v 1.3 2004/02/26 09:02:43 xtraeme Exp $
#

DISTNAME=	openbox-2.2.3
CATEGORIES=	wm x11
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	xtraeme@NetBSD.org
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
