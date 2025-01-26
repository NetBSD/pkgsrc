# $NetBSD: Makefile,v 1.25 2025/01/26 00:51:06 ktnb Exp $

DISTNAME=	xteddy_2.2.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	x11 games
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xteddy/}

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	https://web.archive.org/web/20210211193059/http://staffwww.itn.liu.se/~stegu/xteddy/
COMMENT=	Cuddly teddy bear for your desktop
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	bash:run pkg-config

GNU_CONFIGURE=	YES

LDFLAGS.SunOS+=	-lXext

REPLACE_BASH+=	xtoys

SUBST_CLASSES+=		prefix
SUBST_SED.prefix+=	-e "s,/usr/local,${PREFIX},"
SUBST_SED.prefix+=	-e "s,/usr/share,${PREFIX}/share,"
SUBST_SED.prefix+=	-e "s,/usr/games,${PREFIX}/bin,"
SUBST_FILES.prefix+=	xteddy.c
SUBST_FILES.prefix+=	xtoys
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Adapt hardcoded prefix for pkgsrc.

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
