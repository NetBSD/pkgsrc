# $NetBSD: Makefile,v 1.23 1999/01/30 23:18:57 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/10/01 09:20:31 tg Exp
#

DISTNAME=	tk8.0p2
PKGNAME=	tk-8.0p2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.scriptics.com/

DEPENDS+=	tcl-8.0p2:../../lang/tcl80

WRKSRC=		${WRKDIR}/tk8.0/unix
GNU_CONFIGURE=	yes

USE_X11=	yes

# let libtool look after shared libraries
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--disable-shared

# If the build system supports shared objects, enable them in tk.
# libtermcap was chosen as it doesn't change version numbers frequently.
.if exists(/usr/lib/libtermcap.so.0.0)
post-configure:
	@${ECHO} "Enabling shared object support in ${PKGNAME}"
	cd ${WRKSRC};							\
		${MV} tkConfig.sh tkConfig.sh.orig;			\
		${SED} -e 's/TK_SHARED_BUILD=.*/TK_SHARED_BUILD=1/'	\
			-e 's/TK_LIB_FILE=.*/TK_LIB_FILE=libtk80.so.1.0/' \
			tkConfig.sh.orig > tkConfig.sh
.endif

test:
	cd ${WRKSRC}; ${SETENV} LIBTOOL=${LIBTOOL} PREFIX=${PREFIX} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
