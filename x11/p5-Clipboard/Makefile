# $NetBSD: Makefile,v 1.1.1.1 2009/01/08 15:46:49 wiz Exp $
#

DISTNAME=	Clipboard-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KI/KING/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Clipboard/
COMMENT=	Copy and paste with any OS

DEPENDS+=	p5-Spiffy-[0-9]*:../../devel/p5-Spiffy
DEPENDS+=	xclip-[0-9]*:../../x11/xclip

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Clipboard/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
