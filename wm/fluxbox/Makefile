# $NetBSD: Makefile,v 1.9 2003/05/17 05:41:11 salo Exp $
#

DISTNAME=	fluxbox-0.1.14
PKGREVISION=	2
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxbox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@netbsd.org
HOMEPAGE=	http://fluxbox.sourceforge.net/
COMMENT=	Window Manager for X based on Blackbox

DEPENDS=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_CXX=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--enable-kde

.include "../../fonts/Xft2/buildlink2.mk"
.include "../../lang/gcc/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
