# $NetBSD: Makefile,v 1.33 2024/05/06 11:04:43 cheusov Exp $

DISTNAME=		wdiff-1.2.2
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=wdiff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/wdiff/
COMMENT=		Word-by-word diff
LICENSE=		gnu-gpl-v3 # or later

GNU_CONFIGURE=		yes

USE_TOOLS+=		makeinfo
INFO_FILES=		yes

.include "options.mk"

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
