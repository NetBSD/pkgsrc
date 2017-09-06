# $NetBSD: Makefile,v 1.15 2017/09/06 10:40:35 wiz Exp $
#

DISTNAME=	xhangglider-0.94.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.netfort.gr.jp/~take/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.netfort.gr.jp/~take/linux/xhang-en.html
COMMENT=	Hanggliders fly in the background of the X screen
LICENSE=	gnu-gpl-v2

USE_IMAKE=		yes
MAKE_ENV+=		PREFIX=${PREFIX}

post-extract:
	${RM} ${WRKSRC}/Makefile
	${TOUCH} ${WRKSRC}/xhangglider.man

INSTALL_TARGET=	install install.dat

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
