# $NetBSD: Makefile,v 1.13 2007/01/07 09:14:16 rillig Exp $
#

PKGREVISION=	6
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Desktop File Manager

post-install:
	${MV} ${PREFIX}/${PKGMANDIR}/man1/dfm.1x ${PREFIX}/${PKGMANDIR}/man1/dfm.1

.include "Makefile.common"
