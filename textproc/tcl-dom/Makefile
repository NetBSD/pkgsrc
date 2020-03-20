# $NetBSD: Makefile,v 1.12 2020/03/20 11:58:29 nia Exp $
#

DISTNAME=	TclDOM-1.6
PKGNAME=	tcl-dom-1.6
CATEGORIES=	textproc www tcl
MASTER_SITES=	${MASTER_SITE_LOCAL}
# newer releases are on sourceforge

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tclxml.sourceforge.net/tcldom.html
COMMENT=	DOM implementation for use with TclXML or TclExpat

DEPENDS+=	tcl-xml-[0-9]*:../../textproc/tcl-xml

# old name for this package...
CONFLICTS+=	TclDom-[0-9]*

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/tcl/TclDOM share/doc/tcl/TclDOM

do-install:
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${DESTDIR}${PREFIX}/lib/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/dom.tcl ${DESTDIR}${PREFIX}/lib/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/dommap.tcl ${DESTDIR}${PREFIX}/lib/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/docs/reference.html ${DESTDIR}${PREFIX}/share/doc/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/changes ${DESTDIR}${PREFIX}/share/doc/tcl/TclDOM

.include "../../mk/bsd.pkg.mk"
