# $NetBSD: Makefile,v 1.30 2020/01/18 23:35:34 rillig Exp $

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
