# $NetBSD: Makefile,v 1.15 2023/01/29 21:18:01 ryoon Exp $

DISTNAME=	vtwm-5.5.0
PKGREVISION=	2
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vtwm/}

MAINTAINER=	mehul.sanghvi@gmail.com
HOMEPAGE=	http://www.vtwm.org/
COMMENT=	TWM with virtual desktop, m4, sound and 3-D buttons
LICENSE=	x11

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config flex bison m4

CONFIGURE_ARGS+=	--disable-esd-sound
CONFIGURE_ARGS+=	--disable-rplay-sound

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Fixing default OSS device references.
SUBST_FILES.oss+=	configure
SUBST_FILES.oss+=	sound.c
SUBST_SED.oss=		-e 's,/dev/dsp,${DEVOSSAUDIO},'

CONFIGURE_ARGS+=	--enable-oss-sound
LIBS+=			${LIBOSSAUDIO}
.else
CONFIGURE_ARGS+=	--disable-oss-sound
.endif

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
