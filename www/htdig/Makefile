# $NetBSD: Makefile,v 1.47 2020/05/20 06:09:05 rillig Exp $

DISTNAME=	htdig-3.2.0b6
PKGREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htdig/}
#MASTER_SITES+=	http://www.htdig.org/files/
#MASTER_SITES+=	http://www.it.htdig.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://htdig.sourceforge.net/
COMMENT=	WWW indexing and searching system

USE_LANGUAGES=		c c++03
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cgi-bin-dir=${PREFIX}/libexec/cgi-bin
CONFIGURE_ARGS+=	--with-common-dir=${PREFIX}/share/htdig/common
CONFIGURE_ARGS+=	--with-config-dir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-database-dir=${DBDIR:Q}
CONFIGURE_ARGS+=	--with-image-dir=${PREFIX}/share/examples/htdig
CONFIGURE_ARGS+=	--with-search-dir=${PREFIX}/share/examples/htdig
CONFIGURE_ENV+=		PDF_PARSER="${LOCALBASE}/bin/acroread"
CXXFLAGS+=		-Wno-deprecated

# StringMatch.cc: In member function 'int StringMatch::Compare(const char*, int&, int&)':
# StringMatch.cc:314:37: error: array subscript has type 'char' [-Werror=char-subscripts]
#   new_state = table[trans[string[pos]]][state];
#                                      ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

PKG_SYSCONFSUBDIR=	htdig
INSTALLATION_DIRS+=	share/htdig/common

DBDIR?=		${VARBASE}/db/htdig
MESSAGE_SUBST+=	DBDIR=${DBDIR}
OWN_DIRS+=	${DBDIR}

CONF_FILES+=	${PREFIX}/share/examples/htdig/HtFileType-magic.mime \
		${PKG_SYSCONFDIR}/HtFileType-magic.mime
CONF_FILES+=	${PREFIX}/share/examples/htdig/cookies.txt \
		${PKG_SYSCONFDIR}/cookies.txt
CONF_FILES+=	${PREFIX}/share/examples/htdig/htdig.conf \
		${PKG_SYSCONFDIR}/htdig.conf
CONF_FILES+=	${PREFIX}/share/examples/htdig/mime.types \
		${PKG_SYSCONFDIR}/mime.types

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
