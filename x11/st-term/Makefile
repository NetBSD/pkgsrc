# $NetBSD: Makefile,v 1.1 2016/02/02 16:31:43 leot Exp $

DISTNAME=	st-0.6
PKGNAME=	${DISTNAME:S/-/-term-/}
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/st/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://st.suckless.org/
COMMENT=	Simple terminal implementation for X
LICENSE=	mit

MAKE_JOBS_SAFE=	no

SUBST_CLASSES+=			configdefh configmk makefile
SUBST_STAGE.configdefh=		pre-configure
SUBST_STAGE.configmk=		pre-configure
SUBST_STAGE.makefile=		pre-configure
SUBST_MESSAGE.configdefh=	Change default termname to xterm
SUBST_FILES.configdefh=		config.def.h
SUBST_MESSAGE.configmk=		Fixing config.mk
SUBST_FILES.configmk=		config.mk
SUBST_MESSAGE.makefile=		Do not install the st terminfo entry
SUBST_FILES.makefile=		Makefile
SUBST_SED.configdefh+=		-e 's,st-256color,xterm,g'
SUBST_SED.configmk+=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.configmk+=		-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.configmk+=		-e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.configmk+=		-e 's/cc/${CC:Q}/'
SUBST_SED.makefile+=		-e '/tic/d' # Do not install the st terminfo entry

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
