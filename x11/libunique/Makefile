# $NetBSD: Makefile,v 1.31 2014/05/05 00:48:31 ryoon Exp $
#

DISTNAME=	libunique-1.1.6
PKGREVISION=	20
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libunique/1.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/LibUnique
COMMENT=	Library for writing single instance applications
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake

PKGCONFIG_OVERRIDE+=	unique.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=	gtkdoc-rebase

SUBST_CLASSES+=		g_const
SUBST_STAGE.g_const=	post-configure
SUBST_MESSAGE.g_const=	Replace deprecated G_CONST_RETURN with plain "const".
SUBST_FILES.g_const=	unique/uniqueapp.c
SUBST_FILES.g_const+=	unique/uniquebackend.c
SUBST_FILES.g_const+=	unique/uniquebackend.h
SUBST_FILES.g_const+=	unique/uniqueinternals.h
SUBST_FILES.g_const+=	unique/uniquemessage.c
SUBST_FILES.g_const+=	unique/uniquemessage.h
SUBST_SED.g_const=	-e 's/G_CONST_RETURN /const /g'

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-tautological-compare
.endif

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
