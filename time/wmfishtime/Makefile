# $NetBSD: Makefile,v 1.24 2026/08/04 20:29:18 wiz Exp $
#

DISTNAME=	wmfishtime-1.24
PKGREVISION=	2
CATEGORIES=	time x11
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ne.jp/asahi/linux/timecop/
COMMENT=	Dockable clock application with clock, date and fish

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
