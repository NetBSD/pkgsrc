# $NetBSD: Makefile,v 1.4 2007/01/07 09:14:14 rillig Exp $
#

DISTNAME=	bbpager-0.4.1beta1
PKGNAME=	bbpager04-0.4.1.1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net/available.phtml
COMMENT=	Pager for the blackbox window manager

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbpager.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/bbpager.bb.5 ${PREFIX}/${PKGMANDIR}/man5

.include "../../wm/blackbox70/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
