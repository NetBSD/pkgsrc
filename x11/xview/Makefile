# $NetBSD: Makefile,v 1.27 2022/04/23 00:15:46 gutteridge Exp $
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-3.2.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	OpenLook Toolkit meta-package

META_PACKAGE=		# empty

DEPENDS+=	xview-config>=3.2.1:../../x11/xview-config
DEPENDS+=	xview-lib>=3.2.1nb11:../../x11/xview-lib
DEPENDS+=	xview-clients>=3.2.1:../../x11/xview-clients

BROKEN_ON_PLATFORM=	${LP64PLATFORMS}  # broken va_arg handling in xview-lib

.include "../../mk/bsd.pkg.mk"
