# $NetBSD: Makefile,v 1.5 2003/08/07 12:11:10 seb Exp $
#

DISTNAME=		XaoS-3.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xaos/}

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://xaos.theory.org/
COMMENT=		Zoomable fractal rendering doodad

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-curses-driver=no
USE_NEW_TEXINFO=	YES
INFO_FILES=		xaos.info

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
