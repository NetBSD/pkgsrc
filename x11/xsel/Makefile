# $NetBSD: Makefile,v 1.4 2023/11/28 20:28:52 jperkin Exp $
#

DISTNAME=	xsel-1.2.0
CATEGORIES=	x11
MASTER_SITES=	http://www.vergenet.net/~conrad/software/xsel/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vergenet.net/~conrad/software/xsel/
COMMENT=	Manipulate the X selection

GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM+=	rm:-Werror

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xsel.1x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xsel.1

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
