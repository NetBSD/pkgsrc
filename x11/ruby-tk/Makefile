# $NetBSD: Makefile,v 1.25 2006/11/10 16:54:54 tv Exp $

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-tk-${RUBY_VERSION}
#PKGREVISION=
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCHFILES=	ruby-1.8.5-tk-${RUBY18_PATCH_DATE}.patch.bz2
PATCH_DIST_STRIP= -p2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby interface to the Tk widget set including Tcl/TK library

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/tk
WRKSRC=			${RUBY_WRKSRC}/ext/tk
CONFIGURE_ARGS+=	--with-X11-dir=${X11BASE:Q}

REPLACE_RUBY_DIRS=	${WRKSRC}/sample

pre-configure:
	${FIND} ${WRKSRC} \( -name '*.orig' -o -name '*.bak' \) -print | ${XARGS} ${RM} -f

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tk
	${CP} -r ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tk

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
