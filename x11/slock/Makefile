# $NetBSD: Makefile,v 1.3.18.1 2012/05/23 17:53:33 tron Exp $

DISTNAME=		slock-1.0
CATEGORIES=		x11
MASTER_SITES=		http://dl.suckless.org/tools/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://tools.suckless.org/slock
COMMENT=		Simple X11 screen locker
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin share/doc/slock

.include "../../mk/bsd.prefs.mk"

.if !(${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly")
CFLAGS+=-DHAVE_SHADOW_H
.endif

# TODO: handle -lcrypt too
LIBS+=	-lcrypt

do-build:
	cd ${WRKSRC} && ${CC} -c -DVERSION=\"1.0\" ${CFLAGS} slock.c && \
		${CC} -o slock slock.o -lc ${LIBS} ${X11_LDFLAGS} -lX11

SPECIAL_PERMS+=	bin/slock ${SETUID_ROOT_PERMS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slock ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/slock/

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
