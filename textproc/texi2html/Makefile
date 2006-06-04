# $NetBSD: Makefile,v 1.26 2006/06/04 16:26:55 joerg Exp $

DISTNAME=	texi2html-1.76
CATEGORIES=	textproc
MASTER_SITES=	http://savannah.nongnu.org/download/texi2html/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/texi2html/
COMMENT=	Texinfo-to-HTML direct translator

CONFLICTS=	teTeX-bin-1.*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
