# $NetBSD: Makefile,v 1.44 2000/06/02 20:21:18 fredb Exp $
#

DISTNAME=	xscreensaver-3.24
CATEGORIES=	x11
MASTER_SITES=	http://www.jwz.org/xscreensaver/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.jwz.org/xscreensaver/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-shadow
CONFIGURE_ARGS+=--without-motif
CONFIGURE_ARGS+=--enable-subdir=${PREFIX}/libexec/xscreensaver
CONFIGURE_ARGS+=--with-zippy=/usr/games/fortune
CONFIGURE_ENV+=	INSTALL=/usr/bin/install

USE_X11BASE=	yes
USE_PERL5=	yes
USE_XAW=	yes

post-patch:
	cd ${WRKSRC}/driver ; \
	f=xscreensaver.kss ; \
	[ -f $$f.BAK ] || ${MV} $$f $$f.BAK ; \
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		<xscreensaver.kss.BAK >xscreensaver.kss

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=	3d

.if (${OPSYS} == "NetBSD")
.if defined(KERBEROS)
CFLAGS+=	-I/usr/include/kerberosIV
.else
CONFIGURE_ARGS+=--without-kerberos
.endif
.endif

.if defined(USE_GNOME)
DEPENDS+=	control-center>=1.2.0:../../x11/controlcenter
.else
CONFIGURE_ARGS+=--without-gnome
.endif

.include "../../mk/bsd.pkg.mk"
