# $NetBSD: Makefile,v 1.25 2012/10/25 06:57:06 asau Exp $
#

DISTNAME=		wdiff-1.1.2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=wdiff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/wdiff/
COMMENT=		Word-by-word diff
LICENSE=		gnu-gpl-v3 # or later

GNU_CONFIGURE=		yes

USE_TOOLS+=		makeinfo
INFO_FILES=		yes
CHECK_FILES_SKIP+=	lib/charset.alias

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
