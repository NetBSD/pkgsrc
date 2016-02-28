# $NetBSD: Makefile,v 1.10 2016/02/28 19:49:06 joerg Exp $

DISTNAME=		slock-1.3
CATEGORIES=		x11
MASTER_SITES=		http://dl.suckless.org/tools/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://tools.suckless.org/slock
COMMENT=		Simple X11 screen locker
LICENSE=		mit

MAKE_JOBS_SAFE=	no

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Adjust config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,/usr/X11R6,${X11BASE},'
SUBST_SED.makefile+=	-e '/^CPPFLAGS/ s,-DHAVE_SHADOW_H,,'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^CPPFLAGS *= ,CPPFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

# Bump _XOPEN_SOURCE version to 600 in order to avoid "Compiler or options
# invalid for pre-UNIX 03 X/Open applications" error on SunOS.
SUBST_CLASSES+=		slock
SUBST_STAGE.slock=	pre-configure
SUBST_MESSAGE.slock=	Bump _XOPEN_SOURCE version
SUBST_FILES.slock=	slock.c
SUBST_SED.slock+=	-e '/_XOPEN_SOURCE/ s/500/600/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if !(${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly")
CFLAGS+=		-DHAVE_SHADOW_H
.endif

.if !(${OPSYS} == "OpenBSD" || ${OPSYS} == "Darwin")
LIBS+=	-lcrypt

.endif

SPECIAL_PERMS+=	bin/slock ${SETUID_ROOT_PERMS}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
