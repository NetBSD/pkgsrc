# $NetBSD: Makefile,v 1.5 2000/05/04 21:39:58 tron Exp $
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-3.2.1
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	root@garbled.net

DEPENDS+=	xview-config-3.2.1:../xview-config
DEPENDS+=	xview-lib-3.2.1:../xview-lib
DEPENDS+=	xview-clients-3.2.1:../xview-clients

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
