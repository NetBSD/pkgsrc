# $NetBSD: Makefile,v 1.1.2.2 2002/06/30 06:24:36 jlam Exp $
#

DISTNAME=		XaoS-3.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xaos/}

MAINTAINER=		atatat@netbsd.org
HOMEPAGE=		http://xaos.theory.org/
COMMENT=		Zoomable fractal rendering doodad

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-curses-driver=no

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
