# $NetBSD: Makefile,v 1.25 2005/05/16 03:04:45 jlam Exp $

DISTNAME=	htdig-3.1.6
PKGREVISION=	3
CATEGORIES=	www databases
MASTER_SITES=	http://www.htdig.org/files/ \
		ftp://ftp.htdig.org/ \
		${MASTER_SITE_SOURCEFORGE:=files/} \
		${MASTER_SITE_SOURCEFORGE:=pub/sourceforge/htdig/} \
		http://htdig.europeanservers.net/files/ \
		http://www.it.htdig.org/files/ \
		ftp://www.it.htdig.org/pub/htdig/ \
		http://www.opdenbrouw.nl/htdig/maindocs/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://htdig.sourceforge.net/
COMMENT=	WWW indexing and searching system

USE_PKGINSTALL=	YES
USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cgi-bin-dir=${PREFIX}/libexec/cgi-bin \
		--with-common-dir=${PREFIX}/share/htdig/common \
		--with-config-dir=${PKG_SYSCONFDIR} \
		--with-database-dir=${DBDIR} \
		--with-image-dir=${PREFIX}/share/examples/htdig \
		--with-search-dir=${PREFIX}/share/examples/htdig
CONFIGURE_ENV+=	PDF_PARSER="${LOCALBASE}/bin/acroread"
CXXFLAGS+=	-Wno-deprecated
CPPFLAGS+=	${CXXFLAGS}

INSTALL_EXTRA_TMPL=     ${PKGDIR}/INSTALL
PKG_SYSCONFSUBDIR=	htdig

DBDIR?=		${VARBASE}/db/htdig
MESSAGE_SUBST+=	DBDIR=${DBDIR}
OWN_DIRS+=	${DBDIR}

CONF_FILES+=	${PREFIX}/share/examples/htdig/htdig.conf \
		${PKG_SYSCONFDIR}/htdig.conf

.include "../../mk/bsd.prefs.mk"

.if !empty(EXTRACT_USING:Mgtar)
EXTRACT_ELEMENTS= --exclude ${DISTNAME}/db*
.else
EXTRACT_ELEMENTS= -c ${DISTNAME}/db*
.endif

.include "../../databases/db/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

post-patch:
	${TOUCH} ${WRKSRC}/configure

.include "../../mk/bsd.pkg.mk"
