# $NetBSD: Makefile,v 1.27 2003/12/04 19:48:26 xtraeme Exp $
#

DISTNAME=		Eterm-0.9.2
PKGNAME=		${DISTNAME:S/^E/e/}
PKGREVISION=		5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=eterm/} \
                        ftp://ftp.dti.ad.jp/pub/X/Eterm/
DISTFILES=		${ETERM_SRCS} ${PIXMAP_FILES}

SITES_Eterm-bg-scale-1.tar.gz= ${MASTER_SITE_BACKUP}
SITES_Eterm-bg-scale-2.tar.gz= ${MASTER_SITE_BACKUP}
SITES_Eterm-bg-tile.tar.gz=    ${MASTER_SITE_BACKUP}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.eterm.org/
COMMENT=		Enlightened terminal emulator for the X Window System

EXTRACT_ONLY=		${ETERM_SRCS}
ETERM_SRCS=		${DISTNAME}${EXTRACT_SUFX}
PIXMAP_FILES=		Eterm-bg-scale-1.tar.gz Eterm-bg-scale-2.tar.gz \
			Eterm-bg-tile.tar.gz

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

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

.if ${MACHINE_ARCH} == "i386" && ${USE_MMX} != "NO"
CONFIGURE_ARGS+=	--enable-mmx
BUILD_DEFS+=		USE_MMX
.endif

post-extract:
	${LN} -sf ${WRKSRC} ${WRKDIR}/Eterm
	cd ${WRKDIR} && \
	for f in ${PIXMAP_FILES}; do \
		${PAX} -O -zrf ${DISTDIR}/$$f; \
	done

.include "../../devel/libast/buildlink2.mk"
.include "../../graphics/imlib2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
