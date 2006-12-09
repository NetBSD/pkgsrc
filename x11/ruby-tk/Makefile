# $NetBSD: Makefile,v 1.24.2.1 2006/12/09 10:17:48 salo Exp $

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-tk-${RUBY_VERSION_SUFFIX}
#PKGREVISION=
CATEGORIES=		x11 ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		ruby-1.8.5-tk-${RUBY18_PATCH_DATE}.patch.bz2
PATCH_DIST_STRIP=	-p3

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby interface to the Tk widget set

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/tk
WRKSRC=			${RUBY_WRKSRC}/ext/tk
CONFIGURE_ARGS+=	--with-X11-dir=${X11BASE:Q}

REPLACE_RUBY_DIRS=	${WRKSRC}/sample

post-extract:
	${CHMOD} ${SHAREMODE} ${WRKSRC}/sample/tkextlib/tktable/tcllogo.gif

pre-install:
	cd ${WRKSRC}; \
	${FIND} . \( -name '*.bak' -o -name '*.orig' -o \
			-name '*.orig_dist' \) -exec ${RM} -f {} \;

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tk
	${CP} -r ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tk

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
