# $NetBSD: Makefile,v 1.37 2009/12/17 19:35:03 abs Exp $

DISTNAME=	htdig-3.1.6
PKGREVISION=	5
CATEGORIES=	www databases
MASTER_SITES=	http://www.htdig.org/files/ \
		http://www.it.htdig.org/files/ \
		ftp://www.it.htdig.org/pub/htdig/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://htdig.sourceforge.net/
COMMENT=	WWW indexing and searching system

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-cgi-bin-dir=${PREFIX}/libexec/cgi-bin \
		--with-common-dir=${PREFIX}/share/htdig/common \
		--with-config-dir=${PKG_SYSCONFDIR:Q} \
		--with-database-dir=${DBDIR:Q} \
		--with-image-dir=${PREFIX}/share/examples/htdig \
		--with-search-dir=${PREFIX}/share/examples/htdig
MAKE_ENV+=	INSTALL_ROOT=${DESTDIR:Q}
CONFIGURE_ENV+=	PDF_PARSER="${PREFIX}/bin/acroread"
CXXFLAGS+=	-Wno-deprecated
CPPFLAGS+=	${CXXFLAGS}

PKG_SYSCONFSUBDIR=	htdig

BUILD_DEFS+=	VARBASE

DBDIR?=		${VARBASE}/db/htdig
MESSAGE_SUBST+=	DBDIR=${DBDIR}
OWN_DIRS+=	${DBDIR}

CONF_FILES+=	${PREFIX}/share/examples/htdig/htdig.conf \
		${PKG_SYSCONFDIR}/htdig.conf

EXTRACT_OPTS+=		-x
EXTRACT_ELEMENTS=	${DISTNAME}/db*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/db/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

post-patch:
	${TOUCH} ${WRKSRC}/configure

.include "../../mk/bsd.pkg.mk"
