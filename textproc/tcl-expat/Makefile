# $NetBSD: Makefile,v 1.12 2009/08/20 15:25:00 jwise Exp $
#

DISTNAME=	TclExpat-1.1
PKGNAME=	tcl-expat-1.1
PKGREVISION=	4
CATEGORIES=	textproc www tcl
MASTER_SITES=	http://www.zveno.com/in-tclxml/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/
COMMENT=	XML parser implemented entirely in Tcl

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes

MAKE_ENV+=	SHLIBTOOL=${SHLIBTOOL:Q}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tcl

INSTALLATION_DIRS=	share/doc/tcl/TclExpat

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/tcl/TclExpat

.include "../../lang/tcl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
