# $NetBSD: Makefile,v 1.34 2000/08/16 21:23:48 tron Exp $: Makefile,v 1.30 2000/06/17 22:14:00 tsarna Exp $

DISTNAME=	mozilla-source-M17
PKGNAME=	mozilla-5.0m17
WRKSRC=		${WRKDIR}/mozilla
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/releases/m17/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:../../lang/perl5
BUILD_DEPENDS+=	autoconf:../../devel/autoconf
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk
DEPENDS+=	ORBit>=0.5.1:../../net/ORBit
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-debug \
		--enable-optimize \
		--with-jpeg=${LOCALBASE} \
		--with-png=${LOCALBASE}
MOZ_LIBDIR=	${PREFIX}/lib/mozilla
MAKE_ENV+=	LIBRUNPATH=${MOZ_LIBDIR}
LDFLAGS+=	-Wl,-R${MOZ_LIBDIR}

PLIST_SRC=	${PKGDIR}/PLIST-${OBJECT_FMT}

pre-configure:
	(cd ${WRKSRC} && autoconf)

#do-build:
#	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} -f client.mk build)

do-install:
	sed -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/mozilla-${OBJECT_FMT}.in > ${PREFIX}/bin/mozilla
	chmod 755 ${PREFIX}/bin/mozilla
	${INSTALL_PROGRAM_DIR} ${MOZ_LIBDIR}
	( cd ${WRKSRC}/dist/bin; \
	tar chf - . | (cd ${MOZ_LIBDIR}; tar xpf -) ; \
	cd ${MOZ_LIBDIR}; \
	${SETENV} MOZILLA_FIVE_HOME=${MOZ_LIBDIR} ./regxpcom )
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/mozilla

.include "../../mk/bsd.pkg.mk"
