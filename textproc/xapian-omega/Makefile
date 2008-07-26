# $NetBSD: Makefile,v 1.1.1.1 2008/07/26 23:37:29 schmonz Exp $
#

DISTNAME=		xapian-omega-1.0.7
CATEGORIES=		textproc
MASTER_SITES=		http://oligarchy.co.uk/xapian/1.0.7/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://xapian.org/docs/omega/overview.html
COMMENT=		Search engine application for websites using Xapian

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files=	omega.conf
SUBST_SED.files=	-e "s|@VARBASE@|${VARBASE}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

OWN_DIRS+=		${VARBASE}/log/${PKGBASE}
OWN_DIRS+=		${VARBASE}/${PKGBASE}/cdb
OWN_DIRS+=		${VARBASE}/${PKGBASE}/data
OWN_DIRS+=		${VARBASE}/${PKGBASE}/templates

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES+=		${EGDIR}/omega.conf ${PKG_SYSCONFDIR}/omega.conf

INSTALLATION_DIRS=	${EGDIR}

INSTALL_TARGET=		install install-dist_sysconfDATA
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

BUILD_DEFS+=		VARBASE

.include "../../textproc/xapian/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
