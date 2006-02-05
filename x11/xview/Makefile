# $NetBSD: Makefile,v 1.19 2006/02/05 23:11:49 joerg Exp $
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-3.2.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	OpenLook Toolkit meta-package

DEPENDS+=	xview-config>=3.2.1:../../x11/xview-config
DEPENDS+=	xview-lib>=3.2.1:../../x11/xview-lib
DEPENDS+=	xview-clients>=3.2.1:../../x11/xview-clients

NOT_FOR_PLATFORM=       *-*-alpha       # broken va_arg handling in xview-lib

USE_X11BASE=	yes

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
