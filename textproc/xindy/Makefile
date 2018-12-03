# $NetBSD: Makefile,v 1.1 2018/12/03 19:28:02 markd Exp $

DISTNAME=	texlive-20180414-source
PKGNAME=	xindy-2.5.1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2018/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	xindy runtime required by the tex-xindy package
LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/utils/xindy

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/utils/xindy
INSTALL_DIRS=	xindy-src/src xindy-src/tex2xindy

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-clisp-runtime=default
CONFIGURE_ARGS+=	--disable-xindy-docs
CONFIGURE_ARGS+=	--disable-xindy-rules

INSTALLATION_DIRS+=	bin

post-install:
	cd ${WRKSRC}; ${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
                ${MAKE_PROGRAM} install-exec-hook
	rm -rf ${DESTDIR}${PREFIX}/man

BUILDLINK_DEPMETHOD.clisp=	build
.include "../../lang/clisp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
