# $NetBSD: Makefile,v 1.19 2005/02/07 13:30:11 wiz Exp $
#

DISTNAME=		texi2html-1.76
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_LOCAL}
# The following only seems to work with a graphical browser
# https://texi2html.cvshome.org/files/documents/70/758/texi2html-1.76.tar.bz2
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		https://texi2html.cvshome.org/
COMMENT=		Texinfo-to-HTML direct translator

CONFLICTS=		teTeX-bin-1.0 teTeX-bin-1.0.[1234567]

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
INFO_FILES=		texi2html.info

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
