# $NetBSD: Makefile,v 1.25 2015/07/04 16:18:44 joerg Exp $
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-3.2.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	OpenLook Toolkit meta-package

META_PACKAGE=		# empty

DEPENDS+=	xview-config>=3.2.1:../../x11/xview-config
DEPENDS+=	xview-lib>=3.2.1:../../x11/xview-lib
DEPENDS+=	xview-clients>=3.2.1:../../x11/xview-clients

NOT_FOR_PLATFORM=	*-*-alpha       # broken va_arg handling in xview-lib

.include "../../mk/bsd.pkg.mk"
