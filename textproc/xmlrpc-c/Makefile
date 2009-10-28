# $NetBSD: Makefile,v 1.10 2009/10/28 09:25:23 adam Exp $

DISTNAME=	xmlrpc-c-1.06.38
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlrpc-c/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmlrpc-c.sourceforge.net/
COMMENT=	Library for writing an XML-RPC server or client in C or C++

PKG_DESTDIR_SUPPORT=	user-destdir

# Sometimes can't open ../xmltok/libxmlrpc_xmltok.la
MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c99 c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
MAKE_FILE=		GNUmakefile
MAKE_ENV=		CFLAGS_COMMON=${CFLAGS:M*:Q}
MAKE_ENV+=		CXXFLAGS_COMMON=${CXXFLAGS:M*:Q}
MAKE_ENV+=		LADD=${LDFLAGS:M*:Q}
TEST_TARGET=		check

SUBST_CLASSES+=	pthread
SUBST_FILES.pthread=	xmlrpc-c-config.in xmlrpc-c-config.test.in
PTHREAD_LINKFLAGS=	${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}
SUBST_SED.pthread=	-e s/-lpthread/${PTHREAD_LINKFLAGS:Q}/
SUBST_SED.pthread+=	-e "s/-L\(.\)libdir/-L\1libdir ${COMPILER_RPATH_FLAG}\1libdir/"
SUBST_STAGE.pthread=	pre-configure
SUBST_MESSAGE.pthread=	Fixing config scripts.

.include "../../www/libwww/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
