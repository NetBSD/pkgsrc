# $NetBSD: Makefile,v 1.64 2010/01/18 09:59:45 wiz Exp $
#

DISTNAME=	xforms-1.0
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://download.savannah.nongnu.org/releases/xforms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/xforms
COMMENT=	Graphical user interface toolkit for X Window System

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	YES

MAKE_ENV=	DEPEND_DEFINES=${CPPFLAGS:M*:Q}
MAKE_FLAGS+=	MANPATH=${PREFIX}/${PKGMANDIR}
SCRIPTS_ENV=	DEPEND_DEFINES="${CPPFLAGS}"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
