# $NetBSD: Makefile,v 1.34 2017/05/08 12:02:06 schmonz Exp $

DISTNAME=		xapian-omega-${VERSION}
VERSION=		1.4.2
CATEGORIES=		textproc
MASTER_SITES=		http://oligarchy.co.uk/xapian/${VERSION}/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://xapian.org/docs/omega/overview.html
COMMENT=		Search engine application for websites using Xapian
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++11
USE_TOOLS+=		perl:run

TEST_TARGET=		check

REPLACE_PERL=		dbi2omega htdig2omega mbox2omega

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

.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
