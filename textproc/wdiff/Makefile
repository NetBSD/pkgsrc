# $NetBSD: Makefile,v 1.18 2011/02/05 17:47:22 ryoon Exp $
#

DISTNAME=		wdiff-0.6.5
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=wdiff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/wdiff/wdiff.html
COMMENT=		Word-by-word diff

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

USE_TOOLS+=		makeinfo
INFO_FILES=		yes
CHECK_FILES_SKIP+=	lib/charset.alias

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
