# $NetBSD: Makefile,v 1.27 2006/11/05 17:06:43 joerg Exp $

DISTNAME=	texi2html-1.76
CATEGORIES=	textproc
MASTER_SITES=	http://savannah.nongnu.org/download/texi2html/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/texi2html/
COMMENT=	Texinfo-to-HTML direct translator

CONFLICTS=	teTeX-bin-1.*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
