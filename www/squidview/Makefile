# $NetBSD: Makefile,v 1.9 2023/05/21 14:52:22 taca Exp $

DISTNAME=	squidview-0.86
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.rillion.net/squidview/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rillion.net/squidview/
COMMENT=	Program which monitors and displays squid logs
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

.include "../../www/squid5/Makefile.common"

LOGDIR?=	${SQUID_DATADIR}/logs

SUBST_CLASSES+=		files
SUBST_STAGE.files=	pre-configure
SUBST_FILES.files=	squidview.h squidview.1
SUBST_SED.files=	-e "s|/var/log/squid|${LOGDIR}|g"
SUBST_MESSAGE.files=	Fixing logfile location.

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
