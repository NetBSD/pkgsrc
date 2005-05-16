# $NetBSD: Makefile,v 1.2 2005/05/16 01:15:34 jlam Exp $

DISTNAME=	BWidget-1.7.0
PKGNAME=	tk-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcllib/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tcllib.sourceforge.net/
COMMENT=	High-level Widget Set for Tcl/Tk

DEPENDS+=	tcl-8.4*:../../lang/tcl
DEPENDS+=	tk-8.4*:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_EXTRACT=	YES
NO_BUILD=	YES
NO_CONFIGURE=	YES

PKGSRC_USE_TOOLS+=	gtar

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tcl
	cd ${PREFIX}/lib/tcl && ${GTAR} zxpf ${DISTDIR}/${DISTFILES}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/tcl/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
