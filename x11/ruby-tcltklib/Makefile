# $NetBSD: Makefile,v 1.12 2004/03/29 07:55:25 taca Exp $
# FreeBSD: ports/lang/ruby-tcltklib/Makefile,v 1.21 2000/10/20 19:56:04 knu Exp

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}tcltklib-${RUBY_VERSION}
PKGREVISION=	4
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby interface to Tcl/Tk libraries

# Ruby can work with tcl 8.4 but can't coexist with thread library.
# Since tcl-8.4.6nb1 enabled linking with thread library, ruby couldn't
# use it any more.
DEPENDS+=	tcl>=8.3:../../lang/tcl83
DEPENDS+=	tk>=8.3:../../x11/tk83

WRKSRC=		${RUBY_WRKSRC}/ext/tcltklib
DIST_SUBDIR=	ruby
DISTINFO_FILE=	${RUBY_DISTINFO}

EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/ext/tcltklib
USE_RUBY_EXTCONF= yes

CONFIGURE_ARGS=	--with-tcllib="${TCL_LIB}" --with-tklib="${TK_LIB}" \
		--with-tcl-lib="${LOCALBASE}/lib/${TCL_DIR}" \
		--with-tk-lib="${LOCALBASE}/lib/${TK_DIR}" \
		--with-tcl-include="${LOCALBASE}/include/${TCL_DIR}" \
		--with-tk-include="${LOCALBASE}/include/${TK_DIR}" \
		--with-X11-dir="${X11BASE}"

# Set these vars as the version numbers (without decimal points) of Tcl/Tk
# you want to use with Ruby/Tk.
# e.g.: make TCL_VERSION=42 TK_VERSION=76 WITH_TCL_JP=yes build
TCL_VERSION?=	83
TK_VERSION?=	83
#.if defined(WITH_TCLTK_JP)
#TCL_CATEGORY=	japanese
#TK_CATEGORY=	japanese
#TCL_JP=		jp
#.else
#TCL_CATEGORY=	lang
#TK_CATEGORY=	x11
TCL_JP=		# empty
#.endif

TCL_LIB=	tcl${TCL_VERSION}${TCL_JP}
TK_LIB=		tk${TK_VERSION}${TCL_JP}
TCL_DIR=	`echo "${TCL_LIB}" | ${SED} 's/\([0-9]\)\([0-9]\)/\1.\2/'`
TK_DIR=		`echo "${TK_LIB}"  | ${SED} 's/\([0-9]\)\([0-9]\)/\1.\2/'`

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tcltklib
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tcltklib
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tcltklib/demo
	${INSTALL_DATA} ${WRKSRC}/demo/* ${RUBY_EXAMPLESDIR}/tcltklib/demo
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tcltklib
	${INSTALL_DATA} ${WRKSRC}/MANUAL.euc ${RUBY_DOCDIR}/tcltklib/MANUAL.ja
	${INSTALL_DATA} ${WRKSRC}/README.euc ${RUBY_DOCDIR}/tcltklib/README.ja

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
