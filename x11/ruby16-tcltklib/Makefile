# $NetBSD: Makefile,v 1.2 2005/01/28 14:08:02 taca Exp $
# FreeBSD: ports/lang/ruby-tcltklib/Makefile,v 1.21 2000/10/20 19:56:04 knu Exp

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-tcltklib-${RUBY_VERSION}
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby interface to Tcl/Tk libraries

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION=		${RUBY16_VERSION}
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
USE_X11=		yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/tcltklib
WRKSRC=			${RUBY_WRKSRC}/ext/tcltklib

CONFIGURE_ARGS=	--with-tcllib="${TCL_LIB}" --with-tklib="${TK_LIB}" \
		--with-tcl-lib="${LOCALBASE}/lib/${TCL_DIR}" \
		--with-tk-lib="${LOCALBASE}/lib/${TK_DIR}" \
		--with-tcl-include="${LOCALBASE}/include/${TCL_DIR}" \
		--with-tk-include="${LOCALBASE}/include/${TK_DIR}" \
		--with-X11-dir="${X11BASE}"
REPLACE_RUBY=	demo/lines1.rb demo/lines2.rb \
		sample/sample0.rb sample/sample1.rb sample/sample2.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tcltklib
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tcltklib
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tcltklib/demo
	${INSTALL_DATA} ${WRKSRC}/demo/* ${RUBY_EXAMPLESDIR}/tcltklib/demo
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tcltklib
	${INSTALL_DATA} ${WRKSRC}/MANUAL.euc ${RUBY_DOCDIR}/tcltklib/MANUAL.ja
	${INSTALL_DATA} ${WRKSRC}/README.euc ${RUBY_DOCDIR}/tcltklib/README.ja

.include "../ruby-tcltklib/tcltkversion.mk"
.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
