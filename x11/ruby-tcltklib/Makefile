# $NetBSD: Makefile,v 1.16 2005/03/24 21:13:03 wiz Exp $

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-tcltklib-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby interface to Tcl/Tk libraries

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION_SUPPORTED=	18
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
USE_X11=		yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/tcltklib
WRKSRC=			${RUBY_WRKSRC}/ext/tcltklib

CONFIGURE_ARGS=	--with-tcllib="${TCL_LIB}" --with-tklib="${TK_LIB}" \
		--with-tcl-lib="${BUILDLINK_PREFIX.tcl}/lib/${TCL_DIR}" \
		--with-tk-lib="${BUILDLINK_PREFIX.tk}/lib/${TK_DIR}" \
		--with-tcl-include="${BUILDLINK_PREFIX.tcl}/include/${TCL_DIR}" \
		--with-tk-include="${BUILDLINK_PREFIX.tk}/include/${TK_DIR}" \
		--with-X11-dir="${X11BASE}"
REPLACE_RUBY=	demo/lines1.rb demo/lines2.rb demo/safeTk.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tcltklib
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tcltklib
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tcltklib/demo
	${INSTALL_DATA} ${WRKSRC}/demo/* ${RUBY_EXAMPLESDIR}/tcltklib/demo
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tcltklib
	${INSTALL_DATA} ${WRKSRC}/MANUAL.euc ${RUBY_DOCDIR}/tcltklib/MANUAL.ja
	${INSTALL_DATA} ${WRKSRC}/README.euc ${RUBY_DOCDIR}/tcltklib/README.ja

.include "tcltkversion.mk"
.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
