# $NetBSD: Makefile,v 1.1 1998/06/28 17:16:31 tron Exp $

DISTNAME=	XF86Setup-3.3.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
ONLY_FOR_ARCHS=	i386

MAINTAINER=	tron@netbsd.org

BUILD_DEPENDS+= ${TCLLIB}:../../lang/tcl80 \
		${TKLIB}:../../x11/tk80

TCLLIB=		${LOCALBASE}/lib/libtcl80.a
TKLIB=		${LOCALBASE}/lib/libtk80.a

WRKSRC=		${WRKDIR}/XF86Setup
USE_IMAKE=	yes

.include "../../mk/bsd.pkg.mk"
