# $NetBSD: Makefile,v 1.52 2023/11/14 14:03:05 wiz Exp $
#

DISTNAME=	antiright-3.4
PKGREVISION=	43
CATEGORIES=	x11
MASTER_SITES=	http://download.savannah.nongnu.org/releases/antiright/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	antiright@gmail.com
HOMEPAGE=	https://www.nongnu.org/antiright/
COMMENT=	The gtkshell GUI creator, gshterm, and ACE desktop implementation

MAKE_JOBS_SAFE=		no

HAS_CONFIGURE=	YES
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config lex yacc

CPPFLAGS+=	-I${BUILDLINK_PREFIX.boehm-gc}/include/gc

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Fixing manual directory references.
SUBST_FILES.mandir=	Makefile
SUBST_SED.mandir=	\
	-e 's|^\(mandir[	 :]*=\).*|\1${PREFIX}/${PKGMANDIR}|'

SUBST_CLASSES+=		hpath
SUBST_STAGE.hpath=	pre-configure
SUBST_MESSAGE.hpath=	Fixing hardcoded paths.
SUBST_FILES.hpath=	configure
SUBST_SED.hpath=	-e 's|^\(INSTALL[	 :]*=\).*|\1${INSTALL}|'
SUBST_SED.hpath+=	-e 's|/usr/pkg|${PREFIX}|'
SUBST_NOOP_OK.hpath=	yes

TOOLS_DEPENDS.pkg-config=	pkg-config>=0.20:../../devel/pkg-config
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0

INSTALL_MAKE_FLAGS+=		PREFIX=${DESTDIR}${PREFIX} \
				mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../x11/vte/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
