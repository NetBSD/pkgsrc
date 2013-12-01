# $NetBSD: Makefile,v 1.35 2013/12/01 23:25:31 bsiegert Exp $

DISTNAME=	xmlrpc-c-1.25.26
# the "super stable" branch
PKGNAME=	${DISTNAME:S/-c-/-c-ss-/}
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
#MAKE_JOBS_SAFE=		no

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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "MirBSD"
SUBST_CLASSES+=		xopen
SUBST_STAGE.xopen=	pre-configure
SUBST_MESSAGE.xopen=	Removing _XOPEN_SOURCE lines.
SUBST_FILES.xopen+=	lib/abyss/src/data.c lib/abyss/src/response.c lib/abyss/src/conf.c
SUBST_FILES.xopen+=	lib/abyss/src/http.c lib/abyss/src/server.c lib/abyss/src/handler.c
SUBST_FILES.xopen+=	lib/curl_transport/curltransaction.c lib/curl_transport/curlmulti.c
SUBST_FILES.xopen+=	lib/curl_transport/xmlrpc_curl_transport.c lib/libutil/select.c
SUBST_FILES.xopen+=	lib/libutil/error.c lib/libutil/make_printable.c lib/libutil/asprintf.c
SUBST_FILES.xopen+=	lib/util/cmdline_parser.c lib/expat/xmlwf/xmlfile.c src/xmlrpc_datetime.c
SUBST_FILES.xopen+=	src/method.c src/xmlrpc_parse.c src/test/value_datetime.c src/xmlrpc_client.c
SUBST_FILES.xopen+=	src/xmlrpc_server_info.c src/xmlrpc_server_abyss.c tools/lib/dumpvalue.c
SUBST_FILES.xopen+=	tools/xmlrpc/xmlrpc.c tools/xmlrpc_transport/xmlrpc_transport.c
SUBST_SED.xopen=	-e '/^\#define _XOPEN_SOURCE/d'
.endif

LDFLAGS.OpenBSD+=	${PTHREAD_LINKFLAGS}
LDFLAGS.MirBSD+=	${PTHREAD_LINKFLAGS}

.include "../../www/curl/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
