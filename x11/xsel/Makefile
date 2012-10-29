# $NetBSD: Makefile,v 1.2 2012/10/29 05:07:20 asau Exp $
#

DISTNAME=	xsel-1.2.0
CATEGORIES=	x11
MASTER_SITES=	http://www.vergenet.net/~conrad/software/xsel/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vergenet.net/~conrad/software/xsel/
COMMENT=	Manipulate the X selection

GNU_CONFIGURE=	yes

BUILDLINK_DEPMETHOD.libXt?=	build

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xsel.1x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xsel.1

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
