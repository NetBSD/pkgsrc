# $NetBSD: Makefile,v 1.18 2005/05/16 01:15:34 jlam Exp $#

DISTNAME=	xservers-3.3.6.3
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Old X11 servers for use under XFree86 4.x

ONLY_FOR_PLATFORM=	NetBSD-*-i386

BUILD_TARGET=	World
PLIST_SRC=	${WRKDIR}/PLIST
USE_X11BASE=	YES

.if !defined(X11_RELEASE) && !defined(CHECK_X11)
X11_RELEASE!=	${MAKE} CHECK_X11=YES print-x11-release
MAKEFLAGS+=	X11_RELEASE=${X11_RELEASE}
.  if ${X11_RELEASE} == "6.3"
PKG_SKIP_REASON= "${PKGNAME} is part of your X11 distribution"
.  endif
.endif

PKGSRC_USE_TOOLS+=	gtar

X11_SUBDIR=	X11R6.3
X11_SRCS=	Imakefile Makefile config fonts include lib nls \
		programs/Imakefile programs/Xserver programs/bdftopcf \
		programs/mkfontdir programs/xkbcomp

MESSAGE_SUBST+=	X11_SUBDIR=${X11_SUBDIR}

.include "../../mk/bsd.prefs.mk"

do-fetch:
.if defined(BSDXSRCDIR)
.if !exists(${BSDXSRCDIR}/xc/config/cf/NetBSD.cf)
	@${ECHO_MSG} "Cannot find NetBSD 2.0 (or older) X11 sources in ${BSDXSRCDIR}."
	@${FALSE}
.endif
.else
	@${ECHO_MSG} "Please set BSDXSRCDIR in /etc/mk.conf, pointing it to a"
	@${ECHO_MSG} "directory that contains NetBSD 2.0 (or older) X11 sources."
	@${FALSE}
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	${GTAR} --exclude '*/CVS' -c -C ${BSDXSRCDIR}/xc -f - ${X11_SRCS} | \
	${GTAR} xCf ${WRKSRC} -

do-configure:
	${SED} -e 's#@PROJECTROOT@#${PREFIX}/${X11_SUBDIR}#' \
	  ${FILESDIR}/host.def >${WRKSRC}/config/cf/host.def

post-install:
	cd ${PREFIX} && \
	${FIND} ${X11_SUBDIR} \! -type d -print | ${SORT} >${PLIST_SRC} && \
	${FIND} ${X11_SUBDIR} -type d -print | ${SORT} -r | \
	${AWK} '{print("@dirrm "$$1)}' >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"

print-x11-release:
	@${GREP} '^#define SharedXextRev' ${X11BASE}/lib/X11/config/X11.tmpl \
	| ${AWK} '{print($$3)}'
