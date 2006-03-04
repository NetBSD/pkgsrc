# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:54 jlam Exp $
#

DISTNAME=	openbox-2.2.3
PKGREVISION=	3
CATEGORIES=	wm x11
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Window manager based on Blackbox (2.x branch)

DEPENDS+=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

CPPFLAGS+=	-DHAVE_STRFTIME=1

.include "../../fonts/Xft2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
