# $NetBSD: Makefile,v 1.3 2006/09/03 10:16:56 wiz Exp $
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
	${INSTALL_MAN} ${WRKSRC}/bbpager.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bbpager.bb.5 ${PREFIX}/man/man5

.include "../../wm/blackbox70/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
