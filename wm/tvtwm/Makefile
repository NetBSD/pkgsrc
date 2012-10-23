# $NetBSD: Makefile,v 1.20 2012/10/23 10:24:15 wiz Exp $

DISTNAME=	tvtwm.pl11
PKGNAME=	tvtwm-11
PKGREVISION=	3
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=window_managers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Classic twm with virtual desktop support

WRKSRC=		${WRKDIR}/tvtwm
USE_IMAKE=	YES
USE_TOOLS+=	lex yacc

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
