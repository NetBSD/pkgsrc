# $NetBSD: Makefile,v 1.16 2024/03/21 08:52:01 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	xindy-2.5.1
PKGREVISION=	11
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	xindy runtime required by the tex-xindy package
LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS+=	${DISTNAME}/utils/xindy

USE_TOOLS+=	gmake perl
WRKSRC=		${WRKDIR}/${DISTNAME}/utils/xindy
INSTALL_DIRS=	xindy-src/src xindy-src/tex2xindy

GNU_CONFIGURE_ICONV=	no

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

# clisp does not honour buildlink, and will happily link against any
# libraries found in PREFIX.  This means we need to duplicate any libraries
# that clisp uses here so that this package does not have runtime issues.
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_DEPMETHOD.clisp=	build
.include "../../lang/clisp/buildlink3.mk"

.include "../../devel/libffcall/buildlink3.mk"
.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
