# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 20:58:34 wiz Exp $
#

DISTNAME=		numlockx-1.0
CATEGORIES=		x11
MASTER_SITES=		http://ktown.kde.org/~seli/numlockx/

MAINTAINER=		lems@gmx.net
HOMEPAGE=		http://ktown.kde.org/~seli/numlockx/
COMMENT=		Allows you to start X with numlock turned on

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/numlockx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/numlockx

.include "../../mk/bsd.pkg.mk"
