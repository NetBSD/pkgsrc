# $NetBSD: Makefile,v 1.11 2001/05/05 19:51:20 jlam Exp $
# FreeBSD Id: ports/x11-toolkits/rubytk/Makefile,v 1.3 1999/08/31 02:59:34 peter Exp

DISTNAME=	ruby-1.4.6
PKGNAME=	${DISTNAME:S/-/-Tk-/}
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.TokyoNet.AD.JP/pub/misc/ruby/ \
		ftp://ftp.iij.ad.jp/pub/lang/ruby/ \
		ftp://ftp.netlab.co.jp/pub/lang/ruby/ \
		ftp://blade.nagaokaut.ac.jp/pub/lang/ruby/ \
		ftp://ftp.krnet.ne.jp/pub/ruby/ \
		ftp://ftp.mirror.nucba.ac.jp/mirror/ruby/ \
		http://mirror.nucba.ac.jp/mirror/ruby/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/
COMMENT=	Ruby interface to Tcl/Tk libraries

DEPENDS+=	ruby-1.4.*:../../lang/ruby
DEPENDS+=	tk>=8.3.2:../../x11/tk

TCL_LIB=	tcl83
TK_LIB=		tk83

USE_X11=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}/ext
CONFIGURE_ARGS+=--with-tcllib="${TCL_LIB}" --with-tklib="${TK_LIB}" \
		--with-tcl-lib="${LOCALBASE}/lib" \
		--with-tk-lib="${LOCALBASE}/lib" \
		--with-tcl-include="${LOCALBASE}/include" \
		--with-tk-include="${LOCALBASE}/include" \
		--with-X11-dir="${X11BASE}"

RUBY=		${LOCALBASE}/bin/ruby
PLIST_SUBST=	RUBY_VERSION=1.4

EXTS=		tcltklib tk

do-configure:
.for dir in ${EXTS}
	@${ECHO_MSG} "Configuring in ${dir}..."
	@(cd ${WRKSRC}/${dir}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS})
.endfor

do-build:
.for dir in ${EXTS}
	@${ECHO_MSG} "Building in ${dir}..."
	@cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}
.endfor

do-install:
.for dir in ${EXTS}
	@${ECHO_MSG} "Installing in ${dir}..."
	@cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ruby/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/sample/* ${PREFIX}/share/examples/ruby/${dir}
.endfor

.include "../../mk/bsd.pkg.mk"
