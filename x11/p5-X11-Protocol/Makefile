# $NetBSD: Makefile,v 1.25 2021/05/24 19:56:03 wiz Exp $
#

DISTNAME=		X11-Protocol-0.56
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		13
CATEGORIES=		x11 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=X11/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/X11-Protocol
COMMENT=		Interface to the X11 protocol

PERL5_PACKLIST=		auto/X11/Protocol/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
