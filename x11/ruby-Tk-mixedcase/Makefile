# $NetBSD: Makefile,v 1.4 2000/04/24 10:01:11 sakamoto Exp $
# FreeBSD Id: ports/x11-toolkits/rubytk/Makefile,v 1.3 1999/08/31 02:59:34 peter Exp

DISTNAME=	ruby-1.4.4
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
HOMEPAGE=	http://www.netlab.co.jp/ruby/index.html

DEPENDS+=	ruby-1.4.4:../../lang/ruby
DEPENDS+=	tcl-8.0.5:../../lang/tcl80
DEPENDS+=	tk-8.0.5:../../x11/tk80

TCL_LIB=	tcl80
TK_LIB=		tk80
TCL_DIR=	tcl8.0
TK_DIR=		tk8.0

USE_X11=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}/ext
CONFIGURE_ARGS+=--with-tcllib="${TCL_LIB}" --with-tklib="${TK_LIB}" \
		--with-tcl-lib="${LOCALBASE}/lib" \
		--with-tk-lib="${LOCALBASE}/lib" \
		--with-tcl-include="${LOCALBASE}/include/${TCL_DIR}" \
		--with-tk-include="${LOCALBASE}/include/${TK_DIR}" \
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
	${MKDIR} ${PREFIX}/share/examples/ruby/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/sample/* ${PREFIX}/share/examples/ruby/${dir}
.endfor

.include "../../mk/bsd.pkg.mk"
