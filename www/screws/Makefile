# $NetBSD: Makefile,v 1.16 2006/08/14 22:36:47 wiz Exp $
#

DISTNAME=	screws-0.56
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.nopcode.org/prj/screws/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.nopcode.org/?t=screws
COMMENT=	SCRipt Enhanced Web Server

USE_TOOLS+=	perl:run

BUILD_DEFS+=	SCREWS_USER SCREWS_GROUP

PKG_USERS=	${SCREWS_USER}:${SCREWS_GROUP}
PKG_GROUPS=	${SCREWS_GROUP}

MAKE_ENV+=	ETCPREFIX=${PKG_SYSCONFDIR:Q}
MAKE_ENV+=	PERL=${PERL5:Q}

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/default.conf ${PKG_SYSCONFDIR}/screws.conf
FILESDIR=	${WRKSRC}/src/Utils/files

RCD_SCRIPTS=	screws

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/Utils/screwsctl
SUBST_SED.paths=	-e 's|/var/log|${VARBASE}/log|g'

# The HSML files do not really contain a script interpreter, only
# something very similar.
CHECK_INTERPRETER_SKIP+=	*.hsml

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
