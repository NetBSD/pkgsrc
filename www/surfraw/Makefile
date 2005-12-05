# $NetBSD: Makefile,v 1.28 2005/12/05 20:51:14 rillig Exp $
#

DISTNAME=	surfraw-1.0.7
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/proff/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://surfraw.sourceforge.net/
COMMENT=	Shell Users' Revolutionary Front Rage Against the Web

CONFLICTS+=	surfaw-[0-9]*

USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

# Override sysconfdir so that the installation puts the example config file
# in ${EGDIR}.
#
MAKE_FLAGS+=	sysconfdir=${EGDIR:Q}
MAKE_ENV+=	AM_MAKEFLAGS=${MAKE_FLAGS:Q}

DOCDIR=		${PREFIX}/share/doc/surfraw
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=	${EGDIR}/surfraw.conf ${PKG_SYSCONFDIR}/surfraw.conf
CONF_FILES+=	${EGDIR}/surfraw_elvi.list ${PKG_SYSCONFDIR}/surfraw_elvi.list

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
