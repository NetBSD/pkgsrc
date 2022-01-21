# $NetBSD: Makefile,v 1.11 2022/01/21 17:34:34 wiz Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	xindy-2.5.1
PKGREVISION=	7
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	xindy runtime required by the tex-xindy package
LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS+=	${DISTNAME}/utils/xindy

USE_TOOLS+=	gmake perl
WRKSRC=		${WRKDIR}/${DISTNAME}/utils/xindy
INSTALL_DIRS=	xindy-src/src xindy-src/tex2xindy

CONFIGURE_ARGS+=	--disable-xindy-docs
CONFIGURE_ARGS+=	--disable-xindy-rules
CONFIGURE_ARGS+=	--with-clisp-runtime=default

INSTALLATION_DIRS+=	bin

# due to using clisp
MKPIE_SUPPORTED=	no

post-install:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} install-exec-hook
	# man page conflicts with tex-xindy-doc
	${RM} -f -r ${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../devel/libffcall/buildlink3.mk"
.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
BUILDLINK_DEPMETHOD.clisp=	build
.include "../../lang/clisp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
