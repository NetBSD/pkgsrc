# $NetBSD: Makefile,v 1.1.1.1 2004/01/24 08:43:27 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	imake-${XF_VER}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-1.tgz X430src-3.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Imake and other utilities from XFree86

USE_BUILDLINK2=	YES

INSTALL_TARGET=	install install.man

NO_XFREE86_TARGETS=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	flex-[0-9]*:../../devel/flex
USE_GNU_TOOLS+=	make
.endif

.include "../../wip/XFree86/Makefile.common"

post-extract:
.for F in ${SYSTEMS}
	@${MV} ${WRKSRC}/config/cf/${F}.cf \
		${WRKSRC}/config/cf/${F}.cf.in
.endfor
.undef F

pre-configure:
.for F in ${SYSTEMS}
	@${SED} -e "s|@@PKGSRC_CC@@|${CC}|g" \
		-e "s|@@PKGSRC_CPP@@|${CPP}|g" \
		-e "s|@@PKGSRC_CXX@@|${CXX}|g" \
		-e "s|@@PKGSRC_CFLAGS@@|${CFLAGS}|g" \
		${WRKSRC}/config/cf/${F}.cf.in > \
		${WRKSRC}/config/cf/${F}.cf
.endfor
.undef F

do-build:
	@${TOUCH} ${WRKSRC}/config/cf/version.def
	@${TOUCH} ${WRKSRC}/config/cf/date.def
	@${CP} ${FILESDIR}/xf86site.def ${WRKSRC}/config/cf
	@${SED} \
		-e "s|@PREFIX@|${PREFIX}|g" \
		-e "s|@BLNK@|${BUILDLINK_DIR}|g" \
		-e "s|@LOCALBASE@|${LOCALBASE}|g " \
		-e "s|@LDFLAGS@|${LDFLAGS}|g" \
		-e "s|@MAKE@|${MAKE_PROGRAM}|" \
		${FILESDIR}/host.def > \
		${WRKSRC}/config/cf/host.def
	( cd ${WRKSRC} && ${MAKE} Makefile.boot && \
	${MAKE_PROGRAM} -f xmakefile VerifyOS version.def \
		Makefiles includes )

.include "../../mk/bsd.pkg.mk"
