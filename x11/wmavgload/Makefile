# $NetBSD: Makefile,v 1.15 2007/02/22 19:27:27 wiz Exp $

DISTNAME=	wmavgload-0.7.0
PKGREVISION=	1
CATEGORIES=	x11 windowmaker
MASTER_SITES=	ftp://ftp.windowmaker.info/pub/contrib/srcs/utils/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Another WindowMaker load gauge

USE_IMAKE=	YES

NO_INSTALL_MANPAGES=	YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
