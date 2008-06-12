# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:57 joerg Exp $
#

DISTNAME=		X11-Protocol-0.56
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		x11 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=X11/}

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://search.cpan.org/dist/X11-Protocol/
COMMENT=		Interface to the X11 protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/X11/Protocol/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
