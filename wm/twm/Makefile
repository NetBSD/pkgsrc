# $NetBSD: Makefile,v 1.14 2022/04/02 19:03:58 wiz Exp $

DISTNAME=	twm-1.0.12
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Tom's Window Manager

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config yacc

# Work around borked configure test
CONFIGURE_ENV+=		ac_cv_prog_YACC=yacc

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
