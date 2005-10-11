# $NetBSD: Makefile,v 1.4 2005/10/11 19:16:33 reed Exp $
#

DISTNAME=		numlockx-1.1
CATEGORIES=		x11
MASTER_SITES=		http://ktown.kde.org/~seli/numlockx/

MAINTAINER=		lems@gmx.net
HOMEPAGE=		http://ktown.kde.org/~seli/numlockx/
COMMENT=		Allows you to start X with numlock turned on

GNU_CONFIGURE=		yes

.include "../../mk/x11.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/numlockx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/numlockx

.include "../../mk/bsd.pkg.mk"
