# $NetBSD: Makefile,v 1.16 2014/05/29 23:38:20 wiz Exp $
#

DISTNAME=		X11-Protocol-0.56
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		x11 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=X11/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/X11-Protocol/
COMMENT=		Interface to the X11 protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/X11/Protocol/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
