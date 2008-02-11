# $NetBSD: Makefile,v 1.1.1.1 2008/02/11 22:48:17 reed Exp $

DISTNAME=		slock-0.7
CATEGORIES=		x11
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.suckless.org/wiki/tools/xlib
COMMENT=		Simple X11 screen locker

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin share/doc/slock

.include "../../mk/bsd.prefs.mk"

.if !(${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin")
CFLAGS+=-DHAVE_SHADOW_H
.endif

# TODO: handle -lcrypt too
LIBS+=	-lcrypt

do-build:
	cd ${WRKSRC} && ${CC} -c -DVERSION=\"0.7\" ${CFLAGS} slock.c && \
		${CC} -o slock slock.o -lc ${LIBS} ${X11_LDFLAGS} -lX11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slock ${PREFIX}/bin/
	${CHMOD} 555 ${PREFIX}/bin/slock
	${CHMOD} u+s ${PREFIX}/bin/slock
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/slock/

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
