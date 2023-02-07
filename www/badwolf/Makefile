# $NetBSD: Makefile,v 1.19 2023/02/07 11:10:53 nros Exp $

DISTNAME=	badwolf-1.2.2
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	https://hacktivis.me/releases/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://hacktivis.me/projects/badwolf
COMMENT=	Minimalist and privacy-oriented webkit browser
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}


TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
TOOL_DEPENDS+=	lcms2-[0-9]*:../../graphics/lcms2

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
