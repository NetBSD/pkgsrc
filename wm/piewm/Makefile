# $NetBSD: Makefile,v 1.11 2006/12/27 13:37:41 joerg Exp $

DISTNAME=	piewm-1.02
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.crynwr.com/piewm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.crynwr.com/piewm/
COMMENT=	Minimalist window manager based on tvtwm with pie menus

USE_IMAKE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
