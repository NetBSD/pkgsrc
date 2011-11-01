# $NetBSD: Makefile,v 1.65 2011/11/01 06:02:49 sbd Exp $

DISTNAME=	Eterm-0.9.5
PKGNAME=	${DISTNAME:S/^E/e/}
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eterm/}
DISTFILES=	${DEFAULT_DISTFILES} ${PIXMAP_FILES}
PIXMAP_FILES=	${DISTNAME:S/Eterm-/Eterm-bg-/}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eterm.org/
COMMENT=	Enlightened terminal emulator for the X Window System

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl:run
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-multi-charset=unicode
CONFIGURE_ARGS+=	--enable-auto-encoding

EXTRACT_DIR.${PIXMAP_FILES}=	${WRKSRC}

PKG_SYSCONFSUBDIR=	Eterm
OWN_DIRS=		${PKG_SYSCONFDIR}/themes

.include "../../mk/bsd.prefs.mk"

# Install Eterm as setuid root so that utmp logging function correctly.
#
# XXX: If installed setuid root on Solaris, pseudo-tty is owned by root,
#      and it's not possible to resume a screen session as a normal user.
#      (this behaviour should be reviewed again, since this workaround
#      is 2 years and several version updates old.)
#
.if ${OPSYS} != "SunOS"
SPECIAL_PERMS=		${PREFIX}/bin/Eterm ${SETUID_ROOT_PERMS}
.endif

.include "options.mk"

.include "../../devel/libast/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
