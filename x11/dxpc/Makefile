# New ports collection makefile for:	dxpc
# Version required:			3.7.0
# Date created:				2 Januar 1998
# Whom:					frueauf@ira.uka.de
#
# $NetBSD: Makefile,v 1.3 1998/03/20 08:35:59 mycroft Exp $
#

DISTNAME=	dxpc-3.7.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	frueauf@netbsd.org

GNU_CONFIGURE=	yes
USE_X11=	yes

MAN1=		dxpc.1

post-install:
	@strip ${PREFIX}/bin/dxpc

.include <bsd.port.mk>
