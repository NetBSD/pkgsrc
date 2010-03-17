# $NetBSD: Makefile,v 1.13 2010/03/17 09:53:08 sbd Exp $
#

DISTNAME=		xorg-cf-files-1.0.2
PKGREVISION=		10
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg imake rules

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

.if defined(IMAKE_TOOLS) && !empty(IMAKE_TOOLS:Mgmake)
USE_TOOLS+=		gmake
.endif

post-extract:
	${CP} ${FILESDIR}/host.def ${WRKSRC}
	${CP} ${FILESDIR}/xorgsite.def ${WRKSRC}

pre-configure:
.for sys in NetBSD FreeBSD DragonFly linux darwin
	mv ${WRKSRC}/${sys}.cf ${WRKSRC}/${sys}.cf.before && \
	${SED} -e "s|@@PKGSRC_CC@@|${CC}|g"		\
		-e "s|@@PKGSRC_CPP@@|${CPP}|g"		\
		-e "s|@@PKGSRC_CXX@@|${CXX}|g"		\
		-e "s|@@PKGSRC_CFLAGS@@|${CFLAGS}|g"	\
		-e "s|@@DARWIN_USE_QUARTZ@@|${DARWIN_USE_QUARTZ}|g"	\
		${WRKSRC}/${sys}.cf.before > ${WRKSRC}/${sys}.cf
.endfor
	${SED} -e "s|@PREFIX@|${PREFIX}|g"		\
		-e "s|@PKGMANDIR@|${PKGMANDIR}|"	\
		-e "s|@MAKE@|${MAKE_PROGRAM}|"	${FILESDIR}/host.def > \
		${WRKSRC}/host.def

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
