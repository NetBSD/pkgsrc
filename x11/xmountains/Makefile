# $NetBSD: Makefile,v 1.3 2001/02/17 17:07:18 wiz Exp $
#

DISTNAME=	xmountains_2.5
PKGNAME=	xmountains-2.5
CATEGORIES=	x11
MASTER_SITES=	http://www.epcc.ed.ac.uk/~spb/xmountains/

PATCH_SITES=	http://www.epcc.ed.ac.uk/~spb/xmountains/current_source/
PATCHFILES=	vroot.h

MAINTAINER=	fredb@netsd.org
HOMEPAGE=	http://www.epcc.ed.ac.uk/~spb/xmountains/
COMMENT=	fractal terrain generator

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

DIST_SUBDIR=	xmountains
MAKE_ENV+=	CPPFLAGS="-DVROOT"

# XXX Hack. We really want an OTHER_SITES/OTHERFILES mechanism for this.
do-patch:
		${CP} ${DISTDIR}/${DIST_SUBDIR}/${PATCHFILES} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
