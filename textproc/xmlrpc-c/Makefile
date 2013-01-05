# $NetBSD: Makefile,v 1.31 2013/01/05 10:37:56 ryoon Exp $

DISTNAME=	xmlrpc-c-1.16.44
# the "super stable" branch
PKGNAME=	${DISTNAME:S/-c-/-c-ss-/}
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlrpc-c/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmlrpc-c.sourceforge.net/
COMMENT=	Library for writing an XML-RPC server or client in C or C++
LICENSE=	modified-bsd

CONFLICTS+=	xmlrpc-c-[0-9]*
SUPERSEDES+=	xmlrpc-c-[0-9]*

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

PTHREAD_LINKFLAGS=	${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_MESSAGE.pthread=	Fixing config scripts.
SUBST_FILES.pthread=	xmlrpc-c-config.* xmlrpc-c-config.test.*
SUBST_SED.pthread=	-e 's/-lpthread/${PTHREAD_LINKFLAGS:Q}/'
SUBST_SED.pthread+=	-e 's/-L\(.\)libdir/-L\1libdir ${COMPILER_RPATH_FLAG}\1libdir/'

LDFLAGS.OpenBSD+=	${PTHREAD_LINKFLAGS}

.include "../../www/curl/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
