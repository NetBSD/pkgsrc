# New ports collection makefile for:    xview-lib
# Version required:     3.2p1-X11R6
# Date created:         22 November 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.1.1.1 1998/07/03 21:02:03 tron Exp $
#

DISTNAME=	xview-lib
PKGNAME=	xview-lib-3.2.1
CATEGORIES=	x11

DEPENDS=        ${PORTSDIR}/x11/xview-config

WRKSRC=      	${PORTSDIR}/x11/xview-config/work/xview3.2p1-X11R6
USE_IMAKE=	yes
NO_WRKDIR=      yes

do-fetch:
do-extract:	# don't use NO_EXTRACT, dependency won't work

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
