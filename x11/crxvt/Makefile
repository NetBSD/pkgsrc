# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 12:14:18 wiz Exp $
#

DISTNAME=	crxvt-2.10-2
PKGNAME=	crxvt-2.10.2
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/crxvt/old/ \
		ftp://ftp.ncu.edu.tw/OS/Linux/Chinese/xcin/crxvt/old/ \
		ftp://linux.cis.nctu.edu.tw/packages/chinese/X/xcin/crxvt/old/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://xcin.linux.org.tw/old/
COMMENT=	low memory usage xterm replacement that supports color & xcin

DEPENDS+=	intlfonts-1.2:../../fonts/intlfonts

USE_X11BASE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --os=NetBSD --no-menu

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/crxvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/crxvt.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
