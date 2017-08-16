# $NetBSD: Makefile,v 1.5 2017/08/16 20:45:46 wiz Exp $
#

DISTNAME=	august0.63b.src
PKGNAME=	august-0.63b
CATEGORIES=	www editors
#MASTER_SITES=	http://www.bostream.nu/johanb/august/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.bostream.nu/johanb/august/
COMMENT=	Simple Tk-based HTML editor

NO_BUILD=	yes
USE_LANGUAGES=	# none

USE_TOOLS+=		wish:run

INSTALLATION_DIRS=	bin share/doc/august

# needs Tcl/Tk version 8.0 or better
REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	/usr/bin/wish
REPLACE.wish.new=	${WISH}
REPLACE_FILES.wish=	august

# ImageMagick and Weblint is also recommended (but not necessary).
# August uses ImageMagick commands to determine width and
# height of images, and Weblint to check html syntax.

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/august ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/license.txt ${DESTDIR}${PREFIX}/share/doc/august/
	${INSTALL_MAN} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/august/
	${INSTALL_MAN} ${WRKSRC}/specchars.txt ${DESTDIR}${PREFIX}/share/doc/august/
	${INSTALL_MAN} ${WRKSRC}/keyname.tcl ${DESTDIR}${PREFIX}/share/doc/august/

.include "../../mk/bsd.pkg.mk"
