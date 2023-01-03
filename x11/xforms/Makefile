# $NetBSD: Makefile,v 1.72 2023/01/03 17:36:40 wiz Exp $
#

DISTNAME=	xforms-1.0
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	http://download.savannah.nongnu.org/releases/xforms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/xforms
COMMENT=	Graphical user interface toolkit for X Window System

USE_IMAKE=	YES

MAKE_JOBS_SAFE=	no
MAKE_ENV+=	DEPEND_DEFINES=${CPPFLAGS:M*:Q}
MAKE_FLAGS+=	MANPATH=${PREFIX}/${PKGMANDIR}
SCRIPTS_ENV+=	DEPEND_DEFINES=${CPPFLAGS:Q}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
