# $NetBSD: Makefile,v 1.1.1.1 2004/09/28 22:59:30 rh Exp $
.include "../firefox-bin-flash/Makefile.common"

COMMENT=		Flash Player plugin for firefox-gtk2-bin

DEPENDS+=		firefox-gtk2-bin>=0.10:../../www/firefox-gtk2-bin

MOZ_NAME=		firefox-gtk2-linux
PLIST_SRC=		${PKGDIR}/../firefox-bin-flash/PLIST
DISTINFO_FILE=		${PKGDIR}/../firefox-bin-flash/distinfo

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
