# $NetBSD: Makefile,v 1.8 2004/03/24 11:56:00 wiz Exp $
#

DISTNAME=		XaoS-3.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xaos/}

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://xaos.theory.org/
COMMENT=		Zoomable fractal rendering doodad

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-curses-driver=no
INFO_FILES=		xaos.info

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
