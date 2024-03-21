# $NetBSD: Makefile,v 1.2 2024/03/21 14:51:31 wiz Exp $
#
DISTNAME=		X11-Protocol-Other-31
PKGNAME=		p5-${DISTNAME:S/3/0.3/:}
CATEGORIES=		x11 perl5
MASTER_SITES=		https://cpan.metacpan.org/authors/id/K/KR/KRYDE/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/X11-Protocol
COMMENT=		Interface to the X11 protocol
LICENSE=		gnu-gpl-v3

DEPENDS+=		p5-X11-Protocol-[0-9]*:../../x11/p5-X11-Protocol
DEPENDS+=		p5-Encode-HanExtra-[0-9]*:../../textproc/p5-Encode-HanExtra

PERL5_PACKLIST=		auto/X11/Protocol/Other/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
