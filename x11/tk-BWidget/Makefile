# $NetBSD: Makefile,v 1.7 2009/07/07 18:21:47 joerg Exp $

DISTNAME=	BWidget-1.7.0
PKGNAME=	tk-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcllib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcllib.sourceforge.net/
COMMENT=	High-level Widget Set for Tcl/Tk

DEPENDS+=	tcl>=8.4:../../lang/tcl
DEPENDS+=	tk>=8.4:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_EXTRACT=	YES
NO_BUILD=	YES
NO_CONFIGURE=	YES

USE_TOOLS+=	gtar

INSTALLATION_DIRS=	lib/tcl

do-install:
	cd ${DESTDIR}${PREFIX}/lib/tcl && ${GTAR} zxpf ${DISTDIR}/${DISTFILES}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/lib/tcl/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
