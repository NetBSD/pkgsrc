# $NetBSD: Makefile,v 1.8 2003/09/26 22:05:14 wiz Exp $
#

DISTNAME=	openbox-2.2.3
CATEGORIES=	wm x11
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Window manager based on Blackbox

DEPENDS=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

CPPFLAGS+=	-DHAVE_STRFTIME=1

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
