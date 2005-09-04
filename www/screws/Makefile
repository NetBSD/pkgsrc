# $NetBSD: Makefile,v 1.11 2005/09/04 05:00:37 jlam Exp $
#

DISTNAME=	screws-0.56
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.nopcode.org/prj/screws/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.nopcode.org/?t=screws
COMMENT=	SCRipt Enhanced Web Server

USE_PKGINSTALL=	YES
USE_TOOLS+=	perl:run

BUILD_DEFS+=	SCREWS_USER SCREWS_GROUP

PKG_USERS=	${SCREWS_USER}:${SCREWS_GROUP}
PKG_GROUPS=	${SCREWS_GROUP}

MAKE_ENV+=	ETCPREFIX=${PKG_SYSCONFDIR}
MAKE_ENV+=	PERL="${PERL5}"

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/default.conf ${PKG_SYSCONFDIR}/screws.conf
FILESDIR=	${WRKSRC}/src/Utils/files

RCD_SCRIPTS=	screws

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing paths."
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/Utils/screwsctl
SUBST_SED.paths=	-e 's|/var/log|${VARBASE}/log|g'

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
