# $NetBSD: Makefile,v 1.17 2003/12/18 04:05:28 grant Exp $

DISTNAME=	htdig-3.1.6
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

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cgi-bin-dir=${PREFIX}/libexec/cgi-bin \
		--with-common-dir=${PREFIX}/share/htdig/common \
		--with-config-dir=${PKG_SYSCONFDIR} \
		--with-database-dir=${DBDIR} \
		--with-image-dir=${PREFIX}/share/examples/htdig \
		--with-search-dir=${PREFIX}/share/examples/htdig
CXXFLAGS+=	-Wno-deprecated
CPPFLAGS+=	${BUILDLINK_CPPFLAGS.db} ${CXXFLAGS}
LDFLAGS+=	${BUILDLINK_LDFLAGS.db}

INSTALL_EXTRA_TMPL=     ${PKGDIR}/INSTALL
PKG_SYSCONFSUBDIR=	htdig

DBDIR?=		/var/db/htdig
MESSAGE_SUBST+=	DBDIR=${DBDIR}
OWN_DIRS+=	${DBDIR}

CONF_FILES+=	${PREFIX}/share/examples/htdig/htdig.conf \
		${PKG_SYSCONFDIR}/htdig.conf

post-patch:
	${TOUCH} ${WRKSRC}/configure

.include "../../mk/bsd.prefs.mk"
.if defined(EXTRACT_USING_PAX)
EXTRACT_ELEMENTS= -c ${DISTNAME}/db*
.else
EXTRACT_ELEMENTS= --exclude ${DISTNAME}/db*
.endif

.include "../../databases/db/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
