# $NetBSD: Makefile,v 1.21 2022/08/19 09:58:30 tnn Exp $
#

DISTNAME=	oroborus_2.0.12-1
PKGNAME=	${DISTNAME:S/_/-/:C/-.$//}
PKGREVISION=	1
CATEGORIES=	wm x11
#MASTER_SITES=	https://www.oroborus.org/debian/dists/sid/main/source/x11/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20191129172107/https://www.oroborus.org/
COMMENT=	Small and simple window manager for X

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
