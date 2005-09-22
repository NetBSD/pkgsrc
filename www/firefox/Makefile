# $NetBSD: Makefile,v 1.21 2005/09/22 14:14:04 jlam Exp $

MOZILLA=	firefox
EXTRACT_SUFX=	.tar.bz2
COMMENT=	Lightweight gecko-based web browser

_MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES

# Some .pc files are filled in by the build process, so we can't fix the
# rpaths until this has happened.
#
PKGCONFIG_OVERRIDE_STAGE=	post-build
PKGCONFIG_OVERRIDE+=		build/unix/*.pc

.include "../../www/firefox/Makefile-firefox.common"
.include "../../mk/bsd.pkg.mk"
