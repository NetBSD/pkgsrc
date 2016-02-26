# $NetBSD: Makefile,v 1.58 2016/02/26 11:27:17 jperkin Exp $

DISTNAME=		rxvt-2.7.10
PKGREVISION=		6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rxvt/} \
			ftp://mason.primenet.com.au/pub/rxvt/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gcw@rxvt.org
HOMEPAGE=		http://sourceforge.net/projects/rxvt
COMMENT=		Low memory usage xterm replacement that supports color

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-utmp \
			--enable-wtmp \
			--enable-lastlog \
			--enable-xpm-background \
			--enable-transparency \
			--enable-menubar \
			--enable-rxvt-scroll \
			--enable-next-scroll \
			--enable-xterm-scroll \
			--enable-xim \
			--enable-ttygid \
			--enable-xgetdefault \
			--enable-frills \
			--enable-linespace \
			--enable-24bit \
			--enable-keepscrolling \
			--enable-mousewheel \
			--enable-greek \
			--enable-slipwheeling \
			--enable-languages \
			--with-encoding=noenc

CONFIGURE_ARGS+=	--with-xpm-includes=${BUILDLINK_PREFIX.libXpm}/include/X11
CONFIGURE_ARGS+=	--with-xpm-library=${BUILDLINK_PREFIX.libXpm}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin"
# Make rxvt setuid root so that tty ownership setting and utmp logging
# function correctly.
#
SPECIAL_PERMS=	${PREFIX}/bin/rxvt ${SETUID_ROOT_PERMS}
.endif

CFLAGS.SunOS+=	-DSunOS

post-patch:
	${MV} ${WRKSRC}/src/feature.h  ${WRKSRC}/src/feature.h.orig
	${SED} < ${WRKSRC}/src/feature.h.orig > ${WRKSRC}/src/feature.h \
		-e "s:/usr/lib/X11/app-defaults:${PREFIX}/lib/X11/app-defaults:"

INSTALLATION_DIRS=	lib/X11/app-defaults

pre-install:
	if [ ! -f ${PREFIX}/lib/X11/app-defaults/Rxvt ]; then \
		${INSTALL_DATA} ${FILESDIR}/Rxvt ${DESTDIR}${PREFIX}/lib/X11/app-defaults; \
	fi

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
