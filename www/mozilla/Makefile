# $NetBSD: Makefile,v 1.67 2001/05/23 12:12:33 abs Exp $

MOZ_VER=	0.9
DISTNAME=	mozilla-source-${MOZ_VER}
PKGNAME=	mozilla-${MOZ_VER}
WRKSRC=		${WRKDIR}/mozilla
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/releases/mozilla${MOZ_VER}/src/ \
		ftp://ftp.fu-berlin.de/pub/unix/network/www/mozilla/releases/mozilla${MOZ_VER}/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/
COMMENT=	The open-source version of the Netscape browser

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5
BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=	zip>=2.3:../../archivers/zip
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk
DEPENDS+=	gdk-pixbuf>=0.10.1:../../graphics/gdk-pixbuf
DEPENDS+=	ORBit>=0.5.3:../../net/ORBit
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.11:../../graphics/png

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-i386 NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.5_ALPHA-i386 NetBSD-1.5_BETA-* \
			NetBSD-1.[5-9]*-* Linux-*-*

USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-debug \
		--with-jpeg=${LOCALBASE} \
		--with-png=${LOCALBASE} \
		--enable-mathml \
		--enable-svg \
		--with-extensions=cookie,irc,wallet,xmlextras,xml-rpc \
		--without-pthreads \
		--enable-modules=all,psm2

.if  ${MACHINE_ARCH} == "m68k"
DBG=
.else
CONFIGURE_ARGS+= --enable-optimize
.endif

MOZ_LIBDIR=	${PREFIX}/lib/mozilla
MAKE_ENV+=	LIBRUNPATH=${MOZ_LIBDIR}
LDFLAGS+=	-Wl,-R${MOZ_LIBDIR}

PLIST_SRC=      ${PKGDIR}/PLIST-${OBJECT_FMT}

SCRIPTS_ENV+=	OBJECT_FMT=${OBJECT_FMT}
SCRIPTS_ENV+=	PLIST_SRC=${PLIST_SRC}
SCRIPTS_ENV+=	SED=${SED}
SCRIPTS_ENV+=	EGREP=${EGREP}
SCRIPTS_ENV+=	CHOWN=${CHOWN}
SCRIPTS_ENV+=	CHGRP=${CHGRP}
SCRIPTS_ENV+=	CHMOD=${CHMOD}
SCRIPTS_ENV+=	BINOWN=${BINOWN}
SCRIPTS_ENV+=	BINGRP=${BINGRP}
SCRIPTS_ENV+=	BINMODE=${BINMODE}
SCRIPTS_ENV+=	SETENV=${SETENV}
SHAREMODE?=	644

.include "../../mk/bsd.prefs.mk"

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf)
	(cd ${WRKSRC}/nsprpub && ${LOCALBASE}/bin/autoconf)

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} BUILD_MODULES=all
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} BUILD_MODULES=psm2

post-build:
	${ECHO} skin,install,select,classic/1.0 >> ${WRKSRC}/dist/bin/chrome/installed-chrome.txt
	${ECHO} locale,install,select,en-US >> ${WRKSRC}/dist/bin/chrome/installed-chrome.txt

do-install:
	${SETENV} ${SCRIPTS_ENV} ${SCRIPTDIR}/moz-install

.include "../../mk/bsd.pkg.mk"
