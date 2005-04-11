# $NetBSD: Makefile,v 1.8 2005/04/11 21:48:02 tv Exp $
#

DISTNAME=	screws-0.56
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.nopcode.org/prj/screws/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.nopcode.org/?t=screws
COMMENT=	SCRipt Enhanced Web Server

USE_PERL5=	YES
USE_PKGINSTALL=	YES

BUILD_DEFS+=	SCREWS_USER SCREWS_GROUP

PKG_USERS=	${SCREWS_USER}:${SCREWS_GROUP}
PKG_GROUPS=	${SCREWS_GROUP}

MAKE_ENV+=	ETCPREFIX=${PKG_SYSCONFDIR}

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
