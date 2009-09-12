# $NetBSD: Makefile,v 1.8 2009/09/12 20:49:44 plunky Exp $

DISTNAME=	BWidget-1.9.0
PKGNAME=	tk-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcllib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcllib.sourceforge.net/
COMMENT=	High-level Widget Set for Tcl/Tk

DEPENDS+=	tcl>=8.4:../../lang/tcl
DEPENDS+=	tk>=8.4:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	YES
NO_CONFIGURE=	YES

USE_TOOLS+=	gtar

PLIST_SUBST+=	BWDIR=${DISTNAME}

INSTALLATION_DIRS=	lib/tcl

do-install:
	cd ${DESTDIR}${PREFIX}/lib/tcl && ${GTAR} zxpf ${DISTDIR}/${DISTFILES:Q} --exclude=CVS
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/lib/tcl/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
