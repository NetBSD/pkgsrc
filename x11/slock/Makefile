# $NetBSD: Makefile,v 1.8 2016/02/16 17:47:19 leot Exp $

DISTNAME=		slock-1.3
CATEGORIES=		x11
MASTER_SITES=		http://dl.suckless.org/tools/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://tools.suckless.org/slock
COMMENT=		Simple X11 screen locker
LICENSE=		mit

MAKE_JOBS_SAFE=	no

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,/usr/X11R6,${X11BASE},'
SUBST_SED.makefile+=	-e '/^CPPFLAGS/ s,-DHAVE_SHADOW_H,,'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

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
.include "../../mk/bsd.pkg.mk"
