# $NetBSD: Makefile,v 1.5 1998/11/19 15:40:47 agc Exp $

DISTNAME=		AfterStep-1.4.5.0
PKGNAME=		afterstep-1.450
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/pub/ \
			ftp://ftp.digex.net/pub/os/wm/AfterStep/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.afterstep.org/

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		asclock-11:../../x11/asclock

WRKSRC=			${WRKDIR}/AfterStep
USE_X11=		yes
INSTALL_TARGET=		install install.man

post-patch:
	@${MV} ${WRKSRC}/configure.h ${WRKSRC}/foo
	${SED} -e 's@###x11###@${X11BASE}@g' < ${WRKSRC}/foo > ${WRKSRC}/configure.h
	@${MV} ${WRKSRC}/afterdoc/afterstepdoc ${WRKSRC}/foo
	${SED} -e 's@###x11###@${X11BASE}@g' < ${WRKSRC}/foo > ${WRKSRC}/afterdoc/afterstepdoc
	@${RM} -f ${WRKSRC}/foo
	${TOUCH} ${WRKSRC}/apps/asload/asload.man
	${TOUCH} ${WRKSRC}/apps/asprint/asprint.man
	${TOUCH} ${WRKSRC}/modules/ASSound/ASSound.man

do-configure:
	(cd ${WRKSRC}; ./configure ;xmkmf; make Makefiles)

post-install:
	${RM} ${PREFIX}/man/man1/asload.0
	${RM} ${PREFIX}/man/man1/asprint.0
	${RM} ${PREFIX}/man/man1/ASSound.0
	chmod 664 ${PREFIX}/share/afterstep/feels/feel.paul

.include "../../mk/bsd.pkg.mk"
