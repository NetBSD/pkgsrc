# $NetBSD: Makefile,v 1.6 2004/01/20 12:28:27 agc Exp $
# FreeBSD: ports/x11-toolkits/ruby-tk/Makefile,v 1.21 2000/10/20 19:56:04 knu Exp

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}tk-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby interface to the Tk widget set

DEPENDS+=	${RUBY_PKGNAMEPREFIX}tcltklib>=${RUBY_VERSION}:../../x11/ruby-tcltklib

WRKSRC=		${RUBY_WRKSRC}/ext/tk
DIST_SUBDIR=	ruby

EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/ext/tk
USE_RUBY_EXTCONF= yes

CONFIGURE_ARGS=	--with-tcllib="${TCL_LIB}" --with-tklib="${TK_LIB}" \
		--with-tcl-lib="${LOCALBASE}/lib/${TCL_DIR}" \
		--with-tk-lib="${LOCALBASE}/lib/${TK_DIR}" \
		--with-tcl-include="${LOCALBASE}/include/${TCL_DIR}" \
		--with-tk-include="${LOCALBASE}/include/${TK_DIR}" \
		--with-X11-dir="${X11BASE}"

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -exec rm -f {} \;

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tk
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tk

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
