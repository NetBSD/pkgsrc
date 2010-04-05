# $NetBSD: Makefile,v 1.3 2010/04/05 00:06:24 asau Exp $

DISTNAME=		slock-0.7
CATEGORIES=		x11
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.suckless.org/wiki/tools/xlib
COMMENT=		Simple X11 screen locker

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
	cd ${WRKSRC} && ${CC} -c -DVERSION=\"0.7\" ${CFLAGS} slock.c && \
		${CC} -o slock slock.o -lc ${LIBS} ${X11_LDFLAGS} -lX11

SPECIAL_PERMS+=	bin/slock ${SETUID_ROOT_PERMS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slock ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/slock/

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
