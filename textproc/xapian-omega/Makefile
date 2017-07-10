# $NetBSD: Makefile,v 1.36 2017/07/10 17:43:25 schmonz Exp $

.include "../../textproc/xapian/Makefile.common"

DISTNAME=		xapian-omega-${VERSION}

HOMEPAGE=		http://xapian.org/docs/omega/overview.html
COMMENT=		Search engine application for websites using Xapian

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
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

.include "../../devel/pcre/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
