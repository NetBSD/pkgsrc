# $NetBSD: Makefile,v 1.10 2003/05/29 23:14:10 grant Exp $
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
USE_GCC_SHLIB=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--enable-kde

.include "../../fonts/Xft2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
