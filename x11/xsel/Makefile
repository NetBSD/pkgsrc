# $NetBSD: Makefile,v 1.1.1.1 2008/04/05 13:07:35 obache Exp $
#

DISTNAME=	xsel-1.2.0
CATEGORIES=	x11
MASTER_SITES=	http://www.vergenet.net/~conrad/software/xsel/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vergenet.net/~conrad/software/xsel/
COMMENT=	Manipulate the X selection

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

BUILDLINK_DEPMETHOD.libXt?=	build

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xsel.1x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xsel.1

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
