# $NetBSD: Makefile,v 1.25 2005/12/05 20:51:20 rillig Exp $

DISTNAME=	xservers-3.3.6.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Old X11 servers for use under XFree86 4.x

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_SRC_ON_FTP=	"already in MASTER_SITE_LOCAL"

BUILD_TARGET=	World
PLIST_SRC=	${WRKDIR}/PLIST
USE_X11BASE=	YES

.if !defined(X11_RELEASE) && !defined(CHECK_X11)
X11_RELEASE!=	${MAKE} CHECK_X11=YES print-x11-release
MAKEFLAGS+=	X11_RELEASE=${X11_RELEASE:Q}
.  if ${X11_RELEASE} == "6.3"
PKG_SKIP_REASON+=	"${PKGNAME} is part of your X11 distribution"
.  endif
.endif

X11_SUBDIR=	X11R6.3
X11_SRCS=	Imakefile Makefile config fonts include lib nls \
		programs/Imakefile programs/Xserver programs/bdftopcf \
		programs/mkfontdir programs/xkbcomp

MESSAGE_SUBST+=	X11_SUBDIR=${X11_SUBDIR}

BUILDLINK_PASSTHRU_RPATHDIRS+= 	${PREFIX}/X11R6.3/lib

do-configure:
	${SED} -e 's#@PROJECTROOT@#${PREFIX}/${X11_SUBDIR}#' \
	  ${FILESDIR}/host.def >${WRKSRC}/config/cf/host.def
	${ECHO} "#define NetBSDThreads NO" >>${WRKSRC}/config/cf/host.def

post-install:
	cd ${PREFIX} && \
	${FIND} ${X11_SUBDIR} \! -type d -print | ${SORT} >${PLIST_SRC} && \
	${FIND} ${X11_SUBDIR} -type d -print | ${SORT} -r | \
	${AWK} '{print("@dirrm "$$1)}' >>${PLIST_SRC}

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

print-x11-release:
.if exists(${X11BASE}/lib/X11/config/X11.tmpl)
	@${GREP} '^#define SharedXextRev' ${X11BASE}/lib/X11/config/X11.tmpl \
	| ${AWK} '{print($$3)}'
.else
	@${ECHO} unknown
.endif
