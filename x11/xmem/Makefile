# $NetBSD: Makefile,v 1.2 2024/08/01 18:50:45 vins Exp $

DISTNAME=	xmem_${PKGVER:S/./_/}
PKGVER=		1.29
PKGNAME=	xmem-${PKGVER}
CATEGORIES=	x11 sysutils
MASTER_SITES=	${HOMEPAGE}/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sdf.org/bch/xmem
COMMENT=	Memory and swap meter for X11
LICENSE=	mit

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	xmem.1
SUBST_VARS.paths=	PREFIX
SUBST_MESSAGE.paths=	Replacing PREFIX placeholders.

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
LDFLAGS+=	-lkvm
.endif

.for lib in X11 Xt Xaw Xmu
LDFLAGS+=	-l${lib}
.endfor

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	PREFIX=${PREFIX:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/${PKGBASE}
INSTALLATION_DIRS+=	lib/X11/app-defaults

WRKSRC=	${WRKDIR}/xmem

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmem			\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmem.1 			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/XMem.ad 			\
		${DESTDIR}${PREFIX}/lib/X11/app-defaults/XMem
.for f in xmem.bit copyright
	${INSTALL_DATA} ${WRKSRC}/${f}				\
		${DESTDIR}${PREFIX}/share/${PKGBASE}
.endfor

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
