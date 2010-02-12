# $NetBSD: Makefile,v 1.2 2010/02/12 22:28:56 tonio Exp $
#

DISTNAME=	musca-0.9.24
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://aerosuidae.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aerosuidae.net/musca/Musca_Window_Manager
COMMENT=	Simple dynamic window manager for X

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing Makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e 's,@X11BASE@,${X11BASE},g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apis ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/musca ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xlisten ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/musca.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
