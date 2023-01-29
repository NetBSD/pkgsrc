# $NetBSD: Makefile,v 1.8 2023/01/29 21:18:33 ryoon Exp $

DISTNAME=	xnotify-0.8.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=phillbush/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/phillbush/xnotify
COMMENT=	Read notifications from stdin and display them on the screen
LICENSE=	mit

SUBST_CLASSES+=		configmk
SUBST_STAGE.configmk=	pre-configure
SUBST_MESSAGE.configmk=	Adjusting config.mk
SUBST_FILES.configmk=	config.mk
SUBST_SED.configmk+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.configmk+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.configmk+=	-e 's,/usr/X11R6,${X11BASE},'
SUBST_SED.configmk+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.configmk+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.configmk+=	-e 's/-I$${FREETYPEINC}/$${FREETYPEINC}/'
SUBST_SED.configmk+=	-e 's,^FREETYPEINC *=.*,FREETYPEINC != freetype-config --cflags,'
SUBST_SED.configmk+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CFLAGS.SunOS+=		-D_XOPEN_SOURCE=500

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xnotify ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xnotify.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
