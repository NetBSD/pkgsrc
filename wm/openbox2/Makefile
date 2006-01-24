# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:40 wiz Exp $
#

DISTNAME=	openbox-2.2.3
PKGREVISION=	2
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
