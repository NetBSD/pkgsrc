# $NetBSD: Makefile,v 1.1 2022/12/06 21:04:13 vins Exp $

DISTNAME=	xlax2.4
PKGNAME=	xlax-2.4
CATEGORIES=	x11
MASTER_SITES=	http://hea-www.harvard.edu/~fine/Tech/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://hea-www.harvard.edu/~fine/Tech/xlax.html
COMMENT=	Multi-window input software
LICENSE=	mit

USE_IMAKE=	yes

MAKE_FLAGS+=	CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	LOCAL_LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	lib/X11/app-defaults

REPLACE_PERL+=	mkxlax

post-patch:
	${RUN} ${CP} ${FILESDIR}/stddef.h ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xlax ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mkxlax ${DESTDIR}${PREFIX}/bin

.for m in xlax mkxlax
	${INSTALL_MAN} ${WRKSRC}/${m}.man 				\
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${m}.1
.endfor

post-install:
	${INSTALL_DATA} ${FILESDIR}/xlax.ad 				\
	  ${DESTDIR}${PREFIX}/lib/X11/app-defaults/Xlax

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"         # strlcpy()
.include "../../devel/libbsd/buildlink3.mk"
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
