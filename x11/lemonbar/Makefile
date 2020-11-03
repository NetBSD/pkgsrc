# $NetBSD: Makefile,v 1.1 2020/11/03 11:44:58 nia Exp $

DISTNAME=	lemonbar-1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=LemonBoy/}
GITHUB_PROJECT=	bar
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	hopkinsza@gmail.com
HOMEPAGE=	https://github.com/LemonBoy/bar
COMMENT=	Featherweight lemon-scented bar
LICENSE=	mit

USE_TOOLS+=	gmake pod2man

AUTO_MKDIRS=	yes

# generate the man page as in the lemonbar Makefile's `doc' target
# because `all' does not call it
post-build:
	${TOOLS_PATH.pod2man} --section=1 --name=lemonbar \
		--center="lemonbar manual" \
		--release="${PKGVERSION_NOREV}" \
		${WRKSRC}/README.pod > ${WRKSRC}/lemonbar.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemonbar ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/lemonbar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
