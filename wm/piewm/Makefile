# $NetBSD: Makefile,v 1.15 2012/10/23 10:24:15 wiz Exp $

DISTNAME=	piewm-1.04
CATEGORIES=	wm
MASTER_SITES=	http://www.crynwr.com/piewm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.crynwr.com/piewm/
COMMENT=	Minimalist window manager based on tvtwm with pie menus

USE_IMAKE=	yes
USE_TOOLS+=	lex yacc

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
