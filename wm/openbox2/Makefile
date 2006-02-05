# $NetBSD: Makefile,v 1.12 2006/02/05 23:11:14 joerg Exp $
#

DISTNAME=	openbox-2.2.3
PKGREVISION=	3
CATEGORIES=	wm x11
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Window manager based on Blackbox (2.x branch)

DEPENDS+=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

CPPFLAGS+=	-DHAVE_STRFTIME=1

.include "../../fonts/Xft2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
