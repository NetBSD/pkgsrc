# $NetBSD: Makefile,v 1.1.1.1 2002/11/20 18:13:37 jschauma Exp $
#

DISTNAME=	blackbox-0.65.0
PKGNAME=	bsetroot-0.1
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	tools to set the root windows background

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

do-build:
	( cd ${WRKSRC}/nls && ${MAKE} && \
	 cd ${WRKSRC}/util && ${MAKE} )

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/util/bsetbg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/bsetroot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bsetbg.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bsetroot.1 ${PREFIX}/man/man1

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
