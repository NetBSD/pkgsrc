# $NetBSD: Makefile,v 1.7 2002/07/19 12:33:21 wiz Exp $
#

DISTNAME=		type1inst-0.6.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=X11/xutils/}

MAINTAINER=		groo@netbsd.org
COMMENT=		Automatically generate fonts.scale/fonts.dir for Type1 fonts

USE_PERL5=		yes
USE_X11BASE=		yes
REPLACE_PERL=		t1embed type1inst

NO_BUILD=		yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/type1inst ${X11PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/t1embed ${X11PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/type1inst.man ${X11PREFIX}/man/man1/type1inst.1
	@${INSTALL_DATA_DIR} ${X11PREFIX}/share/doc/type1inst
	@${INSTALL_DATA} ${WRKSRC}/README ${X11PREFIX}/share/doc/type1inst

.include "../../mk/bsd.pkg.mk"
