# $NetBSD: Makefile,v 1.1 2002/03/25 16:19:29 atatat Exp $
#

DISTNAME=		XaoS-3.0
CATEGORIES=		x11
MASTER_SITES=		http://prdownloads.sourceforge.net/xaos/

MAINTAINER=		atatat@netbsd.org
HOMEPAGE=		http://xaos.theory.org/
COMMENT=		Zoomable fractal rendering doodad

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-curses-driver=no

.include "../../graphics/png/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
