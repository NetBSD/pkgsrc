# $NetBSD: Makefile,v 1.2 2023/11/07 22:35:50 schmonz Exp $

PKGNAME=		tcl-${PKGNAME_MODULE}
COMMENT=		Tcl bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/tcl8/

.include "../../lang/tcl/Makefile.version"

CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ENV+=		TCL_LIB=${PREFIX:Q}/lib/tcl

REPLACE_INTERPRETER=	tcl
REPLACE.tcl.old=	/usr/bin/env tclsh
REPLACE.tcl.new=	${PREFIX}/bin/tclsh${TCL_BASEVER}
REPLACE_FILES.tcl=	tcl8/docs/examples/*.tcl

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/tcl8/examples/*.tcl

.include "../../lang/tcl/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
