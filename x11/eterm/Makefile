# $NetBSD: Makefile,v 1.58 2009/09/20 12:51:42 obache Exp $

DISTNAME=	Eterm-0.9.4
PKGNAME=	${DISTNAME:S/^E/e/}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eterm/}
DISTFILES=	${DEFAULT_DISTFILES} ${PIXMAP_FILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eterm.org/
COMMENT=	Enlightened terminal emulator for the X Window System

PKG_DESTDIR_SUPPORT=	user-destdir

SITES.Eterm-bg-scale-1.tar.gz=	${MASTER_SITE_BACKUP}
SITES.Eterm-bg-scale-2.tar.gz=	${MASTER_SITE_BACKUP}
SITES.Eterm-bg-tile.tar.gz=	${MASTER_SITE_BACKUP}

PIXMAP_FILES=		Eterm-bg-scale-1.tar.gz Eterm-bg-scale-2.tar.gz \
			Eterm-bg-tile.tar.gz

USE_TOOLS+=		perl:run
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

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

pre-extract:
	${LN} -sf ${WRKSRC} ${WRKDIR}/Eterm

.include "../../devel/libast/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
